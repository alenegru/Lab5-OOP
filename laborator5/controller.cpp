//
//  controller.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "controller.hpp"
#include <iostream>
#include <string>
#include "validate.hpp"

using namespace std;

Controller::~Controller()
{

}

Controller::Controller()
{
	repo.create_movies();
	//for watchlist remaining
}

void Controller::add_movie_to_repo()
{
	cout << endl << "Add movie to List: " << endl << endl;

	string title, genre, year, trailer;
	cout << "title: ";
	cin >> title;
	cout << endl << "genre: ";
	cin >> genre;
	cout << endl << "year: ";
	cin >> year;
	cout << endl << "trailer: ";
	cin >> trailer;

	validate v;

	if (v.is_string(title) && v.is_string(genre) && v.is_digit(year) && v.is_string(trailer))
	{
		repo.add_movie(title, genre, year, trailer);
		repo.print_movie_vector(repo.get_movies());
		cout << "successfully added" << endl;
	}
	else
	{
		cout << "ERROR - wrong data" << endl << "hint: try giving digits for year" << endl;
	}
	
}

void Controller::remove_movie_from_repo()
{
	cout << endl << "Remove movie from List: " << endl << endl;

	cout << "List of movies: " << endl;
	repo.print_movie_vector(repo.get_movies());

	validate v;
	int id;
	string id_test;
	cout << "id of movie to remove: ";
	cin >> id_test;

	if (v.is_digit(id_test))
	{
		id = stoi(id_test);
		repo.remove_movie(id);
	}
	else
	{
		cout << "ERROR - wrong data" << endl << "hint: id must be integer" << endl;
	}
}

void Controller::update_movie_from_repo()
{
	cout << endl << "Update movie from List: " << endl << endl;

	validate v;
	int id;
	string id_test;
	cout << "id of movie to update: ";
	cin >> id_test;

	string title, genre, year, numberOfLikes, trailer; 

	cout << "give new data: " << endl; 

	cout << "title: ";
	cin >> title;
	cout << endl << "genre: ";
	cin >> genre;
	cout << endl << "year: ";
	cin >> year;
	cout << endl << "numberOfLikes: ";
	cin >> numberOfLikes;
	cout << endl << "trailer: ";
	cin >> trailer;

	if (v.is_digit(id_test) && v.is_string(title) && v.is_string(genre) && v.is_digit(year) && v.is_digit(numberOfLikes) && v.is_string(trailer))
	{
		id = stoi(id_test);
		repo.update_movie(id,title,genre,year,numberOfLikes,trailer);
	}
	else
	{
		cout << "ERROR - wrong data" << endl << "hint: id must be integer" << endl;
	}

}

