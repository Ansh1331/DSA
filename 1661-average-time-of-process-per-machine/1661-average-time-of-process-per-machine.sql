# Write your MySQL query statement below
select machine_id,
    ROUND(SUM(
        CASE WHEN activity_type='start' then timestamp*-1 
        else timestamp END
    )*1.0/(SELECT count(DISTINCT process_id)),3) as processing_time from Activity group by machine_id;