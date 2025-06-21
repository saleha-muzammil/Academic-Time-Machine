create database midterm_q1
use midterm_q1


--a---

create table Movies(
	movieId int not null,
	movieName varchar(50),
	runningTime time(0),
	studioId int,
	primary key(movieId)
);

create table Studios(
	studioId int not null,
	studioName varchar(50),
	primary key(studioId)
);

create table Genres(
	genreId int not null,
	genreName varchar(50),
	primary key(genreId)
);

create table MovieGenre(
	movieId int not null,
	genreId int not null,
	primary key(movieId,genreId)
);


--b---


alter table Movies add constraint Fk1 foreign key(studioId) references Studios(studioId) on update cascade on delete set null

alter table MovieGenre add constraint Fk2 foreign key(movieId) references Movies(movieId) on update cascade on delete cascade

alter table MovieGenre add constraint Fk3 foreign key(genreId) references Genres(genreId) on update cascade -- default on delete is restrict so would not let genreId to be deleted in Genres table



---c---

--1--
alter table Movies add yearReleased int NULL

--2--
alter table Studios add constraint U1 Unique(studioName)

--3--
alter table Movies add constraint NN1 check (movieName!=NULL)

--4--
alter table Movies add constraint Cktime check(runningTime>N'00:00:00')

--5--
alter table Movies add constraint ckyear check(yearReleased <= datepart(yyyy,getdate()))



