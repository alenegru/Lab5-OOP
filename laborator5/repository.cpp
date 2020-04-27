//
//  repository.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "repository.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Repository::Repository() {}

Repository::~Repository() {}

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

void Repository::print_movie_vector(vector <Movie> movies_)
{
   // cout << movies.size();
    for (int i = 0; i < movies_.size(); i++)
        cout << "id: " << movies_[i].get_id() << ", title: " << movies_[i].get_title() << ", genre: " << movies_[i].get_genre() <<
        " Year: " << movies_[i].get_year() << ", likes: " << movies_[i].get_number_of_likes() << "\n";
}

bool Repository::add_movie(string title_, string genre_, string year_, string trailer_) {

    int year = 0;
    if (!isNumber(year_)) return false;
    else  year = stoi(year_);

    Movie new_movie(title_ , genre_, year,0, trailer_);

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

    return false;
}

bool Repository::update_movie(int id_, string title_, string genre_, string year_, string numberOfLikes_, string trailer_) {

    int _year = 0, _numberOfLikes = 0;
    if (!isNumber(year_) || !isNumber(numberOfLikes_)) return false;
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
    else  return movies_genre;


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

void Repository::write_file(vector <Movie> v, string file) {
    
    ofstream write_my_file;
    write_my_file.open(file, ofstream::out | ofstream::trunc);

    for (int i = 0; i < v.size(); i++)
    {
        write_my_file << v[i].get_id() << " " << v[i].get_title() << " " << v[i].get_genre() << " " << v[i].get_year() << " " << v[i].get_number_of_likes() <<
            " " << v[i].get_trailer() << '\n';

    }
    write_my_file.close();

}
