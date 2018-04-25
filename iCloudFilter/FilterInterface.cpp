#include "FilterInterface.h"








//void Redis::hSet(string hashKey,string key,T value)
//{
//	ostringstream sCmd;
//
//	sCmd<<"HSET "<< key <<" " <<value;
//	redisCommand(this->_connect, sCmd.str().c_str());
//
//
//}


string Redis::hGet(string hashKey,string key)
{

	this->_reply = (redisReply*)redisCommand(this->_connect, "HGET %s %s",hashKey.c_str(), key.c_str());
	std::string str = this->_reply->str;
	freeReplyObject(this->_reply);
	return str;
}