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
#include "Exception.hpp"
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

    //sets movies
    void set_movies(vector <Movie> m) { movies = m; }

    //prints a movie vector
    void print_movie_vector(vector <Movie> movies_);
    
    //adds a movie in repos
    bool add_movie(string title_, string genre_, string year_, string trailer_);
    
    //removes movie from repo
    bool remove_movie(int id_);

    //updates a movie's data
    bool update_movie(int id_, string title_, string genre_, string year_, string numberOfLikes, string trailer_);

    //shows movies based on genre
    vector <Movie> show_movies(string genre_);

    //opens trailer in browser
    void open_link(string link_);

    //reading file
    void create_movies();
    
    //writing in file
    void write_file(vector <Movie> v, string file);
    
    Movie get_movie_by_id(int id_);
    
    bool find_movie_by_id(int id_);
};

#endif /* repository_hpp */
