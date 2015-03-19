#pragma once
#include<string>

// ユーザーからの入力を受け取りCSVに保存する
// 「ユーザーからの入力の受け取り」と「CSVへの書き込み」を分ける場合はユーザーからの入力の受け取りをGetUserInputクラスに書く

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
	SaveData saveData;

	bool SaveToCSV();
	bool MakeHTML();

	bool ThrowToTerminal();

public:
	Save(){
		fileNameCSV = "save.csv";
	}

	void GetUserInput(const std::string& _registerString, const std::string& _URL, const double& _position0, const double& _position1){
		saveData = SaveData(_registerString, _URL, _position0, _position1);
	}

	void SaveMain(){
		SaveToCSV();
		MakeHTML();
		ThrowToTerminal();
	};
};