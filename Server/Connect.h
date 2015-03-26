#pragma once

#include <winsock2.h>
#include<string>
#include<iostream>
#include"Save.h"

class Connect{
private:
	SOCKET server, client;

	//接続を許可するクライアント端末の情報
	struct sockaddr_in source;

	WSADATA data;

public:
	Connect();
	~Connect();

	std::wstring StringToWString(const std::string& arg_str)
	{
		// https://gist.github.com/TAMAGO-JP/31f0030d26b321a9548e

		size_t length = arg_str.size();
		size_t convLength;
		wchar_t *wc = (wchar_t*)malloc(sizeof(wchar_t)* (length + 2));
		mbstowcs_s(&convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE);
		std::wstring str(wc);
		free(wc);

		return str;
	};

	int GetMode();
	std::string GetSearchString();

	SaveData GetUserInput() {
		char buffer[512];
		std::wstring nameSource;
		std::wstring urlSource;
		std::string _name;
		std::string _url;
		double _position[2];

		std::cout << "Connect::GetUserInput" << std::endl;

		recv(client, buffer, 512, 0);
		_name = buffer;
		nameSource = StringToWString(_name);
	
		recv(client, buffer, 512, 0);
		_url = buffer;
		nameSource = StringToWString(_url);

		recv(client, buffer, 8, 0);
		_position[0] = std::stof(buffer);

		recv(client, buffer, 8, 0);
		_position[1] = std::stof(buffer);

		SaveData sd(nameSource, urlSource, _position[0], _position[1]);

		std::cout << "Connect::GetUserInput End" << std::endl;

		return sd;
	}

	SOCKET getClient(){
		return client;
	}
};