with cte as(select e1.name as manager,e2.name as employee,e2.managerId as manager_id from Employee as e1 join Employee as e2 on
e1.id=e2.managerId),
 cte_2 as (
select manager,manager_id,count(*) over(partition by manager_id) as num_employees from cte),
cte_3 as(
select distinct manager_id,manager from cte_2  where num_employees>=5 )
select manager as name from cte_3

