# Write your MySQL query statement below
select (Select distinct  salary from Employee
order by salary DESC
limit 1,1)  as  SecondHighestSalary

