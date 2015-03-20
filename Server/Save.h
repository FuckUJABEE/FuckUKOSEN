#pragma once
#include<string>
#include <winsock2.h>

struct SaveData{
	std::string registerString;
	std::string URL;
	double position[2];

	SaveData(){
		registerString = "null";
		URL = "null";
		for (int i = 0; i < 2; ++i)
			position[i] = 0;
	};

	SaveData(const std::string& _registerString, const std::string& _URL, const double& _position0, const double& _position1){
		registerString = _registerString;
		URL = _URL;
		position[0] = _position0;
		position[1] = _position1;
	};

	SaveData(SaveData& _saveData){
		registerString = _saveData.registerString;
		URL = _saveData.URL;

		for (int i = 0; i < 2;++i)
			position[i] = _saveData.position[i];

	}
};


class Save{
private:
	std::string fileNameCSV;
	std::string answerString;
	SaveData saveData;

	bool SaveToCSV();
	bool MakeHTML();

	bool ThrowToTerminal(SOCKET);

public:
	Save(){
		fileNameCSV = "save.csv";
	}

	void GetUserInput(const std::string& _registerString, const std::string& _URL, const double& _position0, const double& _position1){
		saveData = SaveData(_registerString, _URL, _position0, _position1);
	}

	void GetUserInput(SaveData _saveData){
		saveData = _saveData;
	}

	void SaveMain(SOCKET client){
		SaveToCSV();
		MakeHTML();
		ThrowToTerminal(client);
	};
};