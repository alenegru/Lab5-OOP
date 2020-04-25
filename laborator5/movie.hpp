//
//  movie.hpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef movie_hpp
#define movie_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    int year;
    int numberOfLikes;
    string trailer;
public:
    //constructors
    Movie();
    Movie(string title, string genre, int year, int numberOfLikes, string trailer);
    
    //getters
    string get_title() { return title; }
    string get_genre() { return genre; }
    int get_year() { return year; }
    int get_number_of_likes() { return numberOfLikes; }
    string get_trailer() { return trailer; }
    
    //setters
    void set_title(string t) { title = t; }
    void set_genre(string g) { genre = g;}
    void set_year(int y) { year = y; }
    void set_numberOfLikes(int nrlikes) { numberOfLikes = nrlikes; }
    void set_trailer(string tr) { trailer = tr; }
    
    //destructor
    ~Movie();
};

#endif /* movie_hpp */
