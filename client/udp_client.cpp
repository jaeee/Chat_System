/*************************************************************************
	> File Name: udp_client.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:32:12 PM CST
 ************************************************************************/

#include "udp_client.h"


udp_client::udp_client(const std::string &_ip, const int &_port)
	:remote_ip(_ip), remote_port(_port), sock(-1)
{}
int udp_client::init_client()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		write_log("create socket error", FATAL);
		return -1;
	}
	return 0;
}
int udp_client::recv_msg(std::string &out)
{
	char buf[1024];
	struct sockaddr_in peer;
	socklen_t len = sizeof(len);
	int ret = recvfrom(sock, buf, sizeof(peer)-1, 0, (struct sockaddr*)&peer, &len);
	if(ret > 0)
	{
		buf[ret] = 0;
		out = buf;
	}
}
int udp_client::send_msg(const std::string &in)
{
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(remote_port);
	server.sin_addr.s_addr = inet_addr(remote_ip);

	int ret = sendto(sock, in.c_str(), in.size(), 0, (struct sockaddr*)&server, sizeof(server));
	if(ret < 0)
	{
		write_log("send msg error", WARNING);
		return -1;
	}
	return 0;
		
}		
udp_client::~udp_client()
{
	if(sock > 0)
	{
		close(sock);
	}
}

