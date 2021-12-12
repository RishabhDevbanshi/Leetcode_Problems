SELECT d.name as 'Department', e.name as 'Employee', salary
FROM Employee as e
JOIN Department as d
ON e.departmentId = d.id
WHERE
(e.departmentId,salary) IN
(SELECT departmentId, MAX(Salary)
FROM Employee
GROUP BY departmentId);