--A Part

create table Students(
studentid int Primary Key,
name varchar(30),
departmentid int,
batch int
)

create table Department(
departmentid int Primary Key,
name varchar(30)
)

create table Courses(
courseid int  Primary Key,
name varchar(30),
creditHrs int
)

create table StudentCourse(
courseid int,
studentid int,
Primary Key(courseid,studentid),
)







--B Part

--1,2

alter table Students 
add Foreign Key (departmentid) 
references Department(departmentid) 
on Delete no Action on Update Cascade


--3,4

alter table StudentCourse 
add Foreign Key (courseid) 
references Courses(courseid) 
on Delete Cascade on Update Cascade








--C Part

--5

alter table Department alter Column name varchar(30) Not Null


--4

alter table Courses add constraint credit_limit Check( creditHrs=3 Or creditHrs=4)


--3

alter table Students add Constraint batch_limit Check(batch<= DatePart(year,GetDate()))


--2

alter table Department add constraint uni_Name Unique (name) 


--1

alter table Students add dateOfBirth date



