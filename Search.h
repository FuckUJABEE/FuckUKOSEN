#pragma once

#include<string>
#include<vector>

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
	int resultNum;	// 検索に引っかかった数
	std::string searchString;	// 検索する文字列
	std::string fileNameCSV;
	std::vector<ResponceSet> responceSet;

	bool searchFromCSV();
	bool responceToTerminal();	// ユーザーに検索結果を返す

public:
	void getSearchString(const std::string&);		// ユーザーから検索する文字列を受け取る

	void searchMain(){
		searchFromCSV();
		responceToTerminal();
	}

	Search(){
		resultNum = 0;
		fileNameCSV = "null";
	}

	Search(const std::string& _fileNameCSV){
		resultNum = 0;
		fileNameCSV = _fileNameCSV;
	}
};