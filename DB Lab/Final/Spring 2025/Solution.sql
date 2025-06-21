use dbcoord

------------------ Question 1
select '23L-1234', 'BCS-4X';
go
select RAND(), RAND(), RAND();
go

--- Error as String_AGG required two arguments

print 'Hello World'
go

DECLARE @n INT = 34;
DECLARE @i INT = 0;

WHILE @i < @n
BEGIN
    SELECT @i AS i;
    SET @i = @i + 1;
END
go
--- Scope identity gets the id of the last inserted id in the scope
go


------------------- Question 2
create table Topic (
id int identity primary key,
name varchar(200)
)
go

INSERT INTO Topic(name)
SELECT DISTINCT q.Topic AS name
FROM Question q;
go

ALTER TABLE Question
ADD topic_id INT,
    CONSTRAINT FK_Topic_Parent
    FOREIGN KEY (topic_id) REFERENCES Question(id);
go

EXEC sp_rename 'Question.topic_id', 'corresponding_topic_id', 'COLUMN';
go 

UPDATE Question
SET corresponding_topic_id = T.id
FROM Question Q
JOIN Topic T ON Q.topic = T.name;

go
ALTER TABLE Question
DROP COLUMN topic;
go

------------------ Question 3
-- a)
SELECT 
    ls.day,
    ls.start_time,
    ls.end_time,
    STRING_AGG(s.name, ', ') AS section_names,
    STRING_AGG(i.name, ', ') AS instructors
FROM Course c
JOIN CourseSection cs        ON c.id = cs.course_id
JOIN Section s               ON cs.section_id = s.id
JOIN SectionLabSession sls   ON s.id = sls.section_id
JOIN LabSession ls           ON ls.id = sls.lab_session_id
JOIN SectionInstructor si    ON s.id = si.section_id
JOIN Instructor i            ON i.id = si.instructor_id
GROUP BY 
    ls.id, ls.day, ls.start_time, ls.end_time;
GO

-- b)
Create Function fn_InstructorLabWorkLoad(@id int)
returns int
as
begin
	declare @res int;
	
	select @res= SUM(DATEDIFF(HOUR,start_time,end_time))
	from SectionInstructor
	join SectionLabSession on SectionLabSession.section_id=SectionInstructor.section_id
	join LabSession on LabSession.id=SectionLabSession.lab_session_id
	where instructor_id=@id
	group by instructor_id

	return @res
end


alter table Instructor
add weeklyLoad as dbo.fn_InstructorLabWorkLoad(id);

-- c)
create trigger PreventMultipleAssignments
on SectionInstructor
instead of insert
as
begin
	begin transaction
	begin try
	if exists(Select instructor_id from SectionInstructor where section_id= (Select section_id from inserted) )
	begin
		print 'An intructor is already assigned. Update to change him.'
		rollback transaction
	end
	else
	begin
		insert into SectionInstructor(section_id,instructor_id)
		Values((Select section_id from inserted),(Select instructor_id from inserted))
	end
	commit transaction;
	end try
	begin catch
	PRINT 'An instructor is already assigned to this section';
	end catch
	
end
--- d)
create trigger AutoGenerate
on QuestionSubmission
after insert
as
begin
	begin transaction
	begin try
		declare @cID int;
		select @cID= course_id from inserted
		if ( exists( Select * from QuestionSubmission where course_id =@cID group by course_id having count(*)>3)
		and GETDATE()<'2025-06-05')
		begin
			if not exists( Select exam_id from FinalExam where course_id=@cID)
			begin
				declare @eID int;
				Select @eID=  max(exam_id)+1  from FinalExam
				
				insert into FinalExam(exam_id,course_id)
				values (@eID,@cID)
		
				declare @totalW int =0;
				declare @qNo int;

				declare @high int;
				while(@totalW < 40)
				begin
					with cte as
					(select course_id,question_id, ROW_NUMBER()OVER(order by course_id,question_id asc) AS ROWn
					from QuestionSubmission
					WHERE course_id=@cID
					group by course_id,question_id)
					select @high =max (ROWn) from cte
					set @qNo= FLOOR(Rand(@high)+1);
					
					declare @n int;
					with cte as
					(select course_id,question_id, ROW_NUMBER()OVER(order by course_id,question_id asc) AS ROWn
					from QuestionSubmission
					WHERE course_id=@cID
					group by course_id,question_id)
					select @n= question_id from cte where ROWn=@qNo;

					if not exists (Select * from FinalExamQuestions where question_id=@n and exam_id=@eID)
						begin
						insert into FinalExamQuestions
						values (@eID,@n)
						set @totalW= @totalW + (Select weightage from Question where id=@n)
						end

					declare @c int;

					with cte as
					(select course_id,question_id, ROW_NUMBER()OVER(order by course_id,question_id asc) AS ROWn
					from QuestionSubmission
					WHERE course_id=@cID
					group by course_id,question_id)
					Select @c= count(ROWn) from cte

					if((Select count(*) from FinalExamQuestions where exam_id=@eID)=@c)
					break;


				end

			end
		end
	commit transaction;
	end try
	begin catch
	PRINT 'There was an issue with automatic Generation of final Exam Qs';
	end catch
	
end

--(e)
Select fq.exam_id,q.id as question_id,q.question_text,q.difficulty,q.suggested_marks,q.weightage,q.restrictions,q.topic,SUM(q.weightage)/q.weightage as totalWeightagePerExam
from Question	q	
join FinalExamQuestions fq on fq.question_id=q.id
group by exam_id,q.id,q.question_text,q.difficulty,q.suggested_marks,q.weightage,q.restrictions,q.topic	



