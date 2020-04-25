//
//  repository.hpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef repository_hpp
#define repository_hpp

#include <stdio.h>
#include <vector>
#include "movie.hpp"
using namespace std;

class Repository {
private:
    vector <Movie> movies;
public:
    //constructor
    Repository();
    
    //destructor
    ~Repository();
    
    //returns the movies
    vector <Movie> get_movies() { return movies; }
    
    //adds a movie in repo
    bool add_movie(string title_, string genre_, string year_, string trailer_);

    //removes movie from repo
    bool remove_movie(int id_);

    //updates a movie's data
    bool update_movie(int id_, string title_, string genre_, string year_, string trailer_);

    //shows movies based on genre
    vector <Movie> show_movies(string genre_);

    //opens trailer in browser
    void open_link(string link_);

    //reading file
    void read_file(vector <Movie>& v, string file);
    
    //writing in file
    void write_file(vector <Movie> v, string file);
};

#endif /* repository_hpp */
