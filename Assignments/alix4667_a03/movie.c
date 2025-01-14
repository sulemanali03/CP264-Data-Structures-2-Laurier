/**
 * -------------------------------------
 * @file  movie.c
 * movie Source Code File
 * -------------------------------------
 * @author Suleman Ali,169044667, alix4667@mylaurier.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "movie.h"

// Define the genre names and the count of genres
const char *GENRES[] = { "Action", "Comedy", "Drama", "Horror", "Romance" };
const int GENRES_COUNT = 5;

void movie_init(movie_struct *source, const char *title, int year,
		const char *director, int genre, float rating) {
	assert(year >= FIRST_YEAR);
	assert(rating >= MIN_RATING && rating <= MAX_RATING);

	strncpy(source->title, title, MAX_STRING - 1);
	strncpy(source->director, director, MAX_STRING - 1);
	source->year = year;
	source->genre = genre;
	source->rating = rating;
}

void movie_copy(const movie_struct *source, movie_struct *target) {
	movie_init(target, source->title, source->year, source->director,
			source->genre, source->rating);
}

int movie_compare(const movie_struct *source, const movie_struct *target) {
	int title_compare = strcmp(source->title, target->title);
	if (title_compare == 0) {
		return source->year - target->year;
	} else {
		return title_compare;
	}
}

void movie_print(const movie_struct *source) {
	printf("Title:    %s\n", source->title);
	printf("Year:     %d\n", source->year);
	printf("Director: %s\n", source->director);
	printf("Genre:    %s\n", GENRES[source->genre]);
	printf("Rating:   %.1f\n", source->rating);
}

char* movie_key(char *str, size_t max_length, movie_struct *source) {
	snprintf(str, max_length, "%s, %d", source->title, source->year);
	return str;
}

void genres_menu() {
	for (int i = 0; i < GENRES_COUNT; i++) {
		printf("%d: %s\n", i, GENRES[i]);
	}
}
