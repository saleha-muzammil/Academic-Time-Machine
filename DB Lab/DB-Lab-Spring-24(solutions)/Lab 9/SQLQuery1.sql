create database trigger_lab_9
use trigger_lab_9

--Student(roll_no, name, dept_id, batch)
--Course(course_id, name, credit_hrs, dept_id)
--Section (section_id, course_id, capacity)
--Enrolled(student_roll_no, section_id)
--Faculty(faculty_id, name, dept_id)
--Department(dept_id, name)


--Creating the table structures
create table DEPARTMENT(
	dept_id INT PRIMARY KEY IDENTITY(1,1),  --using IDENTITY keyword means that we don't have to insert ids into the table auto incremented and added
	name nvarchar(60)
)

create table STUDENT(
	roll_no INT PRIMARY KEY IDENTITY(1,1),
	name nvarchar(60),
	dept_id int foreign key references DEPARTMENT(dept_id),
	batch nvarchar(60)
)

create table COURSE(
	course_id INT PRIMARY KEY IDENTITY(1,1),
	name nvarchar(60),
	credit_hrs int check(credit_hrs>=0 AND credit_hrs<=3), --max 3 creds
	dept_id int foreign key references DEPARTMENT(dept_id)
)

create table SECTION(
	section_id INT PRIMARY KEY IDENTITY(1,1),
	course_id INT FOREIGN KEY REFERENCES COURSE(course_id),
	capacity INT
)

create table ENROLLED(
	roll_no INT FOREIGN KEY REFERENCES STUDENT(roll_no),
	section_id INT FOREIGN KEY REFERENCES SECTION(section_id)
)

create table FACULTY(
	faculty_id INT PRIMARY KEY IDENTITY(1,1),
	name nvarchar(60),
	dept_id int foreign key references DEPARTMENT(dept_id)
)

--Populating the tables
insert into STUDENT
values
('Hassaan', 1, 'Fall 22'),
('Mujtaba', 2, 'Spring 22'),
('Burhan', 3, 'Fall 23'),
('Asif', 3, 'Fall 22'),
('Rahim', 2, 'Spring 23')


insert into COURSE
values
('PF', 3, 1),
('MM', 2, 3),
('DS', 3, 1),
('PHY', 2, 2),
('CPS', 2, 5),
('ISL', 1, 5)


insert into DEPARTMENT
values
('CS'),
('EE'),
('BM'),
('ROBO'),
('HUMANITIES')


insert into SECTION
values
(1, 20),
(2, 30),
(3, 40),
(3, 50),
(4, 20),
(5, 35),
(6, 25)


insert into ENROLLED
values
(1, 3),
(1, 4),
(1, 6),
(2, 3),
(3, 2),
(4, 5),
(5, 6)


insert into FACULTY
values
('Saira Karim', 1),
('Namra Absar', 1),
('Ishaq Raza', 2),
('Saquib Bhatti', 3),
('Ali Kashif', 4),
('Atif Ali', 5)


--printing
select* from STUDENT
select* from COURSE
select* from DEPARTMENT
select* from SECTION
select* from ENROLLED
select* from FACULTY






--Q1
create table AUDITING(
	audit_id INT PRIMARY KEY IDENTITY(1,1),
	Last_Change_On DATE
)

--trigger is associated with a specific table so can't make a single trigger for all the tables
--student table
create trigger AddAuditRecord
on STUDENT
after insert, update, delete
AS
BEGIN
	insert into AUDITING
	values
	(GETDATE()) --adds the current date of the change
END

--department table
create trigger AddAuditRecord_Dept
on DEPARTMENT
after insert, update, delete
AS
BEGIN
	insert into AUDITING
	values
	(GETDATE()) --adds the current date of the change
END

--faculty table
create trigger AddAuditRecord_Faculty
on FACULTY
after insert, update, delete
AS
BEGIN
	insert into AUDITING
	values
	(GETDATE()) --adds the current date of the change
END








--Q2
alter table AUDITING
add description nvarchar(60)

--student table
alter trigger AddAuditRecord
on STUDENT
after insert, update, delete
AS
BEGIN
	if (EXISTS(select * from inserted) AND EXISTS(select * from deleted))
	begin
		--update operation took place
		insert into AUDITING
		values
		(GETDATE(), 'Updated STUDENT table') --adds the current date of the change
	end
	else
	begin
		if (EXISTS(select * from inserted))
		begin
			--insert took place
			 insert into AUDITING
			values
			(GETDATE(), 'Inserted into STUDENT table') --adds the current date of the change
		end
		else
		begin
			if (EXISTS(select * from deleted))
			begin
			--insert took place
			insert into AUDITING
			values
			(GETDATE(), 'Deleted from STUDENT table') --adds the current date of the change
		end
		end
	end
END

--DEPARTMENT table
alter trigger AddAuditRecord_Dept
on DEPARTMENT
after insert, update, delete
AS
BEGIN
	if (EXISTS(select * from inserted) AND EXISTS(select * from deleted))
	begin
		--update operation took place
		insert into AUDITING
		values
		(GETDATE(), 'Updated DEPARTMENT table') --adds the current date of the change
	end
	else
	begin
		if (EXISTS(select * from inserted))
		begin
			--insert took place
			 insert into AUDITING
			values
			(GETDATE(), 'Inserted into DEPARTMENT table') --adds the current date of the change
		end
		else
		begin
			if (EXISTS(select * from deleted))
			begin
			--insert took place
			insert into AUDITING
			values
			(GETDATE(), 'Deleted from DEPARTMENT table') --adds the current date of the change
		end
		end
	end
END


--faculty table
alter trigger AddAuditRecord_Faculty
on FACULTY
after insert, update, delete
AS
BEGIN
	if (EXISTS(select * from inserted) AND EXISTS(select * from deleted))
	begin
		--update operation took place
		insert into AUDITING
		values
		(GETDATE(), 'Updated FACULTY table') --adds the current date of the change
	end
	else
	begin
		if (EXISTS(select * from inserted))
		begin
			--insert took place
			 insert into AUDITING
			values
			(GETDATE(), 'Inserted into FACULTY table') --adds the current date of the change
		end
		else
		begin
			if (EXISTS(select * from deleted))
			begin
			--insert took place
			insert into AUDITING
			values
			(GETDATE(), 'Deleted from FACULTY table') --adds the current date of the change
		end
		end
	end
END


insert into STUDENT
values
('Ibrahim', 1, 'Fall 22')

insert into FACULTY
values
('Akhlaq Ahmed', 5)

delete from FACULTY
where faculty_id=8

update FACULTY
set name='Asim Afzal'
where faculty_id=9





--Q3
create view displaySectionStatus
as
(
select s.section_id, course_id, totalNumber, capacity from
(select section_id, COUNT(*) as totalNumber from ENROLLED
group by section_id) as tmp inner join SECTION as s
on tmp.section_id=s.section_id
)

select * from displaySectionStatus


--Q4





--Q5


--Q6