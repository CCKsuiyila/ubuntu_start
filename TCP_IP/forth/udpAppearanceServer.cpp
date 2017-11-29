#include "Winsock2.h"
#include "stdio.h"
#include "string.h"
#pragma comment(lib,"wsock32.lib")

#define RECV_PORT 3000
#define SEND_PORT 3001

SOCKET sock;
SOCKET ServerSock;
sockaddr_in ServerAddr;
sockaddr_in broadAddr;

void main(){
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(2,2),&WSAData)!=0){
		printf("socket init fail!\n");
		return;
	}
	
	sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock==SOCKET_ERROR){
		printf("socket create fail!\n");
		WSACleanup();
		return;
	}
	
	ServerSock = socket(AF_INET,SOCK_DGRAM,0);
	if(ServerSock==SOCKET_ERROR){
		printf("socket create fail!\n");
		WSACleanup();
		return;
	}
	
	memset(&ServerAddr,0,sizeof(ServerAddr));
	ServerAddr.sin_family=AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("172.20.10.5");
	ServerAddr.sin_port = htons(RECV_PORT);
	
	memset(&broadAddr,0,sizeof(broadAddr));
	broadAddr.sin_family = AF_INET;
	broadAddr.sin_addr.s_addr = inet_addr("255.255.255.255");
	printf("Braodcase addr: %s \n",inet_ntoa(broadAddr.sin_addr));
	broadAddr.sin_port  = htons(SEND_PORT);
	
	bool bBroadcast = true;
	int n = setsockopt(sock,SOL_SOCKET,SO_BROADCAST,(const char*)&bBroadcast,sizeof(bBroadcast));
	
	int opt = sizeof(bBroadcast);
	getsockopt(sock,SOL_SOCKET,SO_BROADCAST,(char*)&bBroadcast,&opt);
	if(bBroadcast == true){
		printf("Test Braodcase: ok \n");
	}else{
		printf("Test Braodcase: can not Braodcase \n");
		return;
	}
	
	char buf[1024] = "/name:Please send your name\0";
	n = sendto(sock,buf,strlen(buf) + 1,0,(const sockaddr *)&broadAddr,sizeof(broadAddr));
	
	if(n == SOCKET_ERROR){
		printf(" BROADCAST data error! \n");
		printf(" The error code: %d \n", WSAGetLastError());
		}else{
			printf("Send BROADCAST data: \"%s\" ok! \n\n",buf);
	}
	
	if(bind(ServerSock,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr)) == SOCKET_ERROR){
		printf(" Binding error! \n");
		printf(" The error code: %d \n",WSAGetLastError());
		closesocket(ServerSock);
		getchar();
		return;
	}else{
		printf("Binding ok! start recieving data from clients ... \n");
	}
	
	while(1){
		sockaddr_in ClientAddr;
		memset(&buf,'\0',sizeof(buf));
		memset(&ClientAddr,0,sizeof(ClientAddr));;
		n = sizeof(ClientAddr);
		n = recvfrom(ServerSock,buf,sizeof(buf),0,(struct sockaddr *)&ClientAddr, &n);
		
		if( n!= SOCKET_ERROR){
			printf("\n 接收远程主机 %s 传回的数据: %s \n", inet_ntoa(ClientAddr.sin_addr),buf);
		}
	}
	
	closesocket(sock);
	closesocket(ServerSock);
	WSACleanup();
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	