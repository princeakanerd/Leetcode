# Write your MySQL query statement below

SELECT eu.unique_id , e.name
FROM Employees as e
left JOIN EmployeeUNI as eu
ON e.id = eu.id ;
