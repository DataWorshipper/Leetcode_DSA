# Write your MySQL query statement below
with cte as(
select *,date_format(trans_date,'%Y-%m') as month from Transactions)
select month,country,count(*) as trans_count,sum(state='approved') as approved_count,sum(amount) as  trans_total_amount,SUM(
    CASE
        WHEN state = 'approved' THEN amount
        ELSE 0
    END
) as approved_total_amount from cte group by country,month