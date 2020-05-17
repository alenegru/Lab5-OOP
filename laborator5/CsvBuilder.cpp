//
//  CsvBuilder.cpp
//  laborator5
//
//  Created by Alexandra Negru on 16/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "CsvBuilder.hpp"
#include <fstream>

using namespace std;

void CsvBuilder::build_watchlist(vector <int> watchlist, Repository &repo) {
    ofstream fout;
    fout.open("watchlist.csv");

    fout << "#,Title,Genre,Year,Likes,Trailer\n";

    for (int i = 0; i < watchlist.size(); i++) {
        Movie movie = repo.get_movie_by_id(watchlist[i]);
        fout << i + 1 << "," << movie.get_title() << "," << movie.get_genre() << "," << movie.get_year() << "," << movie.get_number_of_likes() << "," << movie.get_trailer() << '\n';
    }
    
    fout.close();
}
