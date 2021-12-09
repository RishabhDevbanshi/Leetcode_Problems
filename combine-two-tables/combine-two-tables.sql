Select p.firstName,p.lastName,a.city,a.state
FROM Person as p
LEFT JOIN Address as a
On p.personID = a.personID;