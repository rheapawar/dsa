# Write your MySQL query statement below
#first do a group by the user id, then partition by id using lead, then count the gap 
WITH gaps AS(
    SELECT user_id, 
    created_at,
    DATEDIFF(
        LEAD(created_at, 1) OVER (PARTITION BY user_id ORDER BY created_at), created_at
    ) as days_between
    FROM Users
)
SELECT DISTINCT user_id
FROM gaps
WHERE days_between IS NOT NULL AND days_between <= 7

