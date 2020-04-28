//
//  validate.cpp
//  laborator5
//
//  Created by Alexandra Negru on 28/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include <stdio.h>
#include "repository.hpp"
#include "validate.hpp"
#include "watchlist.hpp"

bool validate::validate_unique_repo(int id_, Repository& repo) {
    //checks if the film already exists
    if (repo.find_movie_by_id(id_) == true)
        return false;
    return true;
}

bool validate::validate_unique_wlist(int id_, Watchlist& watchlist) {
    //checks if the film already exists
    if (watchlist.find_movie_by_id(id_) == true)
        return false;
    return true;
}
