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

void Repository::read_file(vector <Movie>& v, string file) {
    
    ifstream read_my_file;
   // string my_file = file;
    read_my_file.open(file.c_str());

    string title, genre, trailer;
    string year, numberOfLikes;
    char vec[100];
   
    while (!read_my_file.eof())
    {
        /*read_my_file >> title;
        cout << title << " ";
        read_my_file >> genre >> year >> numberOfLikes >> trailer;
        cout << genre << " ";
        if (title != "" || genre != "" || year != "" || numberOfLikes != "" || trailer != "")
        {
            Movie movie(title, genre, stoi(year), stoi(numberOfLikes), trailer);
            movies.push_back(movie);
        }
        else break;*/
        read_my_file >> vec;
        title = vec;
        read_my_file >> vec;
        genre = vec;
        read_my_file >> vec;
        year = stoi(vec);
        read_my_file >> vec;
        numberOfLikes = stoi(vec);
        read_my_file >> vec;
        trailer = vec;
        Movie movie(title, genre, stoi(year), stoi(numberOfLikes), trailer);
        movies.push_back(movie);
    }
    movies = v;
    cout << " ddd" << movies.size();
    print_movie_vector(v);
    read_my_file.close();
        /*  ifstream myReadFile;
    string filename = file;
    myReadFile.open(filename.c_str());

    string title;
    string genre;
    int year;
    int number_likes;
    string trailer;
   

    string temp;

    string::size_type sz;

    while (!myReadFile.eof())
    {
        Movie f;

        

        myReadFile >> title;
        if (title != "")
            f.set_title(title);

        myReadFile >> genre;
        if (genre != "")
            f.set_genre(genre);

        myReadFile >> temp;
        if (temp != "")
        {
            number_likes = stoi(temp, &sz);
            f.set_numberOfLikes(number_likes);
        }

        myReadFile >> temp;
        if (temp != "")
        {
            year = stoi(temp, &sz);
            f.set_year(year);
        }

        myReadFile >> trailer;
        if (trailer != "")
            f.set_trailer(trailer);

        if (title != "")
            v.push_back(f);

    }

    if (v.size() > 0)
        v.erase(v.end() - 1);
    print_movie_vector(v);
    myReadFile.close();*/
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
