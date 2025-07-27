# Write your MySQL query statement below

  select id from (select id,temperature,recordDate ,lag(temperature) over(order by recordDate)  as prev_temp,lag(recordDate) over(order by recordDate) as prev_date from Weather) as t where temperature>prev_temp and prev_temp is not null  and datediff(recordDate,prev_date)=1