# Write your MySQL query statement below
SELECT a.name
FROM Employee AS a
JOIN Employee AS b
ON a.id = b.managerId
GROUP BY b.managerId
HAVING COUNT(*) >= 5;