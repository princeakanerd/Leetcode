# Write your MySQL query statement below
select w2.id 
from Weather as w1 
inner join weather as w2
on w1.recordDate = w2.recordDate - INTERVAL 1 DAY and w2.temperature > w1.temperature