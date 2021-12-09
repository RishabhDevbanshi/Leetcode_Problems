Select email
FROM Person
Group By email
Having Count(email)>1;