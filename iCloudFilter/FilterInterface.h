#ifndef _REDIS_H_
#define _REDIS_H_

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>

#include <hiredis/hiredis.h>

using namespace std;

class Redis
{
public:

	Redis(){}

	~Redis()
	{
		this->_connect = NULL;
		this->_reply = NULL;                
	}

	bool connect(std::string host, int port)
	{
		this->_connect = redisConnect(host.c_str(), port);
		if(this->_connect != NULL && this->_connect->err)
		{
			printf("connect error: %s\n", this->_connect->errstr);
			return 0;
		}
		return 1;
	}

	std::string get(std::string key)
	{
		this->_reply = (redisReply*)redisCommand(this->_connect, "GET %s", key.c_str());
		std::string str = this->_reply->str;
		freeReplyObject(this->_reply);
		return str;
	}

	void set(std::string key, std::string value)
	{
		redisCommand(this->_connect, "SET %s %s", key.c_str(), value.c_str());
	}

	long scard(std::string key)
	{
		long lLen;
		_reply = (redisReply*)redisCommand(this->_connect, "SCARD %s ", key.c_str());
		if (_reply!=NULL)
		{
			//cout<<"type:"<<_reply->type<<",integer:"<<_reply->integer<<",len:"<<_reply->len<<endl;
			lLen=_reply->integer;
			freeReplyObject(this->_reply);
		}
		return lLen;
	}

	void Sadd(std::string key, std::string value)
	{
		_reply = (redisReply*)redisCommand(this->_connect, "SADD %s %s", key.c_str(), value.c_str());
		if (_reply!=NULL)
		{
			freeReplyObject(this->_reply);
		}
	}

	template<typename T>
	void hSet(string hashKey,string key,T value)
	{
		ostringstream sCmd;

		sCmd<<"HSET "<<hashKey<<" "<< key <<" " <<value;
		//cout<<sCmd.str()<<endl;

		this->_reply = (redisReply*)redisCommand(this->_connect, sCmd.str().c_str());
		if (this->_reply!=NULL)
		{
			//cout<<"type:"<<_reply->type<<",integer:"<<_reply->integer<<",len:"<<_reply->len<<",str:"<<_reply->str<<endl;
			freeReplyObject(this->_reply);
		}


	}

	string hGet(string hashKey,string key);

	long hLen(string hashKey)
	{
		long lLen;
		_reply = (redisReply*)redisCommand(this->_connect, "HLEN %s ", hashKey.c_str());
		if (_reply!=NULL)
		{
			//cout<<"type:"<<_reply->type<<",integer:"<<_reply->integer<<",len:"<<_reply->len<<endl;
			lLen=_reply->integer;
			freeReplyObject(this->_reply);
		}
		return lLen;
	}
private:

	redisContext* _connect;
	redisReply* _reply;

};


#endif