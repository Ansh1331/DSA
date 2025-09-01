# Write your MySQL query statement below
select w.id from Weather w join Weather w1 on DATEDIFF(w.recordDate,w1.recordDate) =1 where w.temperature>w1.temperature;