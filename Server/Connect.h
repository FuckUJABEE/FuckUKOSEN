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

	int GetMode();
	std::string GetSearchString();

	SaveData GetUserInput() {
		char buffer[512];
		std::string _name;
		std::string _url;
		double _position[2];

		std::cout << "Connect::GetUserInput" << std::endl;

		recv(client, buffer, 512, 0);
		_name = buffer;
	
		recv(client, buffer, 512, 0);
		_url = buffer;

		recv(client, buffer, 8, 0);
		_position[0] = std::stof(buffer);

		recv(client, buffer, 8, 0);
		_position[1] = std::stof(buffer);

		SaveData sd(_name, _url, _position[0], _position[1]);

		std::cout << "Connect::GetUserInput End" << std::endl;

		return sd;
	}

	SOCKET getClient(){
		return client;
	}
};