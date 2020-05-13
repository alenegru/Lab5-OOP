//
//  movie.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "movie.hpp"
#include <string>

Movie::Movie() {
    
}

Movie::Movie(string title_, string genre_, int year_, int numberOfLikes_, string trailer_) {
    title = title_;
    genre = genre_;
    year = year_;
    numberOfLikes = numberOfLikes_;
    trailer = trailer_;
}

Movie::Movie(int id_, string title_, string genre_, int year_, int numberOfLikes_, string trailer_) {
    id = id_;
    title = title_;
    genre = genre_;
    year = year_;
    numberOfLikes = numberOfLikes_;
    trailer = trailer_;
}

Movie::~Movie() {}
