//
//  movie.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "movie.hpp"
#include <string>

Movie::Movie(string t, string g, int y, int nrOfLikes, string tr) {
    title = t;
    genre = g;
    year = y;
    numberOfLikes = nrOfLikes;
    trailer = tr;
}

Movie::~Movie() {}
