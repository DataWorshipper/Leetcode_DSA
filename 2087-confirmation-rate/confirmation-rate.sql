# Write your MySQL query statement below
 with cte as (select  s1.user_id,c1.action from Signups as s1 left join Confirmations as c1 on
s1.user_id=c1.user_id)
select user_id,round((coalesce(sum(action='confirmed'),0)/count(*)),2) as confirmation_rate from cte group by user_id 

