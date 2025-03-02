

#include <iostream>
#include <map>
#include <string>
#define MAIN_MENU 48
#define CREATE_CONTACT 49
#define DELETE_CONTACT 50
#define SEARCH_CONTACT 51
#define CONTACTS_OUT 52

#define TRUE 1
#define FALSE 0

#define STR_EQUAL 0



void main(void)
{
	//declaire phone book as STL-container std::map
	std::map <std::string, std::string> phone_book;
	char stage_pointer;
	char Stage = MAIN_MENU;
	std::string tmp_line;
	while (1)
	{
		switch (Stage)
		{
			case MAIN_MENU: //Out main menu choice
				//Print all options of main menu
				//Ask user to enter what number of option user want to chose
				std::cout << "1. Create new contact" << std::endl;
				std::cout << "2. Delete contact" << std::endl;
				std::cout << "3. Search contact" << std::endl;
				std::cout << "4. Show all contacts" << std::endl;
				std::cout << "Enter number of option you want to choose:" << std::endl;
				std::cin >> stage_pointer;
				switch (stage_pointer)
				{
					case MAIN_MENU :
						Stage = MAIN_MENU;
						break;
					case CREATE_CONTACT:
						Stage = CREATE_CONTACT;
						break;
					case DELETE_CONTACT:
						Stage = DELETE_CONTACT;
						break;
					case SEARCH_CONTACT:
						Stage = SEARCH_CONTACT;
						break;
					case CONTACTS_OUT:
						Stage = CONTACTS_OUT;
						break;
					default:
						std::cout << "Not an available option number" << std::endl;
						break;
						
				}
				break;
			case CREATE_CONTACT:
				std::cout << "Enter name of new contact:" << std::endl;
				std::cin >> tmp_line;
				std::cout << "Enter number of new contact:" << std::endl;
				std::cin>>phone_book[tmp_line];
				Stage = MAIN_MENU;
				break;
			case DELETE_CONTACT:
				std::cout << "Enter name of contact to delete:" << std::endl;
				std::cin >> tmp_line;
				if (phone_book.count(tmp_line) == TRUE)
				{
					phone_book.erase(tmp_line);
				}
				else
				{
					std::cout << "Phone book hasn't contact with the name" << std::endl;
				}
				Stage = MAIN_MENU;
				break;
			case SEARCH_CONTACT:
				std::cout << "Enter name to search:" << std::endl;
				std::cin >> tmp_line;
				if (phone_book.count(tmp_line) == TRUE)
				{
					std::cout << tmp_line << "\t" << phone_book[tmp_line] << std::endl;
				}
				else
				{
					std::cout << "Phone book hasn't contact with the name" << std::endl;
				}
				Stage = MAIN_MENU;
				break;
			case CONTACTS_OUT:
				for (const auto& contact : phone_book)
				{
					std::cout << contact.first << "\t" << contact.second << std::endl;
				}
				Stage = MAIN_MENU;
				break;
		}
	}
}