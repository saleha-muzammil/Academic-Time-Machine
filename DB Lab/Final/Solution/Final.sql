

create table creators
(
c_id int primary key,
first_name varchar(10) not null,
last_name varchar(10) not null,
[city] varchar(20) not null,
contact varchar(11) not null,
email varchar(30),
[creator_Trainer_id] int foreign key references creators(c_id)
)
go

create table piece_type
(
[type_id] int primary key,
[type_name] varchar(30) not null
)

go

create table art_pieces
(
art_id int primary key,
art_name varchar(30) not null,
price int not null,
quantity_available int not null
)

go

create table art_piece_details(
art_id int foreign key references art_pieces(art_id) primary key,
[type_id] int foreign key references piece_type([type_id]),
creator_id int foreign key references creators(c_id),
release_date date not null
)


go

create table payment_mode
(
p_id int primary key,
payment_mode varchar(10)
)

go


create table sale 
(
s_id int primary key,
art_id int foreign key references art_pieces(art_id),
date_of_sale date not null,
quantity int not null,
payment_mode_id int foreign key references payment_mode(p_id)
)

go


insert into piece_type ([type_id], [type_name]) values (1,'painting'),
(2,'sculpture'),
(3,'portrait'),
(4,'scenery'),
(5,'Machine')

go

insert into creators values (1,'Ali','Ahmad','Lahore', '03009434025','abc@hotmail.com',NULL),
(2,'Alia','Butt','Gujranwala', '03009474025','def@gmail.com',1),
(3,'Rani','Khurram','Faisalabad', '03339434025','rania@hotmail.com',NULL),
(4,'Hadia','Tanzeel','Lahore', '03009434052','ramin@hotmail.com',2),
(5,'Tanzeela','Akbar','Jhelum', '03219434025','tanzeel@hotmail.com',1),
(6,'Talha','Rana','Lahore', '03001034025','talha@hotmail.com',4),
(7,'Zulfiqar','Rana','Narowal','03004545898','Abc@d.com',NULL),
(8,'Sheeraz','Ali','Zafarwal','03004145098','Abc@d.com',4),
(9,'usman','Rana','Karachi','03004545498','Abc@d.com',1),
(10,'wasif','Wajid','Islamabad','03005545098','Abc@d.com',3)


go

insert into art_pieces values (1,'the rising sun' ,300,20),
(2,'the setting sun' ,230,2),
(3,'dark knight' ,90,12),
(4,'the sunlight',170,33),
(5,'big man' ,450,21),
(6,'little things',650,1),
(7,'beautiful Baby',50,20),
(8,'mountains',1300,21),
(9,'song' ,3500,11),
(10,'sonet',100,31),
(11,'the set sun' ,100,15),
(12,'zalmi',250,50),
(13,'the painting yo',1020,12),
(14,'Trump Pic' ,150,41),
(15,'Mind' ,390,7),
(16,'peace' ,600,12),
(17,'pleasant',305,1),
(18,'happy' , 659,21),
(19,'disturbed',190,21),
(20,'ignored' ,355,24)

go
insert into payment_mode (p_id , payment_mode ) values (1,'cash'),
(2,'card')

go

insert into art_piece_details values(1,5,3,'02/25/2018'),
(2,2,1,'03/2/2018'),
(3,3,6,'01/5/2018'),
(4,4,4,'02/25/2017'),
(5,5,6,'02/7/2018'),
(6,1,8,'04/20/2017'),
(7,2,10,'02/03/2017'),
(8,3,2,'12/25/2016'),
(9,4,3,'02/01/2013'),
(10,5,6,'10/2/2018'),
(11,2,7,'11/11/2014'),
(12,3,7,'05/21/2016'),
(13,4,8,'02/05/2014'),
(14,5,8,'07/02/2017'),
(15,3,1,'02/05/2017'),
(16,2,4,'02/17/2011'),
(17,1,3,'07/25/2012'),
(18,2,9,'02/25/2018'),
(19,1,10,'07/22/2010'),
(20,4,4,'05/05/2016')

go

insert into sale values (1, 2,'02/11/2018',2, 1),
(2, 10,'03/25/2018',2, 2),
(3, 13,'01/03/2018',3, 1),
(4, 8,'02/11/2018',1, 2),
(5, 5,'03/04/2018',4, 1),
(6, 4,'04/09/2018',10, 1),
(7, 5,'05/04/2018',9 ,1),
(8, 20,'04/09/2018',7, 1),
(9, 13,'03/05/2018',2,1),
(10, 20,'02/01/2018',3, 1),
(11, 15,'01/02/2018',3, 1)

go

