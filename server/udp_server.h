/*************************************************************************
	> File Name: udp_server.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:35:02 PM CST
 ************************************************************************/
#ifndef _UDP_SERVER_H_
#define _UDP_SERVER_H_

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <pthread.h>
#include "pool.h"
#include "log.h"

class udp_server
{
	public:
		udp_server(const std::string &_ip, const int &_port);
		int init_server();
		int recv_msg(std::string &out);
		int send_msg(const std::string &in, struct sockaddr_in &peer,const int &len);
		int add_online_user(struct sockaddr_in *client);
		int del_online_user(struct sockaddr_in *client);
		int brocast_msg();
		~udp_server();

	private:
		udp_server(const udp_server &);

		std::string ip;
		int port;
		int sock;
		std::map<int, struct sockaddr_in> online_user;
		pool data_pool;
};

#endif
