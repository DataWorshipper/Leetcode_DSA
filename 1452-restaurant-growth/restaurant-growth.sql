 WITH cte_x AS (
    SELECT
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),cte as (select visited_on,sum(amount) over(order by visited_on  rows between 6 preceding and current row) as am,round(avg(amount) over(order by visited_on  rows between 6 preceding and current row),2) as avg,row_number() over(order by visited_on) as rn from cte_x)
select visited_on,am as amount, avg as average_amount from cte where rn>=7 order by visited_on