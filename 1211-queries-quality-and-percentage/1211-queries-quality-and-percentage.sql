# Write your MySQL query statement below
select query_name, 
ROUND(AVG(rating/position),2) as quality,
ROUND(AVG(CASE WHEN rating<3 THEN 1 ELSE 0 END)*100,2) as poor_query_percentage
from Queries group by query_name;