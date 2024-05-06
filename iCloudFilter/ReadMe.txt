
Redis版本: 4.0.7

C++ 测试redis，集合插入的性能

SADD TPR_RESOURCE_ATTR_SET_123456789 insert 1000000 ,perl:7751 ,hLen:100000000

启动服务：
redis-server ./redis_6370.conf

客户端连接：
redis-cli -h 192.168.0.177 -p 6370
