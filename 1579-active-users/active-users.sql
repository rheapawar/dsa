WITH uniquelogins AS(
    SELECT DISTINCT
        id,
        login_date
    FROM Logins
),
RankedLogins AS(
    SELECT 
        id,
        login_date,
        ROW_NUMBER() OVER (PARTITION BY id ORDER BY login_date) as rn
    FROM uniquelogins
),
StreakGroups AS(
    SELECT
        id,
        DATE_SUB(login_date, INTERVAL rn DAY) as group_id
    FROM RankedLogins
),
ActiveIds AS(
    SELECT id
    FROM StreakGroups
    GROUP BY id, group_id
    HAVING COUNT(*) >= 5
)
SELECT DISTINCT a.id, a.name
FROM Accounts a
INNER JOIN ActiveIds b on a.id = b.id
ORDER BY a.id;