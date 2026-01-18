/*TASK 1*/

-- create table Student
-- (
--     rollNum char(7),
--     name varchar(20),
--     gender char(1),
--     phone char(11)
-- )

-- create table Attendance
-- (
--     rollNum char(7),
--     dateMarked date,
--     status char(1),
--     classVenue int
-- )

-- create table ClassVenue
-- (
--     ID int,
--     building varchar(20),
--     roomNum int,
--     teacher varchar(30)
-- )

-- create table Teacher
-- (
--     tName varchar(30),
--     designation varchar(30),
--     department varchar(30)
-- )

-- insert into Student
-- VALUES
-- ('22L6947', 'M Hassaan Raza', 'M', '03001119141'),
-- ('22L6464', 'Ali Asif', 'M', '03302299202' ),
-- ('22L6124', 'Rafia Ahmed', 'F', '03453243567')

-- select * from STUDENT

--note that the date is of format yyyy-mm-dd

-- insert into Attendance
-- VALUES
-- ('22L6947', '2016-02-22', 'P', 2),
-- ('22L6464', '2016-02-23', 'A', 1 ),
-- ('22L6124', '2016-04-03', 'P', 2)

-- select * from attendance

-- insert into ClassVenue
-- VALUES
-- (1, 'CS', 2, 'Sarim Baig'),
-- (2, 'Civil', 7, 'Bismillah Jan')

-- select * from ClassVenue


-- insert into Teacher
-- VALUES
-- ('Sarim Baig', 'Assistant Prof.', 'Computer Science'),
-- ('Bsimillah Jan', 'Lecturer', 'Civil Eng.'),
-- ('Kashif Zafar', 'Professor', 'Electrical Eng.')

-- select * from Teacher


/*TASK 2*/

-- alter table Student alter column rollNum char(7) NOT NULL
-- alter table Student add constraint PK_Student primary key (rollNum) 

-- alter table classVenue alter column ID int NOT NULL
-- alter table classVenue add constraint CV_Student primary key (ID) 

-- alter table Teacher alter column tName varchar(30) NOT NULL
-- alter table Teacher add constraint PK_Teacher primary key (tName) 

/*Note that this combination of primary keys is chosen as there can only be one entry of a rollNum on a specific date*/
-- alter table Attendance alter column rollNum char(7) NOT NULL
-- alter table Attendance alter column dateMarked date NOT NULL
-- alter table Attendance add constraint PK_Attendance primary key (rollNum, dateMarked) 

/*TASK 3*/
-- we will be using the cascade option to update/delete the foreign key upon respective changes in the primary key

-- alter table Attendance add constraint FK_Attendance foreign key (rollNum) references Student(rollNum) on delete cascade on update CASCADE
-- alter table Attendance add constraint FK_Attendance_CV foreign key (classVenue) references ClassVenue(ID) on delete cascade on update CASCADE

-- select * from ClassVenue
-- select * from Teacher

-- update Teacher set tName='Bismillah Jan' where tName='Bsimillah Jan'

-- alter table ClassVenue add constraint FK_CV_Teacher foreign key (teacher) references Teacher(tName) on delete cascade on update CASCADE



/*TASK 4*/

-- alter table Student drop column phone
-- alter table Student add warningCount INT


/*TASK 5*/
-- insert into Student
-- VALUES
-- ('22L2334', 'Fozan Shahid', 'M', 3.2)

-- select * from Student

-- insert into ClassVenue
-- VALUES
-- (3, 'CS', 5, 'Ali')
-- inavlid query above as the the teacher column is a foreign key that refers to the primary key in the Teacher table. Hence, referential integrity is ensured as the name Ali cannot be addded into the CV table as no entry present in the Teacher table

-- update Teacher
-- set tName='Dr. Kashif Zafar'
-- where tName='Kashif Zafar'

-- select * from teacher

-- delete from STUDENT
-- where rollNum='22L2334'

-- select * from Student

-- delete from STUDENT
-- where rollNum='22L6123'
-- no row deleted as no column with this specific entry

-- alter table Teacher add constraint Uniq_Teacher unique(tName)

-- alter table Student add constraint check_gender_student check (gender ='M' OR gender='F')
-- alter table Attendance add constraint check_Attendance_status check (status='A' OR status='P')