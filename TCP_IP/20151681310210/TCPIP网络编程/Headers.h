
typedef struct _iphdr  //IP首部
{
	unsigned char h_lenver; //4位IP版本号 + 4位首部长度
	unsigned char tos; //8位服务类型TOS
	unsigned short total_len; //16位总长度 
    unsigned short ident; //16位标识
	unsigned short frag_and_flags; //3位标志位和13位片偏移
	unsigned char ttl; //8位生存时间
    unsigned char proto;//8位协议
	unsigned short checksum; //16位IP首部校验和
	unsigned int sourceIP; //32位源IP地址
	unsigned int destIP; //32位目的IP地址
}IP_HEADER;

typedef struct _tcpphdr  //TCP首部
{
	unsigned short sourcePORT; //16位源端口号
	unsigned short sdestPORT; //16位目的端口号
	unsigned int sequence; //32位序列号
    unsigned int confirm; //32位确认号
	unsigned char th_lenres; //4位首部长度 + 4位保留字
    unsigned char th_flag;  //2位保留字 + 6位标志位
	unsigned short windowsize; //16位窗口大小
	unsigned short checksum; //16位IP首部校验和
	unsigned short urgent_p; //32位紧急指针
}TCP_HEADER;

typedef struct _udpphdr  //UDP首部
{
	unsigned short sourcePORT;//16位源端口号
	unsigned short sdestPORT;//16位目的端口号
	unsigned short h_len;//16位长度
	unsigned short checksum;//16位IP首部校验和
}UDP_HEADER;