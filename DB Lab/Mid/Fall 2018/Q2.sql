-- Q2

--Part A


Select Emp_name,salary from Employee
Except
Select E.Emp_name,E.salary from Employee_Project EP Join Employee E on E.Emp_No=EP.Emp_No




--Part B


Select E.Emp_No As Employee_Number,E.Emp_name As Employee_Name,M.Emp_No As Manager_Number,M.Emp_name As Manager_Name 
from Employee E Join Employee M on E.Manager=M.Emp_No And DATEPART(year,E.hire_date)=DATEPART(year,M.hire_date)



--C

Select grade,Avg(salary) As Average_Salary from Employee E Join Salary_Grade SG on SG.Minsalary<=E.salary And E.salary<=SG.Maxsalary
Group By SG.grade


--D

Select E.Emp_Name,E.Emp_No,E.salary,EP.Pro_id,P.pro_Name,SG.grade from Employee E Join Salary_Grade SG on SG.Minsalary<=E.salary
And E.salary<=SG.Maxsalary Join Employee_Project EP on EP.Emp_no=E.Emp_No Join Projects P on P.pro_id=EP.Pro_id
where E.Emp_No IN (
Select EE.Emp_No from Employee EE Join Employee_Project EPP on EE.Emp_no=EPP.Emp_No Group By EE.Emp_No having Count(*)=1
)



--E

Select EE.Emp_Name,DD.Dept_Name from Employee EE Join Department DD 
on DD.Dept_No=EE.Dept_No And EE.Hire_Date IN
(Select Max(E.Hire_Date)As T from Employee E Join Department D on D.Dept_No=E.Dept_No Group By D.Dept_No)














