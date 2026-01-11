--create database SALES

--use SALES

--create table salesman
--(
--salesmanID char(4) primary key,
--name varchar(30),
--city varchar(20),
--commission float
--)

--create table Customers
--(
--custID char(4) primary key,
--custName varchar(30),
--city varchar(20),
--grade int,
--salesmanID char(4) foreign key references salesman(salesmanID)

--)

--create table orders
--(
--orderNo char(5) primary key,
--purchaseAmt float,
--orderDate date,
--custID char(4) foreign key references customers(custID),
--salesmanID char(4) Foreign key references salesman(salesmanID)
--)

--insert into salesman
--values
--('5001', 'James Hoog', 'New York', 0.15),
--('5002', 'Nail Knite', 'Paris', 0.13),
--('5005', 'Pit Alex', 'London', 0.11),
--('5006', 'Mc Lyon', 'Paris', 0.14),
--('5007', 'Paul Adam', 'San Jose', 0.13),
--('5003', 'Lauson Hen', 'San Jose', 0.12)

--select * from salesman

--insert into orders
--values
--('70001', 150.5, '2012-10-05', '3005', '5002'),
--('70009', 270.65, '2011-09-10', '3001', '5005'),
--('70002', 65.26, '2014-10-05', '3002', '5001'),
--('70004', 110.5, '2011-08-17', '3009', '5003'),
--('70007', 948.5, '2012-09-10', '3005', '5002'),
--('70005', 2400.6, '2010-07-27', '3007', '5001'),
--('70008', 5760, '2013-09-10', '3002', '5001'),
--('70010', 1983.43, '2010-10-10', '3004', '5006'),
--('70003', 2480.4, '2013-10-10', '3009', '5003'),
--('70012', 250.45, '2010-06-27', '3008', '5002'),
--('70011', 75.29, '2014-08-17', '3003', '5007'),
--('70013', 3045.6, '2010-04-25', '3002', '5001')

--select * from orders

--insert into customers
--values
--('3002', 'Nick Rimando', 'New York', 100, '5001'),
--('3007', 'John Brad Davis', 'New York', 200, '5001'),
--('3005', 'Graham Zusi', 'California', 200, '5002'),
--('3008', 'Julian Green', 'London', 300, '5002'),
--('3004', 'Fabian Johnson', 'Paris', 300, '5006'),
--('3009', 'Geoff Cameron', 'Berlin', 100, '5003'),
--('3003', 'Jozy Altidor', 'Moscow', 200, '5007'),
--('3001', 'John Brad Guzan', 'London', NULL, '5005')

--select * from customers


--TASK 1
--select *
--from customers
--where city='New York'
--order by custName ASC


--TASK 2
--select *
--from customers 
--where (CustName LIKE '% John' OR CustName Like 'John %') 
--AND (city='London' OR city='Paris' OR city='New York')


--TASK 3
--select * 
--from customers
--where (city='London' OR city='New York')


--TASK 4
--select * 
--from orders
--where purchaseAmt>500


--TASK 5
--select *
--from salesman
--where name LIKE '_a%'


--TASK 6
--update salesman
--set commission=commission+0.5
--where city= 'San Jose'

--select * from salesman


--TASK 7
--select *
--from orders
--order by orderDate DESC


--TASK 8
--substring(attributeName, startPos, length)
--we must note that the indexing starts from 1 in sql
--charindex(character, attributeName) gives index of the first appearnace of character 
--len(attributename) gives the length of the row value of specific colums

--select SUBSTRING(name, 0, charindex(' ', name)) AS fullName
--From salesman


--TASK 9
--select *
--from orders
--where MONTH(orderDate)=10

--displayed fro the month of october as no entry in January


--TASK 10
--select EXTraCT(YEAR from orderDate) as Yearsa, EXTraCT(Month from orderDate) as Monthsa, Extract(day from orderDate) as daysa
--from orders
--where Month(orderDate)=10

--select day(orderDate) as mDay, month(orderDate) as mMonth, year(orderDate) as mYear, datepart(dayofyear, orderDate) as DayOfYear, datepart(week, orderDate) as weekOfYear, datepart(weekday, orderDate) as weekDay 
--from orders
--where month(orderDate)=10 


--TASK 11
--update orders
--set purchaseAmt*=3
--where month(orderDate)=10

--select* from orders


--TASK 12
--select custID AS CustomerID FROM orders where year(orderDate)=2014
--intersect
--select custID AS CustomerID FROM orders where year(orderDate)=2012


--TASK 13
--(select custID AS CustomerID
--FROM orders 
--where year(orderDate)=2011 OR year(orderDate)=2013)


--TASK 14
--select custID AS CustomerID FROM orders where year(orderDate)=2012
--except
--select custID AS CustomerID FROM orders where year(orderDate)=2014