/*************************************************************************
	> File Name: chat_system.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:34:33 PM CST
 ************************************************************************/

#include "udp_server.h"
#include <unistd.h>

void usage(std::string proc)
{
	std::cout << "Usage: " << proc << "[peer_ip] [peer_port]" << std::endl; 
}

void *brocast(void *arg)
{
	udp_server* serverp = (udp_server*)arg;
	while(1)
	{
		serverp->brocast_msg();
	}
}
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 1;
	}

	udp_server server(argv[1], atoi(argv[2]));
	server.init_server();

	daemon(0, 0);
	pthread_t id;
	pthread_create(&id, NULL, brocast, (void*)&server);
	std::string msg;
	while(1)
	{
		server.recv_msg(msg);
	}
	return 0;
}

