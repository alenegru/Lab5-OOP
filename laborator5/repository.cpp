//
//  repository.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "movie.hpp"
#include "repository.hpp"
#include "validate.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Exception.hpp"
using namespace std;

Repository::Repository() {}

Repository::~Repository() {}


void Repository::print_movie_vector(vector <Movie> movies_)
{
    // cout << movies.size();
   // if (movies_.size() == 0)
   // {
        //throw Exception("None existing movies");
   // }

    for (int i = 0; i < movies_.size(); i++)
        cout << "id: " << movies_[i].get_id() << ", title: " << movies_[i].get_title() << ", genre: " << movies_[i].get_genre() <<
        " Year: " << movies_[i].get_year() << ", likes: " << movies_[i].get_number_of_likes() << "\n";
    
   
}

bool Repository::add_movie(string title_, string genre_, string year_, string trailer_) {

    validate v;
    int year = 0;
    if (!v.is_digit(year_))
    {
       // throw Exception("Year must be digit");
        return false;
    }

    else  year = stoi(year_);

    if (!v.is_string(title_) || !v.is_string(genre_) || !v.is_string(trailer_))
        return false;

    Movie new_movie(title_ , genre_, year, 0, trailer_);

    movies.push_back(new_movie);

    return true;
}

bool Repository::remove_movie(int id_) {

    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].get_id() == id_)
        {
            movies.erase(movies.begin() + i);
            return true;
        }
    }
    //throw Exception("Movie not removed");
    return false;
}

bool Repository::update_movie(int id_, string title_, string genre_, string year_, string numberOfLikes_, string trailer_) {

    validate v;
    int _year = 0, _numberOfLikes = 0;
    if (!v.is_digit(year_) || !v.is_digit(numberOfLikes_))
    {
        //throw Exception("Year and Number of Likes must be digit");
        return false;
    }
        
    if (!v.is_string(title_) || !v.is_string(genre_) || !v.is_string(trailer_))
       return false;
    else 
    {
        _year = stoi(year_);
        _numberOfLikes = stoi(numberOfLikes_);
    }

    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].get_id() == id_)
        {
            movies[i].set_title(title_);
            movies[i].set_genre(genre_);
            movies[i].set_year(_year);
            movies[i].set_numberOfLikes(_numberOfLikes);
            movies[i].set_trailer(trailer_);

            return true;
        }
    }
    //throw Exception("Movie was not updated");
    return false;
}

vector <Movie> Repository:: show_movies(string genre_) {
  
    vector <Movie> movies_genre;
    if (!get_movies().empty())
    {
        for (int i = 0; i < movies.size(); i++)
        {
            if (genre_ == get_movies()[i].get_genre())
            {
                movies_genre.push_back(get_movies()[i]);
            }

        }

        if (!movies_genre.empty())
            return movies_genre;
        else get_movies();
    }
    
    return movies_genre;


}

void Repository::open_link(string link_) {
    
    system(string("cmd /c start " + link_).c_str());
}

void Repository::create_movies() {

    add_movie("JurrasicWorld", "action", "2015", "https://youtu.be/RFinNxS5KN4");
    add_movie("Thor:Ragnarok ", "action", "2017", "https://youtu.be/ue80QwXMRHg");
    add_movie("Avengers:Endgame ", "adventure", "2019", "https://youtu.be/TcMBFSGVi1c");
    add_movie("Psycho ", "horror", "1960", "https://youtu.be/Wz719b9QUqY");
    add_movie("Us ", "horror", "2019", "https://youtu.be/1tzFRIQfwXg");
    add_movie("Titanic", "romantic", "1997", "https://youtu.be/2e-eXJ6HgkQ");
    add_movie("Superbad", "comedy", "2007", "https://youtu.be/4eaZ_48ZYog");
    add_movie("TheNotebook", "romantic", "2004", "https://youtu.be/yDJIcYE32NU");
    add_movie("Borat", "comedy", "2006", "https://youtu.be/vlnUa_dNsRQ");
    add_movie("Neighbors", "comedy", "2014", "https://youtu.be/kL5c2szf3E4");

}

void Repository::read_file(vector <Movie>& v, string file) {
    ifstream myReadFile;
    string filename = file;
    myReadFile.open(filename.c_str());

    string title;
    string genre;
    int year;
    int number_likes;
    string trailer;
    int id;

    string temp;

    string::size_type sz;

    while (!myReadFile.eof()) {
        char text[1000];
        myReadFile.getline(text,1000);
        
        string line = text;

        if (line == "")
            break;
        
        vector <int> indexes;
        vector <string> elements;
        string word;

        for (int i = 0; i < line.length(); i++)
            if (line[i] == '|')
                indexes.push_back(i);
   
        int j = 0;
        while (j < indexes.size() - 1) {
            for (int i = indexes[j] + 1; i < indexes[j + 1]; i++)
                word += line[i];
            elements.push_back(word);
            word = "";
            j++;
        }
        id = stoi(elements[0], &sz);
        number_likes = stoi(elements[4], &sz);
        year = stoi(elements[3], &sz);
        Movie f(id, elements[1], elements[2], year, number_likes, elements[5]);
        v.push_back(f);
    }
    myReadFile.close();
}

void Repository::write_file(vector<Movie> v, string filename) {
    ofstream fin;
    fin.open(filename, ofstream::out | ofstream::trunc);

    for (int i = 0; i < v.size(); i++)
        fin << "|" << v[i].get_id() << "|" << v[i].get_title() << "|" << v[i].get_genre() << "|" << v[i].get_number_of_likes() << "|" << v[i].get_year() <<
        "|" << v[i].get_trailer() << "|\n";

    fin.close();
}

Movie Repository::get_movie_by_id(int id_) {
    Movie empty_film;
    for (int i = 0; i < movies.size(); i++)
        if (movies[i].get_id() == id_)
            return movies[i];
    throw Exception("No movie with this id");
    return empty_film;
}

bool Repository::find_movie_by_id(int id_) {
    for (int i = 0; i < movies.size(); i++)
        if (movies[i].get_id() == id_)
            return true;
    throw Exception("No movie with this id");
    return false;
}
