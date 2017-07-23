/*************************************************************************
	> File Name: pool.h
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 03:32:49 PM CST
 ************************************************************************/
#ifndef _POOL_H_
#define _POOL_H_

#include <iostream>
#include <string>
#include <vector>
#include <semaphore.h>

//生产者消费者模型 环形队列 信号量
class pool
{
	public:
		pool(int size);
		int get_data(std::string &out);
		int put_data(const std::string &in);
		~pool();
	private:
		pool(const pool &p);

		int c_step;
		int p_step;
		sem_t c_sem;
		sem_t p_sem;
		std::vector<std::string> data_pool;
		int cap;
};
#endif
