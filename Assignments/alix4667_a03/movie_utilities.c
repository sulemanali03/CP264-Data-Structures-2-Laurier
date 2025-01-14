/**
 * -------------------------------------
 * @file  movie_utilities.c
 * Assignment 2 movie_utilities Source Code File
 * -------------------------------------
 * @author Suleman Ali,169044667, alix4667@mylaurier.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */

#include "movie_utilities.h"

void get_movie(movie_struct *source) {
	char title[MAX_STRING];
	char director[MAX_STRING];
	int year, genre;
	float rating;

	printf("Enter movie title: ");
	fgets(title, MAX_STRING, stdin);
	title[strcspn(title, "\n")] = 0; // Remove trailing newline

	printf("Enter director: ");
	fgets(director, MAX_STRING, stdin);
	director[strcspn(director, "\n")] = 0;

	printf("Enter year: ");
	scanf("%d", &year);

	genres_menu();
	printf("Choose genre (enter the number): ");
	scanf("%d", &genre);

	printf("Enter rating (0.0 - 10.0): ");
	scanf("%f", &rating);

	movie_init(source, title, year, director, genre, rating);
}

void read_movie(movie_struct *source, const char *line) {
	char title[MAX_STRING];
	char director[MAX_STRING];
	int year, genre;
	float rating;

	sscanf(line, "%[^,],%d,%[^,],%d,%f", title, &year, director, &genre,
			&rating);
	movie_init(source, title, year, director, genre, rating);
}

void read_movies(movie_array_struct *movies, FILE *fp) {
	char line[256];
	movies->capacity = MOVIES_INIT;
	movies->count = 0;

	while (fgets(line, sizeof(line), fp) && movies->count < movies->capacity) {
		read_movie(&(movies->items[movies->count]), line);
		movies->count++;
	}
}
