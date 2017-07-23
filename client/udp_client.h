/*************************************************************************
	> File Name: udp_client.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:32:23 PM CST
 ************************************************************************/
#ifndef _UDP_CLIENT_H_
#define _UDP_CLIENT_H_

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "log.h"

class udp_client
{
	public:
		udp_client(const std::string &_ip, const int &_port);
		int init_client();
		int recv_msg(std::string &out);
		int send_msg(const std::string &in);
		~udp_client();
	private:
		udp_client(const udp_client &);
		std::string remote_ip;
		int remote_port;
		int sock;
};

#endif
