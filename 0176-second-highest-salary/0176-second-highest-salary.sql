# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from employee where salary NOT IN (select max(salary) from employee)