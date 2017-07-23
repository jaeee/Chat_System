/*************************************************************************
	> File Name: base_json.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Sun 23 Jul 2017 11:40:51 AM CST
 ************************************************************************/
#ifndef _BASE_JSON_H_
#define _BASE_JSON_H_
#include <iostream>
#include <string>
#include "json/json.h"

int serialize(Json::Value &_v, std::string &str);
int unserialize(std::string &str, Json::Value &_v);
#endif

