#include <iostream>
#include<string>
#include <winsock2.h>

int main(void){
	SOCKET server;    //ソケット

	//接続するサーバの情報
	struct sockaddr_in dest;

	//接続するサーバのIPアドレス
	//xxx.xxx.xxx.xxxの形式で指定する
	char destination[] = "192.168.1.3";

//	char buffer[1024];
//	std::string buffer;

	//ソケット通信の準備
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);

	//接続先（サーバ）のアドレス情報を設定
	memset(&dest, 0, sizeof(dest));

	//ポート番号はサーバプログラムと共通
	dest.sin_port = htons(7000);
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(destination);

	//ソケットの生成
	server = socket(AF_INET, SOCK_STREAM, 0);

	//サーバへの接続
	if (connect(server, (struct sockaddr *) &dest, sizeof(dest))){
		std::cout << destination << "に接続できませんでした" << std::endl;
		return -1;
	}
	else{
		std::cout << destination << "に接続しました" << std::endl;
	}


	int mode;
	char mode_str[8];

	std::cout << "Mode Select" << std::endl;
	std::cout << ">>  ";
	std::cin >> mode;
	sprintf_s(mode_str, "%d", mode);

	//サーバにデータを送信
	send(server, mode_str, sizeof(mode_str), 0);


	switch (mode){
	case 0:
		char resultNum[8];
		char searchString[128];

		std::cout << "検索文字列を入力して下さい" << std::endl;
		std::cout << ">>  ";
		std::cin >> searchString;
		send(server, searchString, sizeof(searchString), 0);

		recv(server, resultNum, 8, 0);
		std::cout << resultNum << "件見つかりました" << std::endl;


		for (int i = atoi(resultNum); i > 0; --i){
			char name[1024] = {'\0'};
			char url[1024] = {'\0'};

			recv(server, name, 1024, 0);
			recv(server, url, 1024, 0);

			std::cout << i << " : " << name << " " << url << std::endl;
		}
		break;

	case 1:
		int result;
		std::string name = "TESTCODE";
		std::string url = "http://www.example.com";
		double position[2] = {114.514, 810.931};
		char position_str[2][64];

		std::cout << "Name" << std::endl;
		std::cout << ">>";
		std::cin >> name;

		std::cout << "URL" << std::endl;
		std::cout << ">>";
		std::cin >> url; 
		
		std::cout << "Position[0]" << std::endl;
		std::cout << ">>";
		std::cin >> position[0];
		
		std::cout << "Position[1]" << std::endl;
		std::cout << ">>";
		std::cin >> position[1];
	

		sprintf(position_str[0], "%f", position[0]);
		sprintf(position_str[1], "%f", position[1]);

		send(server, name.c_str(), 512, 0);
		send(server, url.c_str(), 512, 0);
		send(server, position_str[0], 8, 0);
		send(server, position_str[1], 8, 0);
		
		char listURL[256];
		result = recv(server, listURL, 2048, 0);

		if (result < 0){
			std::cout << "mode1 rcv error" << std::endl;
		}
		else{
			std::cout << listURL << std::endl;
		}
		break;
	}

	// Windows でのソケットの終了
	closesocket(server);
	WSACleanup();

	return 0;
}