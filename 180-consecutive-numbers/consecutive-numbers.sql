# Write your MySQL query statement below
with cte as(select *,lag(num,1) over(order by id) as prev_number,lag(num,2) over(order by id) as prev_prev_number  from Logs)
select  distinct num as ConsecutiveNums from cte where num=prev_number and num=prev_prev_number
