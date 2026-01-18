-- /****** Object:  Table [dbo].[Students]    Script Date: 02/08/2017 16:06:49 ******/
-- SET ANSI_NULLS ON
-- GO
-- SET QUOTED_IDENTIFIER ON
-- GO
-- SET ANSI_PADDING ON
-- GO
-- CREATE TABLE [dbo].[Students](
-- 	[StudentID] [int] NOT NULL,
-- 	[StudentName] [varchar](30) NULL,
-- 	[StudentBatch] [int] NULL,
-- 	[CGPA] [float] NULL,
-- PRIMARY KEY CLUSTERED 
-- (
-- 	[StudentID] ASC
-- )WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
-- ) ON [PRIMARY]
-- GO
-- SET ANSI_PADDING OFF
-- GO
-- INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (1, N'Ali', 2013, 2.625)
-- INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (2, N'Aysha', 2013, 4)
-- INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (3, N'Ahmed', 2013, 2.2)
-- INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (4, N'Bilal', 2012, 2.5)
-- INSERT [dbo].[Students] ([StudentID], [StudentName], [StudentBatch], [CGPA]) VALUES (5, N'Zafar', 2012, 3.5)
-- /****** Object:  Table [dbo].[Instructors]    Script Date: 02/08/2017 16:06:49 ******/
-- SET ANSI_NULLS ON
-- GO
-- SET QUOTED_IDENTIFIER ON
-- GO
-- SET ANSI_PADDING ON
-- GO
-- CREATE TABLE [dbo].[Instructors](
-- 	[InstructorID] [int] NOT NULL,
-- 	[InstructorsName] [varchar](30) NULL,
-- PRIMARY KEY CLUSTERED 
-- (
-- 	[InstructorID] ASC
-- )WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
-- ) ON [PRIMARY]
-- GO
-- SET ANSI_PADDING OFF
-- GO
-- INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (1, N'Zafar')
-- INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (2, N'Sadia')
-- INSERT [dbo].[Instructors] ([InstructorID], [InstructorsName]) VALUES (3, N'Saima')
-- /****** Object:  Table [dbo].[Courses]    Script Date: 02/08/2017 16:06:49 ******/
-- SET ANSI_NULLS ON
-- GO
-- SET QUOTED_IDENTIFIER ON
-- GO
-- SET ANSI_PADDING ON
-- GO
-- CREATE TABLE [dbo].[Courses](
-- 	[CourseID] [int] NOT NULL,
-- 	[CourseName] [varchar](30) NULL,
-- 	[CourseCreditHours] [int] NULL,
-- 	[InstructorID] [int] NULL,
-- PRIMARY KEY CLUSTERED 
-- (
-- 	[CourseID] ASC
-- )WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
-- ) ON [PRIMARY]
-- GO
-- SET ANSI_PADDING OFF
-- GO
-- INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (1, N'Computer Programming', 3, 1)
-- INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (2, N'Computer Organization', 3, 2)
-- INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (3, N'Computer Programming Lab', 1, NULL)
-- INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (4, N'Database', 3, 2)
-- INSERT [dbo].[Courses] ([CourseID], [CourseName], [CourseCreditHours], [InstructorID]) VALUES (5, N'Database  Lab', 1, 1)
-- /****** Object:  Table [dbo].[Registration]    Script Date: 02/08/2017 16:06:49 ******/
-- SET ANSI_NULLS ON
-- GO
-- SET QUOTED_IDENTIFIER ON
-- GO
-- CREATE TABLE [dbo].[Registration](
-- 	[StudentID] [int] NOT NULL,
-- 	[CourseID] [int] NOT NULL,
-- 	[GPA] [float] NULL,
-- PRIMARY KEY CLUSTERED 
-- (
-- 	[StudentID] ASC,
-- 	[CourseID] ASC
-- )WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
-- ) ON [PRIMARY]
-- GO
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 1, 3)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 3, 3)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 4, 2)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (1, 5, 3)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 1, 2.5)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 2, 0)
-- INSERT [dbo].[Registration] ([StudentID], [CourseID], [GPA]) VALUES (2, 4, 3)
-- /****** Object:  ForeignKey [FK__Courses__Instruc__08EA5793]    Script Date: 02/08/2017 16:06:49 ******/
-- ALTER TABLE [dbo].[Courses]  WITH CHECK ADD FOREIGN KEY([InstructorID])
-- REFERENCES [dbo].[Instructors] ([InstructorID])
-- GO
-- /****** Object:  ForeignKey [FK__Registrat__Cours__0EA330E9]    Script Date: 02/08/2017 16:06:49 ******/
-- ALTER TABLE [dbo].[Registration]  WITH CHECK ADD FOREIGN KEY([CourseID])
-- REFERENCES [dbo].[Courses] ([CourseID])
-- GO
-- /****** Object:  ForeignKey [FK__Registrat__Stude__0DAF0CB0]    Script Date: 02/08/2017 16:06:49 ******/
-- ALTER TABLE [dbo].[Registration]  WITH CHECK ADD FOREIGN KEY([StudentID])
-- REFERENCES [dbo].[Students] ([StudentID])
-- GO

-- SELECT * FROM Courses
-- SELECT * FROM Instructors
-- SELECT * FROM Registration
-- SELECT * FROM Students



