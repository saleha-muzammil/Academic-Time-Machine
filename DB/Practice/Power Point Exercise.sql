use CompanyElmasri
--Select the EMPLOYEEs whose department # is 4
select Employee.Fname, Department.Dname,Department.Dnumber from Employee
join Department on Employee.Dno =Department.Dnumber where Department.Dnumber =4
--======================================================================================

--Select the EMPLOYEEs whose salary > $30,000
select Employee.Fname, Employee.Salary from Employee where Employee.Salary > 30000

--======================================================================================
--Intersection

select Students.Fname from Students intersect select Instructors.Fname from Instructors

-- intersection using join

select Students.Fname from Students join Instructors on Students.InstructorId=Instructors.Id

--======================================================================================
--Union
select Students.Fname from Students union select Instructors.Fname from Instructors

--======================================================================================
--diffrence student - instructors 

select Students.Fname from Students EXCEPT select Instructors.Fname from Instructors

--diffrence instructors - student 

select Instructors.Fname from Instructors EXCEPT select Students.Fname from Students

--=======================================================================================


--Give the SSNs of those managers have dependent(s).
select Employee.Fname,Employee.Ssn from Employee where Employee.Ssn in(select distinct Dependent.Essn from Dependent)

--========================================================================================
--Give the SSNs non-manager employees

select Employee.Fname , Employee.Ssn from Employee where Employee.Ssn not in (select distinct Employee.Super_ssn from Employee where Employee.Super_ssn is not null)

--=========================================================================================
--Give the SSNs of employees who are both supervisors and supervisees

select Employee.Fname,Employee.Ssn from Employee where Employee.Ssn in (select distinct Employee.Super_ssn from Employee) and Employee.Super_ssn is not null
--==========================================================================================
--To find the dependents’ names of all female employees

select Employee.Fname, Dependent.Dependent_name from Dependent join Employee on Employee.Ssn=Dependent.Essn where Employee.Sex = 'F'

--==========================================================================================
--List the names of those departments that have at least one female employee whose salary >= $25000. 
select distinct Department.Dname,Employee.Sex from Department join Employee on Employee.Dno=Department.Dnumber where Employee.Sex='F' and Employee.Salary >= 25000

--==========================================================================================
--List the Names and SSNs of the managers of the above departments

select Employee.Fname,Employee.Ssn, Department.Dname from Employee join Department on Employee.Dno=Department.Dnumber where Employee.Ssn in (select Employee.Super_ssn from Employee)

--===========================================================================================
--find the dependents’ names of all female employees
select Dependent.Dependent_name from Dependent join Employee on Dependent.Essn =Employee.Ssn where Employee.Sex='F'

--===========================================================================================
--List names and SSNs of those EMPLOYEE who work on some project(s) located in Houston
select distinct Employee.Fname, Project.Plocation from Employee  join Works_On on Employee.Ssn=Works_On.Essn join Project on Works_On.Pno=Project.Pnumber where Project.Plocation='Houston'

--===========================================================================================

--List the names and birth dates of all female dependents born after 1980
select Dependent.Dependent_name,Dependent.Bdate from Dependent where Dependent.Bdate >'1980'

--===========================================================================================
--List the names of all employees who earns salary > $10,000 but does not supervise anyone

select Employee.Fname from Employee where Employee.Salary > 10000 and Employee.Ssn not in (select distinct Employee.Super_ssn from Employee where Employee.Super_ssn is not null)

--============================================================================================

--Finished

