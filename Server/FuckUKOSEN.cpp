#include"Save.h"
#include"Search.h"
#include"Connect.h"

#include<iostream>

int main()
{
	enum MODE { UNDEF = -1, SEARCH = 0, REGISTER = 1};

	int conectionCount = 0;
	int inputMode;
	MODE mode = UNDEF;
	Search search;
	Save save;

		while (true){
			std::cout << std::endl;
			std::cout << "ConectionCount : " << ++conectionCount << std::endl;
			Connect connect;
			inputMode = connect.GetMode();

			switch (inputMode){
			case 0:
				mode = MODE::SEARCH;
				break;
			case 1:
				mode = MODE::REGISTER;
				break;
			default:
				mode = MODE::UNDEF;
				break;
			}

			switch (mode){
				std::cout << "FuckUKOSEN" << std::endl;

			case MODE::SEARCH:
				std::cout << "Search Mode" << std::endl;
				search = Search("save.csv");
				search.getSearchString(connect.GetSearchString());
				search.searchMain(connect.getClient());
				break;

			case MODE::REGISTER:
				std::cout << "Register Mode" << std::endl;
				save = Save();
				save.GetUserInput(connect.GetUserInput());
				save.SaveMain(connect.getClient());
				break;

			case MODE::UNDEF:
				std::cout << "Undefine Mode" << std::endl;
		}
	}
	return 0;
}