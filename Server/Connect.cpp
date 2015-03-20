#include"Connect.h"

Connect::Connect(){
	memset(&source, 0, sizeof(source));
	source.sin_family = AF_INET;

	source.sin_port = htons(7000);
	source.sin_addr.s_addr = htonl(INADDR_ANY);

	WSADATA data;

	if (WSAStartup(MAKEWORD(2, 0), &data) < 0){
		std::cout << GetLastError() << std::endl;
		std::cout << "�\�P�b�g�ʐM�����G���[\n" << std::endl;
	}

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (server < 0){
		std::cout << GetLastError() << std::endl;
		std::cout << "�\�P�b�g�����G���[\n" << std::endl;
	}

	if (bind(server, (struct sockaddr *)&source, sizeof(source)) < 0){
		std::cout << GetLastError() << std::endl;
		std::cout << "�o�C���h�G���[\n" << std::endl;
	}

	if (listen(server, 1) < 0){
		std::cout << "�ڑ����G���[\n" << std::endl;
	}

	std::cout << "�ڑ��J�n\n" << std::endl;

	client = accept(server, NULL, NULL);

	if (client < 0){
		std::cout << "�ҋ@�G���[\n" << std::endl;
	}
}

Connect::~Connect(){
	closesocket(client);

	WSACleanup();
	std::cout << "�ʐM���I�����܂�" << std::endl;
}

int Connect::GetMode(){
	char buffer_tmp[64];
	int buffer;
	int result;

	std::cout << std::endl;
	std::cout << "Connect::GetMode" << std::endl;

	result = recv(client, buffer_tmp, 64, 0);

	if (result < 0){
		std::cout << "��M�G���[" << std::endl;
	}
	else{
		buffer = atoi(buffer_tmp);
	}

	std::cout << buffer << "�����͂���܂���" <<std::endl;

	return buffer;
}

std::string Connect::GetSearchString(){
	char buffer_tmp[1024];
	std::string buffer;
	int result;

	std::cout << std::endl;
	std::cout << "Connect::GetSearchString" << std::endl;

	result = recv(client, buffer_tmp, 1024, 0);

	if (result < 0){
		std::cout << "��M�G���[" << std::endl;
	}
	else{
		buffer = buffer_tmp;
	}

	std::cout << "�u"<< buffer << "�v�����͂���܂���" <<std::endl;

	return buffer;

}