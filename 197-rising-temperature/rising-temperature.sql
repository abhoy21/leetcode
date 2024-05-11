# Write your MySQL query statement below
SELECT w2.id
FROM Weather w1 JOIN Weather w2
ON DATEDIFF(w1.recorddate, w2.recorddate) = -1
AND w2.temperature > w1.temperature