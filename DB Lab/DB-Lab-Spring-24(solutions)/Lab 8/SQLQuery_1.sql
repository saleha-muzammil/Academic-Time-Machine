create database tmp
use tmp
go


create table Students
(RollNo varchar(7) primary key
,Name varchar(30)
,WarningCount int
,Department varchar(15)
)
GO
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'1', N'Ali', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'2', N'Bilal', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'3', N'Ayesha', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'4', N'Ahmed', 0, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'5', N'Sara', 0, N'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'6', N'Salman', 1, N'EE')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'7', N'Zainab', 2, N'CS')
INSERT [dbo].[Students] ([RollNo], [Name], [WarningCount], [Department]) VALUES (N'8', N'Danial', 1, N'CS')

go
create table Courses
(
CourseID int primary key,
CourseName varchar(40),
PrerequiteCourseID int,
CreditHours int
)
GO
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (10, N'Database Systems', 20, 3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (20, N'Data Structures', 30,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (30, N'Programing', NULL,3)
INSERT [dbo].[Courses] ([CourseID], [CourseName], [PrerequiteCourseID],CreditHours) VALUES (40, N'Basic Electronics', NULL,3)
go

go
Create table Instructors
(
InstructorID int Primary key,
Name varchar(30),
Department varchar(7) ,
)
GO
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (100, N'Ishaq Raza', N'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (200, N'Zareen Alamgir', N'CS')
INSERT [dbo].[Instructors] ([InstructorID], [Name], [Department]) VALUES (300, N'Saima Zafar', N'EE')
go
Create table Semester
(
Semester varchar(15) Primary key,
[Status] varchar(10),
)
GO
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Fall2016', N'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Spring2016', N'Complete')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Spring2017', N'InProgress')
INSERT [dbo].[Semester] ([Semester], [Status]) VALUES (N'Summer2016', N'Cancelled')
go
Create table Courses_Semester
(
InstructorID int Foreign key References Instructors(InstructorID),
CourseID int Foreign key References Courses(CourseID),
Semester varchar(15) Foreign key References Semester(Semester),
Section varchar(1) ,
AvailableSeats int,
Department varchar(2)
)
GO
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2017', N'D', 45, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2017', N'C', 0, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (100, 10, N'Spring2017', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, N'Spring2017', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (300, 40, N'Spring2016', N'A', 6, N'CS')
INSERT [dbo].[Courses_Semester] ([InstructorID], [CourseID], [Semester], [Section], [AvailableSeats], [Department]) VALUES (200, 10, N'Spring2016', N'A', 0, N'CS')

go



create table Registration
(
Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
CourseID int Foreign key References Courses(CourseID),
Section varchar(1),
GPA float
)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'1', 20, N'A', 3.3)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'2', 20, N'B', 4)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Spring2016', N'1', 30, N'A', 1.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Fall2016', N'6', 40, N'D',0.0)
INSERT [dbo].[Registration] ([Semester], [RollNumber], [CourseID], [Section],GPA) VALUES (N'Spring2017', N'6', 40, N'D',1)


go

Create table ChallanForm
(Semester varchar(15) Foreign key References Semester(Semester),
RollNumber  varchar(7) Foreign key References Students(RollNo),
TotalDues int,
[Status] varchar(10)
)
GO
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'1', 100000, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'2', 13333, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'3', 5000, N'Paid')
INSERT [dbo].[ChallanForm] ([Semester], [RollNumber], [TotalDues], [Status]) VALUES (N'Fall2016', N'4', 20000, N'Pending')


select * from Students
select * from Courses
select * from Instructors
select * from Registration
select * from Semester
select * from Courses_Semester
select * from ChallanForm


--Functionality 1
-- CREATE TRIGGER No_Delete
-- ON Students
-- INSTEAD OF DELETE
-- AS
-- BEGIN
-- PRINT '“You don’t have the permission to delete the student”'
-- END

-- delete from Students where Name like 'Ali'


--Functionality 2
-- CREATE TRIGGER No_Insert_Course
-- ON Courses
-- INSTEAD OF INSERT
-- AS
-- BEGIN
-- PRINT '“You don’t have the permission to Insert a new Course”'
-- END

-- insert into Courses
-- values
-- (50, 'COAL', NULL, 3)



--Functionality 3
-- CREATE TABLE Notify
-- (
-- NotificationID int primary key,
-- studentID varchar(7) Foreign key References Students(RollNo),
-- notificationString varchar(100)
-- )

