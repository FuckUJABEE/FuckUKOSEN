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

	std::string searchString;	// �������镶����
	std::string fileNameCSV;
	std::vector<ResponceSet> responceSet;
	std::string responceHTML;

	bool searchFromCSV();
	bool responceToTerminal(SOCKET);	// ���[�U�[�Ɍ������ʂ�Ԃ�

public:
	void getSearchString(const std::string&);		// ���[�U�[���猟�����镶������󂯎��

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