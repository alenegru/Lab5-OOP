//
//  repository.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "repository.hpp"
#include "validate.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
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

Movie Repository::get_movie_by_id(int id_) {
    Movie empty_film;
    for (int i = 0; i < movies.size(); i++)
        if (movies[i].get_id() == id_)
            return movies[i];
   // throw Exception("No movie with this id");
    return empty_film;
}

bool Repository::find_movie_by_id(int id_) {
    for (int i = 0; i < movies.size(); i++)
        if (movies[i].get_id() == id_)
            return true;
   // throw Exception("No movie with this id");
    return false;
}

void dublicate_file(string str1, string str2)
{
    ofstream fout;
    fout.open(str2, ofstream::out | ofstream::trunc);
    string s;
    ifstream file(str1);
    while (getline(file, s))
    {
        fout << s << endl;
    }
}

void Repository::watchlist_html(string file, vector<int> wlist)
{
    ofstream fout;
    fout.open(file, ofstream::out | ofstream::trunc);

    fout << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border =";
    fout << "'1'";
    fout << "> \n<tr>\n<td>Titel</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer link </td>\n";

    for (int i = 0; i < wlist.size(); i++)
    {
        Movie m = get_movie_by_id(wlist[i]);
        fout << "</tr>\n<tr>\n<td>" << m.get_title() << "</td>\n<td>" << m.get_genre() << "</td>\n<td>";
        fout << m.get_year()<<"</td>\n<td>"<<m.get_number_of_likes()<<"</td>\n<td><a href = '"<<m.get_trailer()<<"'>Link</a></td>\n";
    }

    fout << "</tr>\n</table>\n</body>\n</html>";

    fout.close();
}