# Write your MySQL query statement below
with cte as 
(select p1.project_id,p1.employee_id,e1.experience_years from Project as p1 left join  Employee as e1 on
p1.employee_id=e1.employee_id)
select project_id,round(sum(experience_years)/count(*),2) as average_years from cte group by project_id