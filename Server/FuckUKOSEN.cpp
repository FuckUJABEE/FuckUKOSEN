#define DEBUG
#define CONNECT_DEBUG

#include"Save.h"
#include"Search.h"
#include"Connect.h"

#include<iostream>

int main()
{
	enum MODE { UNDEF = -1, SEARCH = 0, REGISTER = 1};

	int inputMode;
	MODE mode = UNDEF;
	Search search;
	Save save;
	Connect connect;

//		while (true){

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
//	}
	return 0;
}