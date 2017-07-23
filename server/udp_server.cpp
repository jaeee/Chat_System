/*************************************************************************
	> File Name: udp_server.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:34:52 PM CST
 ************************************************************************/

#include "udp_server.h"

udp_server::udp_server(const std::string &_ip, const int &_port)
	:ip(_ip),port(_port),sock(-1),data_pool(256)
{}

int udp_server::init_server()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		write_log("create socket error", FATAL);
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr = inet_addr(ip.c_str());

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		write_log("bind error", FATAL);
		return -2;
	}
	return 0;
}
int udp_server::recv_msg(std::string &out)
{
	char buf[1024];
	struct sockaddr_in peer;
	socklen_t len = sizeof(peer);
	int ret = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&peer, &len);
	if(ret > 0)
	{
		buf[ret] = 0;
		out = buf;
		data_pool.put_data(out);
		data d;
		d.serialize_to_str(out);
		if(d.cmd == "QUIT")
			del_online_user(&peer);
		else
			add_online_user(&peer);
	}
}
int udp_server::send_msg(const std::string &in, struct sockaddr_in &peer,const int &len)
{
	int ret = sendto(sock, in.c_str(), in.size(), 0, (struct sockaddr*)&peer, len);
	if(ret < 0)
	{
		write_log("send msg error", WARNING);
		return -1;
	}
	return 0;
}
int udp_server::add_online_user(struct sockaddr_in *client)
{
	online_user.insert(std::pair<int, struct sockaddr_in>(client->sin_addr.s_addr,*client));
}
int udp_server::del_online_user(struct sockaddr_in *client)
{
	std::map<int, struct sockaddr_in>::iterator iter = online_user.find(client->sin_addr.s_addr);
	if(iter != online_user.end())
	{
		online_user.erase(iter);
	}
}
int udp_server::brocast_msg()
{
	std::string msg;
	data_pool.get_data(msg);
	std::map<int, struct sockaddr_in>::iterator iter = online_user.begin();
	for(; iter != online_user.end(); iter++)
	{
		send_msg(msg, iter->second, sizeof(iter->second));
	}
	return 0;
}

udp_server::~udp_server()
{
	if(sock > 0)
	{
		close(sock);
	}
}



