//
//  watchlist.hpp
//  laborator5
//
//  Created by Alexandra Negru on 26/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef watchlist_hpp
#define watchlist_hpp

#include <stdio.h>
#include <vector>
#include "movie.hpp"
using namespace std;

class Watchlist {
private:
    vector <int> watchlist;
public:
    //getter
    vector<int>& get_watchlist() { return watchlist; }
    
    bool isEmpty();
    //checks if movie exists in watchlist
    bool find_movie_by_id(int id_);
    
    //removes movie from watchlist
    bool remove_movie_from_watchlist(int id_);
    
    //adds movie to watchlist
    bool add_movie_to_watchlist(int id_);
    
};

#endif /* watchlist_hpp */
