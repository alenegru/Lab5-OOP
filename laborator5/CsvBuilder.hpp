//
//  CsvBuilder.hpp
//  laborator5
//
//  Created by Alexandra Negru on 16/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef CsvBuilder_hpp
#define CsvBuilder_hpp

#include <stdio.h>
#include "WatchlistBuilder.hpp"

class CsvBuilder : public WatchlistBuilder {
public:
    void build_watchlist(vector <int> watchlist, Repository &repo);
};

#endif /* CsvBuilder_hpp */
