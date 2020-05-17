//
//  htmlBuilder.hpp
//  laborator5
//
//  Created by Alexandra Negru on 16/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef htmlBuilder_hpp
#define htmlBuilder_hpp

#include "WatchlistBuilder.hpp"
#include <stdio.h>

class HTMLBuilder : public WatchlistBuilder {
public:
    void build_watchlist(vector <int> watchlist, Repository &repo);
};

#endif /* htmlBuilder_hpp */
