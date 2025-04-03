# Write your MySQL query statement below
select e1.name, e2.unique_id from employees e1 
left join employeeuni e2 on e1.id  = e2.id;