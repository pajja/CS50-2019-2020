SELECT title FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = ratings.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Chadwick Boseman"
ORDER BY title ASC
LIMIT 5;