-- Alter TRIGGER notifyRegistrationTrigger
-- ON Registration
-- INSTEAD OF INSERT
-- AS
--     Declare @sem varchar(15), @StudentRollNum varchar(7), @couID int, @sec varchar(1), @G_P_A FLOAT
--     SELECT @sem=semester, @StudentRollNum=RollNumber, @couID=CourseID, @sec=Section, @G_P_A=GPA FROM Inserted
--     Declare @seatsAvail int, @prereqPassed int --variables to test for insertion conditions
--     --checking for the seats ccondition
--     if (EXISTS(select * FROM Courses_Semester where courseID=@couID AND Semester=@sem AND Section=@sec AND AvailableSeats>=1))
--     BEGIN
--         SET @seatsAvail=1
--     END
--     ELSE
--     BEGIN
--         set @seatsAvail=0
--     END
--     --checking for the prerequisite condition
--     --find prereq of course
--     --if student passed that course with gpa >=2 then prereq passed
--     Declare @prereqID int 
--     select @prereqID=PrerequiteCourseID from Courses WHERE courseID=@couID
--     if (@prereqID is NULL)
--     BEGIN
--         set @prereqPassed=1 --set to 1 as there is no prereq so no need to check this condition any further
--     END
--     ELSE
--     BEGIN
--         if (EXISTS(select * from Registration where (RollNumber=@StudentRollNum AND CourseID=@prereqID AND gpa>=2.0)))
--         BEGIN
--             set @prereqPassed=1
--         END
--         ELSE
--         BEGIN
--             set @prereqPassed=0
--         END
--     END
--     IF (@seatsAvail=1 AND @prereqPassed=1)
--     BEGIN
--         insert into Registration
--         VALUES
--         (@sem, @StudentRollNum,@couID,@sec, @G_P_A)
--         print 'Registration Succesful'
--         --add into the notify table
--         Declare @notID int
--         select top 1 @notID=NotificationID from Notify order by NotificationID Desc
--         insert into Notify
--         VALUES
--         (@notID+1, @StudentRollNum, 'Student roll num ' + @StudentRollNum + ' has been registered')
--         print 'Table notify updated succesfully'
--     END
--     ELSE
--     BEGIN
--         print 'Cannot register due to the following:'
--         if (@seatsAvail=0)
--         BEGIN
--             print 'Seats finished'
--         END
--         if (@prereqPassed=0)
--         BEGIN
--             print 'prereq not passed'
--         END
--         --update notify table
--         Declare @notID1 int
--         select top 1 @notID1=NotificationID from Notify order by NotificationID Desc
--         insert into Notify
--         VALUES
--         (@notID+1, @StudentRollNum, 'Student roll num ' + @StudentRollNum + ' not registered')
--         print 'Table notify updated succesfully'
--     END

--tested for diffferent test cases to ensure working correctly
insert into registration
VALUES
('Spring2017', '2', 10, 'C', 0)


--Functionality 4

-- disable trigger notifyRegistrationTrigger on Registration
-- drop trigger notifyRegistrationTrigger

create TRIGGER notifyRegistrationTriggerWithFeeCheck
ON Registration
INSTEAD OF INSERT
AS
    Declare @sem varchar(15), @StudentRollNum varchar(7), @couID int, @sec varchar(1), @G_P_A FLOAT
    SELECT @sem=semester, @StudentRollNum=RollNumber, @couID=CourseID, @sec=Section, @G_P_A=GPA FROM Inserted
    Declare @seatsAvail int, @prereqPassed int, @feespaid int--variables to test for insertion conditions
    --checking for the seats ccondition
    if (EXISTS(select * FROM Courses_Semester where courseID=@couID AND Semester=@sem AND Section=@sec AND AvailableSeats>=1))
    BEGIN
        SET @seatsAvail=1
    END
    ELSE
    BEGIN
        set @seatsAvail=0
    END
    --checking for the prerequisite condition
    --find prereq of course
    --if student passed that course with gpa >=2 then prereq passed
    Declare @prereqID int 
    select @prereqID=PrerequiteCourseID from Courses WHERE courseID=@couID
    if (@prereqID is NULL)
    BEGIN
        set @prereqPassed=1 --set to 1 as there is no prereq so no need to check this condition any further
    END
    ELSE
    BEGIN
        if (EXISTS(select * from Registration where (RollNumber=@StudentRollNum AND CourseID=@prereqID AND gpa>=2.0)))
        BEGIN
            set @prereqPassed=1
        END
        ELSE
        BEGIN
            set @prereqPassed=0
        END
    END
    --checking for fee condition
    DECLARE @feeAmount INT
    if (EXISTS(select * FROM ChallanForm where TotalDues<=20000 AND RollNumber=@StudentRollNum AND [Status]='Pending'))
    BEGIN
        set @feesPaid=1
    END
    ELSE
    BEGIN
        set @feesPaid=0
    END
    IF (@seatsAvail=1 AND @prereqPassed=1 AND @feespaid=1)
    BEGIN
        insert into Registration
        VALUES
        (@sem, @StudentRollNum,@couID,@sec, @G_P_A)
        print 'Registration Succesful'
        --add into the notify table
        Declare @notID int
        select top 1 @notID=NotificationID from Notify order by NotificationID Desc
        insert into Notify
        VALUES
        (@notID+1, @StudentRollNum, 'Student roll num ' + @StudentRollNum + ' has been registered')
        print 'Table notify updated succesfully'
    END
    ELSE
    BEGIN
        print 'Cannot register due to the following:'
        if (@seatsAvail=0)
        BEGIN
            print 'Seats finished'
        END
        if (@prereqPassed=0)
        BEGIN
            print 'prereq not passed'
        END
        if (@feespaid=0)
        BEGIN
            print 'fees not paid'
        END
        --update notify table
        Declare @notID1 int
        select top 1 @notID1=NotificationID from Notify order by NotificationID Desc
        insert into Notify
        VALUES
        (@notID+1, @StudentRollNum, 'Student roll num ' + @StudentRollNum + ' not registered')
        print 'Table notify updated succesfully'
    END


