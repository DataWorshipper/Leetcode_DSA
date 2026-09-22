SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
GROUP BY activity_date
HAVING DATEDIFF(activity_date, '2019-07-27') <= 0
   AND DATEDIFF(activity_date, '2019-07-27') >= -29;