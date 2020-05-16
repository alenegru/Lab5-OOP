//
//  watchlist.cpp
//  laborator5
//
//  Created by Alexandra Negru on 26/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "watchlist.hpp"
#include "repository.hpp"
#include "validate.hpp"
#include <iostream>
#include <fstream>
using namespace std;

bool Watchlist::remove_movie_from_watchlist(int id_) {
    if (isEmpty() == false)
        for (int i = 0; i < watchlist.size(); i++)
            if (watchlist[i] == id_) {
                watchlist.erase(watchlist.begin() + i);
                return true;
            }
    return false;
}

//adds movie to watchlist
bool Watchlist::add_movie_to_watchlist(int id_) {
    validate v;

    if (!(v.validate_unique_wlist(id_, *this)))
        //movie exists already
        return false;
    else
        watchlist.push_back(id_);
    return true;
}

bool Watchlist::isEmpty() {
    if (watchlist.empty())
        return true;
    return false;
}

bool Watchlist::find_movie_by_id(int id_) {
    for (int i = 0; i < watchlist.size(); i++)
        if (watchlist[i] == id_)
            return true;
    return false;
}
