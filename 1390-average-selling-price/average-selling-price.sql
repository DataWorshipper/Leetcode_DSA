WITH cte AS (
    SELECT p1.product_id, p1.price, u1.units
    FROM Prices AS p1
    LEFT JOIN UnitsSold AS u1
        ON p1.product_id = u1.product_id
        AND DATEDIFF(u1.purchase_date, p1.start_date) >= 0
        AND DATEDIFF(u1.purchase_date, p1.end_date) <= 0
), 
cte_2 AS ( 
    SELECT product_id, price * units AS total_price, units
    FROM cte 
) 
SELECT 
    product_id,
    case 
    when coalesce(sum(units),0)=0 then 0
    else    ROUND(
        COALESCE(SUM(total_price), 0) / COALESCE(SUM(units), 0),
        2
    ) 
    end
    AS average_price
    
FROM cte_2
GROUP BY product_id;