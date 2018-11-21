#include "GlobalParamManager.h"

CGlobalParamManager * CGlobalParamManager::s_pGlobalFun = NULL;

CGlobalParamManager* CGlobalParamManager::GetInstance()
{
	if (NULL == s_pGlobalFun)
	{
		s_pGlobalFun = new CGlobalParamManager();
	}
	return s_pGlobalFun;
}

void CGlobalParamManager::DeleteInstance()
{
	if (NULL != s_pGlobalFun)
	{
		delete s_pGlobalFun;
		s_pGlobalFun = NULL;
	}
}

namespace AutoRun
{
	class CAutoDeleteInstance
	{
	public:
		CAutoDeleteInstance()
		{
			printf("==========CAutoDeleteInstance=============\n");
		}
		~CAutoDeleteInstance()
		{
			printf("==========~CAutoDeleteInstance=============\n");
			CGlobalParamManager::DeleteInstance();
		}
	};
	static CAutoDeleteInstance s_AutoDelete;
}



CGlobalParamManager::CGlobalParamManager()
{
	printf("==========CGlobalParamManager=============\n");
}


CGlobalParamManager::~CGlobalParamManager()
{
	printf("==========~CGlobalParamManager=============\n");
}

void CGlobalParamManager::DemoFunRun()
{
	char * pBuffer = new char[32];
	memset(pBuffer, '\0', sizeof(char) * 32);
	strcpy_s(pBuffer, 31, "Memory~1234567890");

	ListDemoFun();
	MapDemoFun();
}

void CGlobalParamManager::ListDemoFun()
{
	printf("\nListDemoFun=============\n");
	list<LogData*> ListLogData;

	for (int i = 0; i < 5; i++)
	{
		LogData * pLog = new LogData;
		sprintf_s(pLog->strBuffer, 256, "%04d", i + 1);
		pLog->i4ID = i + 1;

		pLog->pTempBuffer = new char[48];
		memset(pLog->pTempBuffer, 0, sizeof(char) * 48);
		strcpy_s(pLog->pTempBuffer, 47, "Hello World!~~");

		ListLogData.push_back(pLog);
	}

	for(list<LogData*>::iterator it = ListLogData.begin(); it != ListLogData.end(); it++)
	{
		LogData * pLog = *it;
		printf("%d:%s\n", pLog->i4ID, pLog->strBuffer);
	}

	/*
	for(list<LogData*>::iterator it = ListLogData.begin(); it != ListLogData.end();)
	{
		LogData * pLog = *it;
		if (NULL != pLog)
		{
			delete pLog;
			pLog = NULL;
		}
		it = ListLogData.erase(it);
	}
	*/

	while(0 != ListLogData.size())
	{
		LogData * pLog = ListLogData.front();
		ListLogData.pop_front();

		if (NULL != pLog)
		{
			delete pLog;
			pLog = NULL;
		}
	}


	int k = 0;
}

void CGlobalParamManager::MapDemoFun()
{
	printf("\nMapDemoFun=============\n");
	map<string, int>  MapOnLineUser;
	MapOnLineUser.insert(make_pair("sino_001", 1));
	MapOnLineUser.insert(make_pair("sino_002", 1));
	MapOnLineUser.insert(make_pair("sino_003", 1));

	MapOnLineUser.insert(make_pair("sino_003~2234", 1));
	MapOnLineUser.insert(make_pair("sino_003~2534", 1));
	MapOnLineUser.insert(make_pair("sino_003~2534", 1));

	int i4Num = 0;
	map<string, int>::iterator it;
	for (it = MapOnLineUser.begin(); it != MapOnLineUser.end(); ++it)
	{
		printf("%d:%s,%d\n", i4Num++, it->first.c_str(), it->second);
	}

	it = MapOnLineUser.find("sino_002");
	if (it != MapOnLineUser.end())
	{
		printf("Find %s,%d\n", it->first.c_str(), it->second);
		MapOnLineUser.erase(it);
	}

	int i4FindNum = 0;
	for (it = MapOnLineUser.begin(); it != MapOnLineUser.end(); it++)
	{
		if (it->first.find("sino_003", 0))
		{
			i4FindNum++;
		}
	}
	printf("Find with : %d\n", i4FindNum);

	printf("Find count : %d\n", MapOnLineUser.count("sino_003"));

	for (it = MapOnLineUser.begin(); it != MapOnLineUser.end();)
	{
		it = MapOnLineUser.erase(it);
	}

	printf("Size %d\n", MapOnLineUser.size());
}