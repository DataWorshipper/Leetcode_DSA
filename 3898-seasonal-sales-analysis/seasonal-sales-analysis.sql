# Write your MySQL query statement below
with cte as(select s1.sale_id,s1.product_id,s1.sale_date,s1.quantity,s1.price,s2.product_name,s2.category from sales s1 join products s2 on s1.product_id=s2.product_id),
cte_2 as(
select *,month(sale_date) as mth from cte),
cte_3 as(
SELECT *,
       CASE 
           WHEN mth IN (12, 1, 2) THEN 'Winter'
           WHEN mth IN (3, 4, 5) THEN 'Spring'
           WHEN mth IN (6, 7, 8) THEN 'Summer'
           WHEN mth IN (9, 10, 11) THEN 'Fall'
       END AS season
FROM cte_2),
cte_4 as(
select season,category,sum(quantity) as total_quantity,sum(quantity*price) as total_revenue  from cte_3 group by season,category),
cte_5 as(
select *, dense_rank() over(partition by season order by total_quantity desc,total_revenue desc,category asc) as rnk from cte_4)
select season,category,total_quantity,total_revenue from cte_5  where rnk=1

