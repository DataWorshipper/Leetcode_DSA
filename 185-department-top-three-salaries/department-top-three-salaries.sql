WITH cte AS (
    SELECT
        e1.name,
        e1.salary,
        e1.departmentId,
        d1.name AS Department
    FROM Employee AS e1
    JOIN Department AS d1
        ON e1.departmentId = d1.id
),
cte_2 AS (
    SELECT *,
           dense_rank() OVER(
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM cte
)
SELECT Department, name as Employee, salary as Salary
FROM cte_2
WHERE rnk <= 3;