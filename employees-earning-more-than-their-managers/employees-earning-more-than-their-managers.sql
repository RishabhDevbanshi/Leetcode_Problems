select e.name as Employee
from Employee e,Employee em
where e.managerID = em.id
and e.salary > em.salary;