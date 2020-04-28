#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "movie.hpp"
#include "repository.hpp"
#include "watchlist.hpp"

using namespace std;

class validate
{
	public:
		bool is_string(string str)
		{
			return true;
		};
		bool is_digit(string str)
		{
			for (int i = 0; i < str.length(); i++)
				if (isdigit(str[i]) == false)
					return false;
			return true;
		};
    //checks for movie in repo
    bool validate_unique_repo(int id_, Repository& repo);
    //checks for movie in watchlist
    bool validate_unique_wlist(int id_, Watchlist& watchlist);
		//bool is_unique(int);
};
