/*************************************************************************
	> File Name: data.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 23 Jul 2017 11:40:59 AM CST
 ************************************************************************/
#ifdef _DATA_H_
#define _DATA_H_
#include <iostream>
#include <string>
#include "base_json.h"

class data
{
	public:
		data();
		~data();
		int str_to_serialize(std::string &out);
		int serialize_to_str(std::string &in);
	public:
		std::string nick_name;
		std::string school;
		std::string msg;
		std::string cmd;
};

#endif