select * from creators
select * from piece_type
select * from art_pieces
select * from art_piece_details
select * from sale
select * from payment_mode




--select ap.art_id,art_name,first_name,Sum(s.quantity) as TotalQuantity from art_pieces ap join sale s on ap.art_id=s.art_id join art_piece_details apd on apd.art_id=ap.art_id

-- join creators c on c.c_id=apd.creator_id group by ap.art_id,art_name,first_name having sum(s.quantity)< (select sum(s.quantity) from sale s where art_id=1)



 
 --create view neverbeensold

 --as

 --select distinct ap.*,first_name,last_name from art_pieces ap join art_piece_details apd on ap.art_id=apd.art_id 
 
 --join creators c on c.c_id=apd.creator_id join sale s on ap.art_id=s.art_id 
 
 --join payment_mode pm on pm.p_id=s.payment_mode_id where s.payment_mode_id!=2


 --select * from neverbeensold




 --select distinct c.first_name,c.email from creators c join creators j on c.c_id=j.creator_Trainer_id 
 
 --join art_piece_details apd on c.c_id=apd.creator_id join piece_type pt on apd.type_id=pt.type_id 
 
 --where ((pt.type_name='scenery' and pt.type_name='portrait') and pt.type_name!='sculpture') except select distinct c.first_name,c.email from creators c join creators j on c.c_id=j.creator_Trainer_id 
 
 --join art_piece_details apd on c.c_id=apd.creator_id join piece_type pt on apd.type_id=pt.type_id where pt.type_name='sculpture'




 
 --go
 --create trigger tt on creators
 
 --instead of insert

 --as begin

 --declare @cid int;
 --declare @fname varchar(10);
 --declare @lname varchar(10);
 --declare @city varchar(20);
 --declare @contact varchar(11);
 --declare @email varchar(30);
 --declare @cti int;

 --select @cid= c_id from inserted;
 --select @fname= first_name from inserted;
 --select @lname= last_name  from inserted;
 --select @city= city from inserted;
 --select @contact= contact from inserted;
 --select @email= email from inserted;
 --select @cti= creator_Trainer_id from inserted;

 --if(@fname=@lname)
 --begin
 --print('Data can not be inserted because first name and last name are equal');
 --end

 --else
 --begin

 --insert into creators values(@cid,@fname,@lname,@city,@contact,@email,@cti);
 --print('Data inserted');

 --end

 --end


 --insert into creators values(11,'Osama','Fayyaz','Lahore','03204805681','l164157@lhr.nu.edu.pk',1)







 --go
 --create function osama(@cid int)

 --returns int

 --as begin

 --declare @return int;

 --select @return = sum(s.quantity) from creators c join art_piece_details apd on c.c_id=apd.creator_id join art_pieces ap on ap.art_id=apd.art_id
 
 -- join sale s on ap.art_id=s.art_id where c.c_id=@cid;

 -- return @return;

 -- end

  
 -- execution:
 -- select dbo.osama(4) as TotalSold








 --create view Osama2

 --as
 

 --select first_name,c_id from creators c join art_piece_details apd on c.c_id=apd.creator_id join piece_type pt on pt.type_id=apd.type_id join art_pieces ap on ap.art_id=apd.art_id

 --join sale s on ap.art_id=s.art_id where pt.type_name='scenery' group by c_id,first_name having (sum(s.quantity) > (Select Sum(s.quantity) from  creators c join creators j on c.c_id=j.creator_Trainer_id

 --join  art_piece_details apd on c.c_id=apd.creator_id join art_pieces ap on ap.art_id=apd.art_id join sale s on ap.art_id=s.art_id))

 --select * from Osama2






-- go
-- alter procedure ReturnSoldArtPieces @sid int,@out1 varchar(20) output,@amountrefund int output
 
-- as begin

-- declare @oo int;

-- select @oo= s.s_id from sale s where @sid=s.s_id;

-- if(@oo!=0)
-- begin
 
-- declare @a int;
-- select @a= art_id from sale s where @sid=s.s_id;


-- delete from sale where s_id=@sid;

-- update art_pieces set quantity_available=quantity_available+1 where art_id=@a;

-- declare @p int;
-- select @p=price from art_pieces where art_id=@a;
 
-- declare @ww int;
-- select @ww=@p*s.quantity from sale s where @sid=s.s_id;
-- set @amountrefund=@ww;

-- set @out1='Deleted Successfully';

-- end 

-- else

-- begin

-- set @out1='Sale ID invalid';

-- end

-- end

-- declare @m1 varchar(20);
-- declare @ar int;
-- exec ReturnSoldArtPieces 5,@m1 output,@ar output
-- select @m1;
--select @ar as AmountRefunded;









