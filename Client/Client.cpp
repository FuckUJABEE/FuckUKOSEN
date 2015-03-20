#include <stdio.h>
#include <winsock2.h>

int ClientMain(void){
	SOCKET s;    //ソケット

	//接続するサーバの情報
	struct sockaddr_in dest;

	//接続するサーバのIPアドレス
	//xxx.xxx.xxx.xxxの形式で指定する
	char destination[] = "192.168.1.3";

	char buffer[1024];

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
	s = socket(AF_INET, SOCK_STREAM, 0);

	//サーバへの接続
	if (connect(s, (struct sockaddr *) &dest, sizeof(dest))){
		printf("%sに接続できませんでした\n", destination);
		return -1;
	}
	else{
		printf("%sに接続しました\n", destination);
	}


	printf("サーバに送信する文字列を入力して下さい\n");
	scanf("%s", buffer);

	//サーバにデータを送信
	send(s, buffer, sizeof(buffer), 0);

	//サーバからデータを受信
	recv(s, buffer, 1024, 0);
	printf("→ %s\n\n", buffer);

	// Windows でのソケットの終了
	closesocket(s);
	WSACleanup();

	return 0;
}