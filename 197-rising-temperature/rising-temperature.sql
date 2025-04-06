# Write your MySQL query statement below
select id from weather w1 where temperature > (select temperature from weather w2 
where w2.recorddate = DATE_SUB(w1.recorddate, INTERVAL 1 DAY));