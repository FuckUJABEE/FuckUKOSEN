#pragma once
#include<string>
#include <winsock2.h>

struct SaveData{
	std::wstring registerString;
	std::wstring explanation;
	double position[2];

	SaveData(){
		registerString = std::wstring(L"null");
		explanation = std::wstring(L"null");
		for (int i = 0; i < 2; ++i)
			position[i] = 0;
	};

	SaveData(const std::wstring& _registerString, const std::wstring& _explanation, const double& _position0, const double& _position1){
		registerString = _registerString;
		explanation = _explanation;
		position[0] = _position0;
		position[1] = _position1;
	};

	SaveData(SaveData& _saveData){
		registerString = _saveData.registerString;
		explanation = _saveData.explanation;

		for (int i = 0; i < 2;++i)
			position[i] = _saveData.position[i];

	}
};


class Save{
private:
	std::wstring fileNameCSV;
	std::wstring answerString;
	SaveData saveData;

	bool SaveToCSV();
	bool MakeHTML();

	bool ThrowToTerminal(SOCKET);

public:
	Save(){
		setlocale(LC_CTYPE, "");
		fileNameCSV = std::wstring(L"save.csv");
	}

	void GetUserInput(const std::wstring& _registerString, const std::wstring& _URL, const double& _position0, const double& _position1){
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