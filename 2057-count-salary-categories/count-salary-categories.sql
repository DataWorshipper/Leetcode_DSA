# Write your MySQL query statement below
with cte as(select *, case
when income<20000 then 'Low Salary'
when income>=20000 and income<=50000 then 'Average Salary'
else  'High Salary'  end as category from Accounts),
categories as(
    select 'Low Salary' as category
    union all
     SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)
select categories.category,count(cte.category) as accounts_count from cte right join categories on
cte.category=categories.category group by categories.category