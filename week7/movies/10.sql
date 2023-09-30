SELECT DISTINCT name FROM people
JOIN directors ON directors.person_id = people.id
JOIN movies on movies.id = directors.movie_id
JOIN ratings on ratings.movie_id = movies.id
WHERE rating >= 9.0;