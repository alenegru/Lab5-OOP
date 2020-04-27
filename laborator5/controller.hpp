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
		//WatchList wlist;

	public:

		//for ADMIN
		void add_movie_to_repo();

		void remove_movie_from_repo();

		void update_movie_from_repo();

		//for USER



};




#endif /* controller_hpp */
