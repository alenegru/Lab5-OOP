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
    wlist.get_watchlist();
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
		cout << "successfully removed" << endl;
	}
	else
	{
		cout << "ERROR - wrong data" << endl << "hint: id must be integer" << endl;
	}
}

void Controller::update_movie_from_repo()
{
	cout << endl << "Update movie from List: " << endl << endl;
	repo.print_movie_vector(repo.get_movies());
	cout << endl;

	validate v;
	int id;
	string id_test;
	cout << "id of movie to update: ";
	cin >> id_test;

	if (v.is_digit(id_test))
	{
		id = stoi(id_test);
		if (!repo.find_movie_by_id(id))
		{
			cout << "Movie ID does not exist" << endl;
		}
		else
		{
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
				repo.update_movie(id, title, genre, year, numberOfLikes, trailer);
				repo.print_movie_vector(repo.get_movies());
				cout << endl << "successfully updated" << endl;
			}
		}
	
	}
	else {
		cout << "ERROR - wrong data" << endl << "hint: id must be integer" << endl;
	}

	

}

void Controller::user_show_movies_by_genre() {
    cout << "\nShow movies by genre:";
    cout << "\nType genre: ";

    string genre;
    cin >> genre;

    vector <Movie> results = repo.show_movies(genre);

    cout << "\nFilms found:\n";
    
    for (int i = 0; i < results.size(); i++) {
        cout << "ID: " << results[i].get_id() << " Title: " << results[i].get_title() << " Genre: " << results[i].get_genre() <<
            " Year: " << results[i].get_year() << " Likes: " << results[i].get_number_of_likes() << "\n";
        repo.open_link(results[i].get_trailer());

        string answer;

        cout << "\nAdd to watchlist?\nY - yes, N - no\nAnswer: ";
        cin >> answer;

        if (answer == "y" or answer == "Y") {
			if (wlist.add_movie_to_watchlist(results[i].get_id()))
			{
				//repo.watchlist_html("movies_out.txt", wlist.get_watchlist());
				cout << "\nFilm successfully added to your watchlist!\n";
			}
            else
                cout << "\nSomething went wrong.";
        }
        
        if (i != results.size() - 1) {
            cout << "Watch another trailer?\nY - yes, N - no\nAnswer: ";
            string answer2;
            cin >> answer2;

            if (answer2 == "n" or answer2 == "N")
                break;
        }
    }
}

void Controller::user_delete_movie_from_watchlist() {
    cout << "\nRemove from watchlist\n";
    cout << "Your watchlist:\n";
    user_show_watchlist();

    int id;
    cout << "\nEnter ID: ";
    cin >> id;

    while (cin.fail()) {
        cout << "Error ID must be integer: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> id;
    }

    if (wlist.remove_movie_from_watchlist(id)) {
        cout << "\nFilm removed from watchlist successfully!\n";
        
        string like;

        cout << "Like?\nY - yes, N - no\nAnswer: ";
        cin >> like;

        if (like == "Y" or like == "y") {
            for (int i = 0; i < repo.get_movies().size(); i++)
                if (repo.get_movies()[i].get_id() == id) {
                    repo.get_movies()[i].set_numberOfLikes(repo.get_movies()[i].get_number_of_likes() + 1);
                    cout << "\nLiked!";
                }
        }
    } else cout << "\nSomething went wrong.\n";
}

void Controller::user_show_watchlist()
{
    cout << "\nWatchlist:";
    vector <Movie> movies;
    for (int i = 0; i < wlist.get_watchlist().size(); i++) {
        Movie movie = repo.get_movie_by_id(wlist.get_watchlist()[i]);
        movies.push_back(movie);
    }
	repo.watchlist_html("view_html.html", wlist.get_watchlist());

	
	repo.open_link("view_html.html");

    for (int i = 0; i < movies.size(); i++)
        cout << "ID: " << movies[i].get_id() <<"Title: " << movies[i].get_title() << " Genre: " << movies[i].get_genre() <<
            " Year: " << movies[i].get_year() << " Likes: " << movies[i].get_number_of_likes() << "\n";
}

