#define DEBUG

#include"Save.h"
#include"Search.h"

#include<iostream>

int main()
{
	enum MODE {UNDEF = -1, SEARCH = 0 , REGISTER};

	int inputMode;
	MODE mode = UNDEF;

	Search search;
	Save save;

#ifdef DEBUG
	std::cout << std::endl;
	std::cout << "DEBUG MODE" << std::endl;
	std::cout << std::endl;
	std::cout << "Search : 0" << std::endl;
	std::cout << "Register : 1" << std::endl;
	std::cout << std::endl;
	std::cout << ">> ";
	std::cin >> inputMode;
#endif

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
	case MODE::SEARCH:
		search = Search("save.csv");
		search.getSearchString("àÔèÈ");
		search.searchMain();
		break;

	case MODE::REGISTER:
		save = Save();
		save.GetUserInput("àÔèÈçÇêÍ3", "http://www.google.com", 114.514, 810.931);
		save.SaveMain();
		break;

	case MODE::UNDEF:
		std::cout << "Mode is undefined" << std::endl;
	}
	return 0;
}