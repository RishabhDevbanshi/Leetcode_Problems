SELECT s.score , count(distinct t.score) "Rank"
FROM Scores s JOIN Scores t
ON s.score <= t.score
GROUP BY s.id
ORDER BY s.score desc