#include "MemoryLeakCheck.h"
#include <stdio.h>

void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

namespace AutoRun
{
	class CAutoMemoryLeakCheck
	{
	public:
		CAutoMemoryLeakCheck()
		{
			printf("==========CAutoRun=============\n");
			EnableMemLeakCheck();
		}
		~CAutoMemoryLeakCheck()
		{
			printf("==========~CAutoRun=============\n");
		}
	};
	static CAutoMemoryLeakCheck s_AutoMemoryLeakCheck;
}