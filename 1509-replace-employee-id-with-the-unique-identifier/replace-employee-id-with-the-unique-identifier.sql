# Write your MySQL query statement below
select uni.unique_id , e.name 
from Employees e
left join EmployeeUNI uni on uni.id=e.id