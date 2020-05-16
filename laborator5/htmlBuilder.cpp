//
//  htmlBuilder.cpp
//  laborator5
//
//  Created by Alexandra Negru on 16/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "htmlBuilder.hpp"

void HTMLBuilder::watchlist_builder(vector <int> watchlist, Repository &repo) {
    ofstream fout;
    fout.open("view_html.html");

    fout << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border =";
    fout << "'1'";
    fout << "> \n<tr>\n<td>Titel</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer link </td>\n";

    for (int i = 0; i < watchlist.size(); i++) {
        Movie m = repo.get_movie_by_id(watchlist[i]);
        fout << "</tr>\n<tr>\n<td>" << m.get_title() << "</td>\n<td>" << m.get_genre() << "</td>\n<td>";
        fout << m.get_year()<<"</td>\n<td>"<<m.get_number_of_likes()<<"</td>\n<td><a href = '"<<m.get_trailer()<<"'>Link</a></td>\n";
    }
    fout << "</tr>\n</table>\n</body>\n</html>";
    fout.close();
}
