# Write your MySQL query statement below
SELECT e.id FROM Weather e, Weather ee WHERE DATEDIFF(e.recordDate,ee.recordDate) = 1 AND e.temperature > ee.temperature;