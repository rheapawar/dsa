# Write your MySQL query statement below
#group by event type in a temp table
#create another temp table where th

WITH AvgActivities AS(
    SELECT 
        event_type,
        avg(occurrences) as avg_occ
    FROM Events
    GROUP BY event_type
)
SELECT 
    business_id
FROM Events b
INNER JOIN AvgActivities a ON a.event_type = b.event_type
WHERE b.occurrences > a.avg_occ
GROUP BY business_id
HAVING COUNT(*) >= 2;