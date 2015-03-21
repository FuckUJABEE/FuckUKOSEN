#include <iostream>
#include<string>
#include <winsock2.h>

int main(void){
	SOCKET server;    //�\�P�b�g

	//�ڑ�����T�[�o�̏��
	struct sockaddr_in dest;

	//�ڑ�����T�[�o��IP�A�h���X
	//xxx.xxx.xxx.xxx�̌`���Ŏw�肷��
	char destination[] = "192.168.1.3";

//	char buffer[1024];
//	std::string buffer;

	//�\�P�b�g�ʐM�̏���
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);

	//�ڑ���i�T�[�o�j�̃A�h���X����ݒ�
	memset(&dest, 0, sizeof(dest));

	//�|�[�g�ԍ��̓T�[�o�v���O�����Ƌ���
	dest.sin_port = htons(7000);
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(destination);

	//�\�P�b�g�̐���
	server = socket(AF_INET, SOCK_STREAM, 0);

	//�T�[�o�ւ̐ڑ�
	if (connect(server, (struct sockaddr *) &dest, sizeof(dest))){
		std::cout << destination << "�ɐڑ��ł��܂���ł���" << std::endl;
		return -1;
	}
	else{
		std::cout << destination << "�ɐڑ����܂���" << std::endl;
	}


	int mode;
	char mode_str[8];

	std::cout << "Mode Select" << std::endl;
	std::cout << ">>  ";
	std::cin >> mode;
	sprintf_s(mode_str, "%d", mode);

	//�T�[�o�Ƀf�[�^�𑗐M
	send(server, mode_str, sizeof(mode_str), 0);


	switch (mode){
	case 0:
		char resultNum[8];
		char searchString[128];

		std::cout << "�������������͂��ĉ�����" << std::endl;
		std::cout << ">>  ";
		std::cin >> searchString;
		send(server, searchString, sizeof(searchString), 0);

		recv(server, resultNum, 8, 0);
		std::cout << resultNum << "��������܂���" << std::endl;


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

	// Windows �ł̃\�P�b�g�̏I��
	closesocket(server);
	WSACleanup();

	return 0;
}