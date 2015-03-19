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
	int resultNum;	// �����Ɉ�������������
	std::string searchString;	// �������镶����
	std::string fileNameCSV;
	std::vector<ResponceSet> responceSet;

	bool searchFromCSV();
	bool responceToTerminal();	// ���[�U�[�Ɍ������ʂ�Ԃ�

public:
	void getSearchString(const std::string&);		// ���[�U�[���猟�����镶������󂯎��

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