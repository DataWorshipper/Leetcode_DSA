# Write your MySQL query statement below

with CTE as(
select name,bonus from Employee left join Bonus on Employee.empId=Bonus.empId )

select name,bonus from CTE where bonus<1000 or bonus is null