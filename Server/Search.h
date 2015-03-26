#pragma once

#include<string>
#include<vector>
#include<WinSock2.h>
#include<cstdio>
#include<cstdlib>

struct ResponceSet{
	std::string URL;
	std::string name;

	ResponceSet(){
		URL = "null";
		name = "null";
	}

	ResponceSet(const std::string& _URL, const std::string& _name){
		URL = _URL;
		name = _name;
	}
};

class Search{
private:

	std::string searchString;	// 検索する文字列
	std::string fileNameCSV;
	std::vector<ResponceSet> responceSet;
	std::string responceHTML;

	bool searchFromCSV();
	bool responceToTerminal(SOCKET);	// ユーザーに検索結果を返す

public:
	void getSearchString(const std::string&);		// ユーザーから検索する文字列を受け取る

	void searchMain(SOCKET client){
		searchFromCSV();
		responceToTerminal(client);
	}

	Search(){
		fileNameCSV = "null";
	}

	Search(const std::string& _fileNameCSV){
		fileNameCSV = _fileNameCSV;
	}
};