--CREATING AND PRINTING VIEWS
CREATE VIEW [3_GPA_Students]
AS 
(SELECT s.StudentName
FROM Students s inner join Registration R on s.studentID=R.studentID)

CREATE VIEW StudentCGPA
AS
(
    SELECT s.StudentName, s.studentID, SUM(c.CourseCreditHours*R.GPA)/SUM(c.CourseCreditHours) AS CGPA
    FROM Students s INNER JOIN Registration R
    ON s.studentID=R.studentID
    INNER JOIN Courses c ON c.CourseID=R.CourseID
    GROUP BY s.studentName, s.StudentID
)

SELECT * FROM [3_GPA_Students]
SELECT * FROM StudentCGPA
--we can also use a view like an ordianry SQL table/relation
SELECT *
FROM StudentCGPA
WHERE (CGPA>2)



--ALTERING A VIEW
--allows us to update the selct query of a given view
ALTER VIEW [3_GPA_Students]
AS
(
    SELECT s.StudentName, c.CourseName
    FROM Students s INNER JOIN Registration R 
    ON s.studentID=R.studentID
    INNER JOIN Courses c ON c.CourseID=R.CourseID
    WHERE R.GPA=3
)

SELECT * FROM [3_GPA_Students]

--Insert, update and delete data through the view
--these modification operations on views would only work if the change is feasible and does not violate any constraint

CREATE VIEW Students2013Batch
AS 
(
    SELECT *
    FROM Students
    WHERE StudentBatch=2013
)

--this row gets inserted into the base table as there are no aggregate functions or joins used, moreover columns of only one base table are being modified
INSERT into Students2013Batch
VALUES
(12, 'xyz', 2014, 3)

--the new row will not be displayed in the VIEW as it does not meet the condition of year=2013 but it is inserted into the underlying base table
SELECT * FROM Students
select * FROM Students2013Batch

--WITH CHECK OPTION -> this prevents the data manipulation of rows that are not visible through the view like the example above where inserted row is not visible in the visible in the view but only in the base table

CREATE VIEW Srudents2014Batch
AS
(
    SELECT *
    FROM Students
    where studentBatch=2014
)
WITH CHECK OPTION

--this row will be visible through the view therefore it will be inserted
insert into Srudents2014Batch
VALUES
(13, 'ABC', 2014, 3)

SELECT * FROM Srudents2014Batch
SELECT * FROM Students

--this row will not be visible through the view therefore it will not be inserted due to the 'WITH CHECK OPTION' enabled
insert into Srudents2014Batch
VALUES
(15, 'LMN', 2013, 3)


--STORED PROCEDURE: a group of SQL statements that can be reused over and over again
--VARIABLES
--declaring
DECLARE @name VARCHAR(30)
DECLARE @fName VARCHAR(30), @lName VARCHAR(30)
--setting the values directly
SET @name='Ali Ahmed'
SELECT @fName='Ali', @lName='Ahmed'
--setting the values using SQL Queries
--if more than one value is returned then the first value will be assigned
SELECT @name=studentName FROM Students WHERE studentBatch=2014
--retrieving variable values
SELECT @name as [Name], @fName as firstName, @lName as lastName
--operations like addition, subtraction and concatenation can also be performed on the variables
SELECT @fName + ', ' + @lName AS fullName

--creating a stored procedure without input and output parameters
CREATE PROCEDURE [studentBatch2013Func]
AS
BEGIN
    SELECT * FROM Students WHERE studentBatch=2013 
END

EXECUTE [studentBatch2013Func]

--creating a procedure with input parametes
CREATE PROCEDURE [studentsOfBatch]
@batch INT
AS 
BEGIN
    SELECT * FROM Students WHERE studentBatch=@batch
END

DECLARE @myBatch int=2014
EXECUTE [studentsOfBatch]
@batch=@myBatch


--creating a procedure with output varaibles
CREATE PROCEDURE [highestGPAOneVal]
@highestGPA float OUTPUT
AS
BEGIN
    SELECT top 1 @highestGPA=CGPA FROM Students ORDER BY CGPA DESC
END

DECLARE @gpa FLOAT
EXECUTE [highestGPAOneVal]
@highestGPA=@gpa OUTPUT
SELECT @gpa as [maxGPA]


--using if else conditions
CREATE PROCEDURE [getTeachers]
@tName VARCHAR(30),
@flag int OUTPUT
AS 
BEGIN
    if EXISTS(select * from Instructors where InstructorsName=@tName)
    BEGIN  
        set @flag=1
        select * FROM Instructors WHERE InstructorsName=@tName
    END
    ELSE
    BEGIN
        set @flag=0
    END
END

DECLARE @name varchar(30) = 'Zafar'
DECLARE @outFlag int 
EXECUTE [getTeachers]
@tName=@name,
@flag=@outFlag OUTPUT
SELECT @outFlag as [Flag Value]



CREATE PROCEDURE [GetStudents]
@letter VARCHAR(30)
AS 
BEGIN
    if LOWER(@letter) like '[a-z]'
    BEGIN
        SELECT * from Students WHERE StudentName LIKE @letter+'%'
    END
    ELSE
    BEGIN
    PRINT 'Invalid letter, only a-z allowed'
    END
END

EXECUTE [GetStudents]
@letter='1'