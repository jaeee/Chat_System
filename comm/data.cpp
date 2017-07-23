/*************************************************************************
	> File Name: data.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 23 Jul 2017 11:41:07 AM CST
 ************************************************************************/

#include "data.h"

data::data()
{}
data::~data()
{}
int data::str_to_serialize(std::string &out)
{
	Json::Value root;
	root["nick_name"] = nick_name;
	root["school"] = school;
	root["msg"] = msg;
	root["cmd"] = cmdi;

	return serialize(root, out);
}
int data::serialize_to_str(std::string &in)
{
	Json::Value root;
	unserialize(in, root);
	nick_name = root["nick_name"].asString();
	school = root["school"].asString();
	msg = root["msg"].asString();
	cmd = root["cmd"].asString();

}
