# Write your MySQL query statement below
SELECT e1.employee_id , e1.name , count(e2.reports_to) as reports_count  , round(avg(e2.age*1.0),0) as average_age 
from Employees e1
inner join Employees e2
on e1.employee_id = e2.reports_to
where e1.employee_id = e2.reports_to
group by e2.reports_to
order by e1.employee_id


-- select a.employee_id,a.name,count(*) as reports_count,round(avg(b.age*1.0),0) as average_age
-- from Employees a inner join Employees b
-- on a.employee_id=b.reports_to
-- group by a.employee_id,a.name
-- order by a.employee_id