insert into Registration
VALUES
('Fall2016', '3', 40, 'B', 3.5)


--Functionality 5
-- Alter TRIGGER Delete_Course_Sem
-- ON Courses_Semester
-- INSTEAD OF Delete
-- AS
--     Declare @instID int, @couID int, @sem varchar(15), @numSeats INT, @sect VARCHAR(1)
--     select @instID=instructorID, @couID=courseID, @sem=Semester, @numSeats=AvailableSeats, @sect=Section
--     from deleted
--     IF (@numSeats>=10)
--         BEGIN
--             delete from Courses_Semester
--             where InstructorID=@instID AND CourseID=@couID AND Semester=@sem AND Section=@sect
--             print 'Succesfully Deleted'
--         END
--     ELSE
--         BEGIN
--             print 'Not Possible'
--         END

-- insert into Courses_Semester
-- VALUES
-- (200, 40, 'Spring2017', 'A', 100, 'CS')

-- delete from Courses_Semester
-- where InstructorID=200 AND CourseID=40 AND Semester='Spring2017' AND Section='A'


--The testing below revealed that if we create a trigger and one value in the table then it will be in inserted. Similiarly,if we insert another row in the next instance then it will be the only one in the inserted table. Hence, we can apply all sorts of checks to meet our requirement by selecting the row from the inserted table. Similiar case for the deleted table
--Another thing to keep in mind is that if we use 'instead of' keyword with the insert/delete the even if that value is not inserted/deleted due to the keyword it will be present in the respective inserted/deleted tables
--this can we used to prevent unwanted deletion/insertions into our tables


-- create trigger PrintInsert
-- on Notify
-- after insert
-- as
-- begin
-- select * from inserted
-- end

-- DISABLE trigger PrintInsert on Notify

-- insert into notify
-- values
-- (1, '1', 'Student Enrolled')

-- insert into notify
-- values
-- (2, '6', 'Student rollNum 6 Enrolled')

-- insert into notify
-- values
-- (3, '4', 'Student rollNum 4 Enrolled')

-- insert into notify
-- values
-- (4, '7', 'Student rollNum 7 Enrolled')

-- create trigger deleteNotifyVal
-- on Notify
-- instead of DELETE
-- as
-- begin
--     select * from deleted
-- end

-- disable trigger deleteNotifyval on Notify

-- delete from Notify where NotificationID=4




--Functionality 6
-- create trigger instructor_DML_Stop
-- ON Instructors
-- INSTEAD OF DELETE, INSERT, UPDATE
-- AS
-- BEGIN
--     print 'Instructor table modification is restricted'
-- END

-- insert into Instructors
-- values 
-- (400, 'Saira Karim', 'CS')


-- --this will disable dropping for all the tables in the database
-- create trigger instructor_Drop_Stop
-- on DATABASE
-- FOR DROP_TABLE
-- AS
-- BEGIN
--     print 'Instructor table modification is restricted'
-- END

-- drop table Instructors

-- --for a specific databse
-- create TRIGGER prevent_specific_table_drop
-- on database
-- FOR DDL_TABLE_EVENTS
-- AS
-- DECLARE @EventData xml
-- SET @EventData=EVENTDATA()
-- IF (@EventData.value('(/EVENT_INSTANCE/ObjectType)[1]', 'varchar(50)')='TABLE'
--     AND @EventData.value('(/EVENT_INSTANCE/ObjectName)[1]', 'varchar(50)') ='Instructors')
-- BEGIN
--     print 'Drop Instructor not allowed'
-- END
-- ELSE
-- BEGIN
--     --command to drop a database if not matches the above
-- END