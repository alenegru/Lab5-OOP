#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "movie.hpp"
#include "repository.hpp"

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

		//bool is_unique(int);
};