with cte as(
select * from Products where datediff(change_date,'2019-08-16')<=0),
cte_2 as(
select *, row_number() over(partition by product_id order by change_date desc) as r1 from cte)
select product_id,new_price as price from cte_2 where r1=1
 union 
 select product_id,10 as price from Products group by product_id having min(change_date)>'2019-08-16'
