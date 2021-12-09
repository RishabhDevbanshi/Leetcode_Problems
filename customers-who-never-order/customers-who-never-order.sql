SELECT c.name AS Customers
FROM Customers as c
LEFT JOIN Orders as o
On c.id = o.customerID
WHERE o.id IS NULL;