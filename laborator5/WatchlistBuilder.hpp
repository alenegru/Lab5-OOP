//
//  WatchlistBuilder.hpp
//  laborator5
//
//  Created by Alexandra Negru on 16/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef WatchlistBuilder_hpp
#define WatchlistBuilder_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include "repository.hpp"
#include "movie.hpp"

class WatchlistBuilder {
public:
    virtual void build_watchlist(vector <int> watchlist, Repository& repo);
};

#endif /* WatchlistBuilder_hpp */
