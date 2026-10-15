# Write your MySQL query statement below
with cte as (select  e1.name,e1.salary,d1.name as dept_name from Employee as e1 join Department as d1 on e1.departmentId=d1.id),
 cte_2 as(
select *,rank() over(partition by dept_name order by salary desc) as order_salary from cte )
select dept_name as Department, name as Employee, salary as Salary from cte_2 where order_salary=1
