Create Table Users
(
	userId nvarchar(50) NOT NULL,
	[password] nvarchar(50),
	dob date,
	joinDate date,
)



Create Table Followers
(
	followee nvarchar(50) NOT NULL,
	follower nvarchar(50) NOT NULL
)

Create Table QuestionCategories
(
   category varchar(40) NOT NULL
)



Create Table Questions
(
	questionId bigint NOT NULL,
	userId nvarchar(50) NOT NULL,
	[date] date,
	category varchar(40) NOT NULL,
    question nvarchar(200)
)


Create Table Answers
(
   questionId bigint NOT NULL,
   userId nvarchar(50) NOT NULL,
   [date] date,
   answer varchar(500)
)

--primary key and foreign key constraints
alter table Users add constraint PK_USERS primary key (userId)
alter table Followers add constraint PK_FOLLOWERS primary key (followee, follower)
alter table QuestionCategories add constraint PK_QuestionCategories primary key (category)
alter table Questions add constraint PK_QUESTIONS primary key (questionId)
alter table Answers add constraint PK_ANSWERS primary key (questionId, userId)

alter table Followers add constraint FK_FOLLOWERS_FOLLOWEE foreign key (followee) references Users (userId)
alter table Followers add constraint FK_FOLLOWERS_FOLLOWER foreign key (follower) references Users (userId)

alter table Questions add constraint FK_QUESTIONS_USERID foreign key (userId) references Users (userId)
alter table Questions add constraint FK_QUESTIONS_CATEGORY foreign key (category) references QuestionCategories (category)

alter table Answers add constraint FK_ANSWERS_QUESTIONID foreign key (questionId) references Questions (questionId)
alter table Answers add constraint FK_ANSWERS_USERID foreign key (userId) references Users (userId)


--data
Insert into Users values ('peter', '123', '1992-11-11', '2010-04-05')
Insert into Users values ('john', '12z3', '1995-11-30', '2009-10-10')
Insert into Users values ('ali', '786q1', '1990-12-25', '2008-12-27')
Insert into Users values ('umer', '1qwe52', '1992-12-25', '2007-05-23')
Insert into Users values ('Junaid', '455errtw', '1989-11-15', '2010-12-12')

Insert into Followers values ('ali', 'peter')
Insert into Followers values ('peter', 'ali')
Insert into Followers values ('john', 'peter')
Insert into Followers values ('John', 'Junaid')
Insert into Followers values ('junaid', 'John')


Insert into QuestionCategories values ('International Relations')
Insert into QuestionCategories values ('Programing')
Insert into QuestionCategories values ('Supernatural')
Insert into QuestionCategories values ('Medical')



Insert into Questions values (1, 'peter', '2016-05-05', 'Medical', 'Will neurosurgeons be able to transplant head in the future?')
Insert into Questions values (2, 'ali', '2017-01-31', 'Programing', 'Which language should I start from first: C++ or Java?')
Insert into Questions values (3, 'peter', '2017-08-14', 'supernatural', 'Are ghosts real?')
Insert into Questions values (4, 'john', '2016-01-01', 'Medical', 'Does daily exercise decrease the risk of heart attack?')
Insert into Questions values (5, 'peter', '2018-1-1', 'Programing', 'Can we make a foreign key using one attribute of a composite primary key?')
Insert into Questions values (6, 'peter', '2019-1-1', 'International Relations', 'What are the pros and cons of Brexit for the UK?')



Insert into Answers values (1, 'john', '2017-02-02', 'Probably. Much research is being carried out on this area. Please see this video: https://bit.ly/2T7gVAi.')
Insert into Answers values (1, 'ali', '2017-03-03', 'Arthur Caplan, a bioethicist, has written "Head transplants are fake news. Those who promote such claims and who would subject any human being to unproven cruel surgery merit not headlines but only contempt and condemnation.')

Insert into Answers values (2, 'john', '2017-03-03', 'you should learn java since java is more popular than C++ in industry.')
Insert into Answers values (2, 'umer', '2017-08-04', 'If you want to learn both eventually then you should learn C++ first and then java. If you want to learn only one language and your goal is to find a job in the industry, then you should learn java.')

Insert into Answers values (3, 'john', '2018-1-1', 'Yes they are real! My grandmother saw one in the kitchen at midnight.')
Insert into Answers values (3, 'ali', '2018-1-1', 'Scientifically, we can neither prove nor disprove whether ghosts exist.')
Insert into Answers values (3, 'junaid', '2018-3-1', 'Yes they are real')

Insert into answers values (4, 'peter', '2019-01-01', 'Exercise helps dilate the body''s blood vessels and enables blood to circulate more freely, said Byung-il William Choi, MD, a professor of cardiovascular medicine at the Medical College of Wisconsin in Milwaukee. In one study, Harvard researchers found up to a 20% reduction of heart-disease risk for those who most frequently got vigorous exercise. This category included running or jogging, swimming laps, playing tennis, or doing aerobics.')

Insert into Answers values(5, 'umer', '2019-2-14', 'You have to make the complete primary key a foreign key.')
Insert into Answers values(5, 'john', '2019-1-1', 'No. When you create a foreign key, the key that you "point to" in the other table must be a UNIQUE or PRIMARY KEY constraint. You cannot establish a foreign key that points to a column that allow duplicate values. It would be very hard to imagine how the data should "act" if you update one of the duplicate values in the other table (for instance).')
Insert into Answers values(5, 'ali', '2018-1-2', 'No. A foreign key must be made using all attributes of a composite primary key.')

Select * From Users
Select * From Followers
Select * From Questions
Select * From QuestionCategories
Select * From Answers
