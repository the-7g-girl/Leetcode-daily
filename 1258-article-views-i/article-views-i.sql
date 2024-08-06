# Write your MySQL query statement below
SELECT  viewer_id AS id
FROM views
GROUP BY viewer_id,author_id
HAVING viewer_id=author_id
ORDER BY viewer_id