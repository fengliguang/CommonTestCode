#pragma once


#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

#define	  pGlobalParamManager	CGlobalParamManager::GetInstance()

struct LogData
{
	char strBuffer[256];
	int  i4ID;
	char * pTempBuffer;

	LogData()
	{
		printf("==========LogData=============\n");
		memset(strBuffer, 0, sizeof(char) * 256);
		i4ID = 0;
		pTempBuffer = NULL;
	}

	~LogData() 
	{ 
		printf("==========~LogData=============\n");
		if (pTempBuffer)
		{
			delete pTempBuffer;
			pTempBuffer = NULL;
		}	
	}
};

class CGlobalParamManager
{
public:
	static CGlobalParamManager * GetInstance();
	static void	DeleteInstance();
public:
	void DemoFunRun();
private:
	void ListDemoFun();
	void MapDemoFun();

private:
	CGlobalParamManager();
	~CGlobalParamManager();

	CGlobalParamManager(const CGlobalParamManager &);
	const CGlobalParamManager &operator = (const CGlobalParamManager &);
private:
	static CGlobalParamManager * s_pGlobalFun;
};

