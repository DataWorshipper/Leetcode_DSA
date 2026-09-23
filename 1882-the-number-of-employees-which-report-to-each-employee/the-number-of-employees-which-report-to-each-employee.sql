# Write your MySQL query statement below
with cte as (select e1.name,e2.reports_to,e2.employee_id,e2.age from Employees as e1 right join Employees as e2 on
e1.employee_id=e2.reports_to)
select reports_to as employee_id,name,count(*) as reports_count,round(avg(age),0) as average_age from cte group by reports_to having reports_to is  not null order by employee_id