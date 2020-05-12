//
//  main.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "console.hpp"
#include "controller.hpp"
#include "movie.hpp"
#include "Tests.hpp"
#include "repository.hpp"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shellapi.h>
#include <vector>

//using namespace std;

int main() {

    Test_Movie();
    Test_Repository();
    Test_Validate();

    /*
    Repository repo;
    vector<Movie> movies,mo;
    Movie m("supermanVSbatman", "action", 2017, 12, "https://youtu.be/0WWzgGyAH6Y");
    repo.add_movie("supermanVSbatman", "action", "2017", "https://youtu.be/0WWzgGyAH6Y");
  
    repo.update_movie(41, "supermanVSbatman", "action", "2017", "90", "https://youtu.be/0WWzgGyAH6Y");
    
    repo.print_movie_vector(repo.show_movies("action"));
    //repo.open_link(m.get_trailer());
    repo.write_file(repo.get_movies(), "movies_out.txt");
    repo.remove_movie(67);
    repo.print_movie_vector(repo.show_movies("action"));

    repo.create_movies();
    repo.print_movie_vector(repo.show_movies("horror"));

    repo.print_movie_vector(repo.get_movies());
    */

  
    //

    //string s = "file:///C:/Users/laura/Laburi%20OOP/Lab5-OOP/laborator5/view_html.html";

    //ShellExecute(0, 0, L , 0, 0, SW_SHOW);

    Controller ctrl;
    Console cons;
    cons.menu();
    return 0;
}
