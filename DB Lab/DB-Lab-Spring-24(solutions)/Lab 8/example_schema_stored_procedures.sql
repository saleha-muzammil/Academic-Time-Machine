--create database lab_stored_pro
--use lab_stored_pro
--drop database lab_stored_pro
--use master
go
create table vehicle
(
vehicle_id varchar(10) Primary key,
engine_no varchar(10),
chassis_no varchar(10),
horsepower int,
company varchar(10),
model_no varchar(10),
make varchar(10),
price int,
typevehicle int-- four wheel or two wheel drive
)
go
create table dealer
(
dname varchar(20),
d_id varchar(10) primary key ,
d_address varchar(250),
d_cnic varchar(15) not null unique,
contact varchar(20)
)
go
--drop table dealer
create table customer
(
cname varchar(10),
c_id varchar(10) primary key,
c_address varchar(250),
c_cnic varchar(15) not null unique,
contact varchar(20)
)
go
go
create table inventory
(
modelno varchar(10),
make varchar(10),
company varchar(10),
articles_available int
primary key(modelno, make, company)
)
go
go
--drop table inventory
create table deals
(
v_id varchar(10) foreign key references vehicle (vehicle_id),
c_id varchar(10) foreign key references customer(c_id),
d_id varchar(10) foreign key references dealer(d_id),
payment_mode varchar(4),
payment_plan varchar(10),
paid int,
left_amount int,
date_deal date
)
go
go
create table orders
(
c_id varchar(10) foreign key references customer(c_id),
d_id varchar(10) foreign key references dealer(d_id),
make varchar(10),-- foreign key references inventory(make),
company varchar(10),-- foreign key references inventory(company),
model varchar(10), --foreign key references inventory (model)
dateorder date,-- date of order
status_order int,--1 for complete 0 for pending
date_completeion date
)
go
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12X3456789','1234567890',
'xx22335588',50,'toyota', '06', 'corolla', 1600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12Y3466789','1234876090',
'xx22315598',50,'toyota', '06', 'corolla', 1600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12Y3466889','0123658974',
'xx22315593',50,'daihatsu', '06', 'lala', 600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12A3456889','0123690974',
'wa22315593',50,'suzuki', '12', 'car', 600000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12A3456877','0123770974',
'wa22315598',50,'suzuki', '15', 'car', 650000,2)
insert into vehicle (vehicle_id ,engine_no ,chassis_no ,horsepower ,company ,model_no ,make ,price,typevehicle ) values ('12J3456889','0123690974',
'wa22313693',50,'hyundai', '17', 'small car', 800000,2)
------------------------------------------------------

insert into dealer (dname ,d_id ,d_address ,d_cnic ,contact ) values('asif','d123xyzbbb', 'Islamabad', '12345-1234567-1','03001234567')
insert into dealer (dname ,d_id ,d_address ,d_cnic ,contact ) values('zahid','d224xyzbbb', 'Lahore', '13345-1234367-1','03001254567')
insert into dealer (dname ,d_id ,d_address ,d_cnic ,contact ) values('khalid','d123xyzbab', 'Karachi', '12345-1234568-1','03001294567')
insert into dealer (dname ,d_id ,d_address ,d_cnic ,contact ) values('khursheed','d789xyzbbb', 'Peshawar', '54321-1234567-1','03009876543')
------------------------------------------------------

insert into customer (cname ,c_id ,c_address ,c_cnic ,contact ) values ('kashif','c123xyzlal','Islamabad','35351-8906751-0','03111234567')
insert into customer (cname ,c_id ,c_address ,c_cnic ,contact ) values ('rehman','c123xyzjix','Karachi','35351-8906720-1','03111233767')
insert into customer (cname ,c_id ,c_address ,c_cnic ,contact ) values ('habib','c123xyzlbl','Lahore','38351-9906751-0','03211236567')
insert into customer (cname ,c_id ,c_address ,c_cnic ,contact ) values ('farhan','c123xyzkal','Peshawar','35351-5906951-2','03131234567')
------------------------------------------------------
insert into inventory (modelno,make ,company ,articles_available ) values (15,'car','suzuki',20)
insert into inventory (modelno,make ,company ,articles_available ) values (12,'car','suzuki',35)
insert into inventory (modelno,make ,company ,articles_available ) values (06,'lala','daihatsu',0)
insert into inventory (modelno,make ,company ,articles_available ) values (17,'small car','hyundai',3)
insert into inventory (modelno,make ,company ,articles_available ) values (06,'lala','daihatsu',0)
--update inventory set modelno=17 where make ='small car'
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12A3456877','c123xyzjix','d123xyzbab','card','immediate',650000,0 ,'01/23/2017')
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12J3456889','c123xyzlbl','d224xyzbbb','cash','install',500000,300000 ,'01/23/2017')
insert into deals (v_id,c_id ,d_id ,payment_mode ,payment_plan ,paid ,left_amount ,date_deal) values ('12Y3466789','c123xyzkal','d789xyzbbb','cash','immediate',1600000,0 ,'05/03/2015')
--truncate  table deals
insert into orders (c_id ,d_id ,make ,company,model , dateorder,status_order ,date_completeion ) values ('c123xyzjix','d123xyzbab','car','suzuki','12','10/02/2017',1,'10/02/2017')
insert into orders (c_id ,d_id ,make ,company,model , dateorder,status_order ,date_completeion ) values ('c123xyzlbl','d224xyzbbb','lala','daihatsu','6','09/02/2017',0,'09/02/2017')
select * from vehicle
select * from customer
select * from dealer
select * from inventory
select * from deals
update vehicle set typevehicle = 4 where chassis_no='xx22315593'