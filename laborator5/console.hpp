//
//  console.hpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef console_hpp
#define console_hpp

#include <stdio.h>
#include <iostream>
#include "controller.hpp"

using namespace std;

class Console
{
	private:

		Controller controller;
	
	public:

		Console();
		~Console();

        //main menu
		void menu();

        //menu for admin side
		void admin_menu();

        //menu for client side
		void user_menu();
};

#endif /* console_hpp */
