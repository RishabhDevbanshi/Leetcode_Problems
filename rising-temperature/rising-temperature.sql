Select x.id 
from Weather x
Join Weather y
on x.temperature > y.temperature
and datediff(x.recordDate,y.recordDate) = 1;