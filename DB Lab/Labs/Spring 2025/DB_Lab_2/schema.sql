create database customer_salesman;

use customer_salesman;

create table salesman(
salesman_Id int, 
name varchar(255),
city varchar(255),
commission decimal(4,2),
constraint salepk primary key(salesman_Id)
);

create table customers(
customer_Id int,
cust_name varchar(255),
city varchar(255),
grade int,
salesman_Id int,
constraint custpk primary key(customer_Id),
constraint cust_salesfk foreign key(salesman_Id) references salesman(salesman_Id),
);

create table orders(
ord_no int,
purch_amt decimal(10,2),
ord_date date,
customer_Id int,
salesman_Id int,
constraint orderpk primary key(ord_no),
constraint order_salesfk foreign key(salesman_Id) references salesman(salesman_Id),
constraint order_custfk foreign key(customer_Id) references customers(customer_Id)
);

insert into salesman (salesman_id, name, city, commission) values
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14),
(5007, 'Paul Adam', 'San Jose', 0.13),
(5003, 'Lauson Hen', 'San Jose', 0.12);

insert into customers (customer_id, cust_name, city, grade, salesman_id) values
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3007, 'John Brad Davis', 'New York', 200, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3008, 'Julian Green', 'London', 300, 5002),
(3004, 'Fabian Johnson', 'Paris', 300, 5006),
(3009, 'Geoff Cameron', 'Berlin', 100, 5003),
(3003, 'Jozy Altidor', 'Moscow', 200, 5007),
(3001, 'John Brad Guzan', 'London', NULL, 5005);

insert into orders (ord_no, purch_amt, ord_date, customer_id, salesman_id) values
(70001, 150.50, '2012-10-05', 3005, 5002),
(70009, 270.65, '2011-09-10', 3001, 5005),
(70002, 65.26, '2014-10-05', 3002, 5001),
(70004, 110.50, '2011-08-17', 3009, 5003),
(70007, 948.50, '2012-09-10', 3005, 5002),
(70005, 2400.60, '2010-07-27', 3007, 5001),
(70008, 5760.00, '2013-09-10', 3002, 5001),
(70010, 1983.43, '2010-10-10', 3004, 5006),
(70003, 2480.40, '2013-10-10', 3009, 5003),
(70012, 250.45, '2010-06-27', 3008, 5002),
(70011, 75.29, '2014-08-17', 3003, 5007),
(70013, 3045.60, '2010-04-25', 3002, 5001);