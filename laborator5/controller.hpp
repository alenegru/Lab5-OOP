//
//  controller.hpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef controller_hpp
#define controller_hpp

#include <stdio.h>
#include "repository.hpp"
#include "watchlist.hpp"

using namespace std;

class Controller
{
	private:
		Repository repo;
		Watchlist wlist;

	public:

		Controller();
		~Controller();

		//for ADMIN
		void add_movie_to_repo();

		void remove_movie_from_repo();

		void update_movie_from_repo();

		//for USER
    //Show movies based on genre
    void user_show_movies_by_genre();
    
    //Deletes movie from watchlist
    void user_delete_movie_from_watchlist();
    
    //Shows watchlist
    void user_show_watchlist();

	//if user wants to save data to html file
	void create_and_open_html();

	//for csv



};

#endif /* controller_hpp */
