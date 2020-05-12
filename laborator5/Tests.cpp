#include "console.hpp"
#include "controller.hpp"
#include "movie.hpp"
#include "repository.hpp"
#include "validate.hpp"
#include "Tests.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <assert.h>

using namespace std;

void Test_Movie()
{
	Movie movie("movie", "gen", 1999, 12, "trailer");
	assert(movie.get_genre() == "gen");
	assert(movie.get_number_of_likes() == 12 );
	movie.set_genre("gen2");
	movie.set_year(2000);
	assert(movie.get_year() == 2000);
	assert(movie.get_genre() == "gen2");
	assert(movie.get_title() == "movie");
	assert(movie.get_trailer() == "trailer");
	movie.set_trailer("trailer2");
	assert(movie.get_trailer() == "trailer2");

	cout << "Finished Movie Test\n";
}

void Test_Repository()
{
	Movie movie("movie", "gen", 1999, 12, "trailer");
	Movie movie2("movie2", "gen2", 2002, 1, "trailer2");
	Repository repo;

	cout << movie.get_id() << " " << movie2.get_id() << endl;

	//add movies
	assert(repo.add_movie("movie", "gen", "1999", "trailer"));
	assert(repo.add_movie("movie2", "gen2", "2002", "trailer2"));

	assert(repo.get_movies().size() == 2);

	
	assert(repo.get_movies()[0].get_title() == movie.get_title());
	assert(repo.get_movies()[1].get_genre() == movie2.get_genre());

	//update movie
	assert(repo.update_movie(repo.get_movies()[0].get_id(), "new_title", "gen", "2000", "12", "trailer"));

	assert(repo.get_movies()[0].get_title() == "new_title");
	assert(repo.get_movies()[0].get_genre() == movie.get_genre());
	assert(repo.get_movies()[0].get_number_of_likes() == movie.get_number_of_likes());


	//remove movie
	assert(repo.remove_movie(repo.get_movies()[1].get_id()));
	assert(repo.get_movies().size() == 1);

	assert(repo.remove_movie(repo.get_movies()[0].get_id()));
	assert(repo.get_movies().size() == 0);


	cout << "Finished Repository Test\n";
}

void Test_Validate()
{
	validate v;
	assert(v.is_digit("123") == true);
	assert(v.is_digit("0") == true);
	assert(v.is_digit("123g") == false);
	assert(v.is_digit("string") == false);

	assert(v.is_string("123") == true);
	assert(v.is_string("123g") == true);
	assert(v.is_string("string") == true);

	cout << "Finished Validate Test\n";
}