//
//  console.cpp
//  laborator5
//
//  Created by Alexandra Negru on 24/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "console.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>

using namespace std;

Console::Console()
{

}

Console::~Console()
{

}

void Console::menu()
{
	string type = ""; //user type
	validate v;

	cout << endl << "MENU" << endl << endl << "for 'USER MENU' press 1" << endl << "for 'ADMIN MENU' press 2" << endl << "for 'EXIT' press 0" << endl;
	cout << endl << "your choice is : ";

	cin >> type;

	while (type != "0")
	{
		if (type == "1")
		{
            user_menu(csv_html_menu());
		}
		else if (type == "2")
		{
			admin_menu();
		}
		else if (type == "0")
		{
			break;
		}
		else
		{
			cout << endl << "ERROR - wrong option" << endl << "hint: existing options are 0, 1 or 2" << endl;
		}
	}	
}

void Console::admin_menu()
{
	string choice = "none";

	cout << endl << "ADMIN MENU" << endl << endl;
	cout << "for 'ADD MOVIE' press 1\n" << "for 'REMOVE MOVIE' press 2\n" << "for 'UPDATE MOVIE' press 3\n" << "for 'EXIT ADMIN MENU' press 0\n";

	cout << endl << "your choice is : ";
	cin >> choice;

	while (choice >" ")
	{
		if (choice == "1")
		{
			controller.add_movie_to_repo();
		}
		else if (choice == "2")
		{
			controller.remove_movie_from_repo();
		}
		else if (choice == "3")
		{
			controller.update_movie_from_repo();
		}
		else if (choice == "0")
		{
			menu();
		}
		else
		{
			cout << endl << "ERROR - wrong option" << endl << "hint: existing options are 0, 1, 2 or 3" << endl;
		}

		cout << endl << "for 'ADD MOVIE' press 1\n" << "for 'REMOVE MOVIE' press 2\n" << "for 'UPDATE MOVIE' press 3\n" << "for 'EXIT ADMIN MENU' press 0\n";
		cout << endl << "your choice is : ";
		cin >> choice;
	}
}

void Console::user_menu(int choice) {
    cout << "\nUSER MENU\n\n1 - Show movies by genre\n2 - Delete movie from watchlist\n3 - See watchlist\nOption 0 - Exit\n";

    string option = " ";

    cout << "\nYour option: ";
    cin >> option;

    if (option == "1")
        controller.user_show_movies_by_genre();
    else if (option == "2")
        controller.user_delete_movie_from_watchlist();

	else if (option == "3")
	{
		controller.user_show_watchlist();
		if (choice == 2)
		{
			//OPEN HTML
			controller.create_and_open_html();
		}
		if (choice == 1)
		{
			//OPEN csv
		}
	}
       
    else if (option == "0")
        return;
    else
        cout << "\nInvalid option!\n";
    user_menu(csv_html_menu());
}

int Console::csv_html_menu()
{
	cout << "\nsave to CSV FILE or HTML FILE?\n" << "for CSV file press 1\nfor HTML file press 2\n";
	string option = " ";

	cout << "\nYour option: ";
	cin >> option;

	//CSV
	//if (option == "1")
		//return 1
		
	//else
	if (option == "2") //HTML
		return 2;
	else
		cout << "\nInvalid option!\n";

	csv_html_menu();


}
