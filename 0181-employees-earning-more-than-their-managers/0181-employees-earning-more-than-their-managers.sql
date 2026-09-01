# Write your MySQL query statement below
SELECT e.name as Employee
from Employee e
JOIN Employee m
ON e.managerId = m.id
where e.salary > m.salary