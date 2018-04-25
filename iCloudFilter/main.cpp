#include <stdio.h>

#include "FilterInterface.h"

int main()
{
	long lPerlCount=1000000;
	Redis *r = new Redis();
	if(!r->connect("192.168.35.177", 6370))
	{
		printf("connect error!\n");
		return 0;
	}
	//r->set("name", "Andy");
	//printf("Get the name is %s\n", r->get("name").c_str());
	
	int iFieldId=1;
	int iKeySection=0;
	char chTmp[1024]={0};

	/*time_t tStart;
	time(&tStart);
	for(int i=1;i<=100000;i++)
	{
		memset(chTmp,0,sizeof(chTmp));
		sprintf(chTmp,"%d",iKeySection+i);
		r->hSet<int>("TPR_RESOURCE_ATTR_TEST3",chTmp,iFieldId);

		if(i%lPerlCount==0)
		{
			long lCount=r->hLen("TPR_RESOURCE_ATTR_TEST3");
			time_t tEnd;
			time(&tEnd);
			long lPerl=lPerlCount/(tEnd-tStart);
			cout<<"HSET insert "<<lPerlCount <<" ,perl:"<<lPerl<<" ,hLen:"<<lCount<<endl;

			tStart=tEnd;
		}
	}*/

	time_t tStart;
	time(&tStart);
	for(int i=67100359;i<=100000000;i++)
	{
		memset(chTmp,0,sizeof(chTmp));
		sprintf(chTmp,"%d",iKeySection+i);
		r->Sadd("TPR_RESOURCE_ATTR_SET_123456789",chTmp);

		if(i%lPerlCount==0)
		{
			long lCount=r->scard("TPR_RESOURCE_ATTR_SET_123456789");
			time_t tEnd;
			time(&tEnd);
			long lPerl=lPerlCount/(tEnd-tStart);
			cout<<"SADD TPR_RESOURCE_ATTR_SET_123456789 insert "<<lPerlCount <<" ,perl:"<<lPerl<<" ,hLen:"<<lCount<<endl;

			tStart=tEnd;
		}
	}
	

	//printf("HGet the TPR_RESOURCE_ATTR is %s\n", r->hGet("TPR_RESOURCE_ATTR","1000000").c_str());
	
	delete r;
	return 0;
}