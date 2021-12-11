SELECT s.Score as Score,
DENSE_RANK() OVER (ORDER BY s.Score DESC) as `Rank`
FROM Scores s