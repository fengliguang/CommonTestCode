#ifndef _CMEMORYLEAKCHECK_H_
#define _CMEMORYLEAKCHECK_H_

//����ڴ�й©����Դ�ļ�����
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <malloc.h>

#define  new  new(_CLIENT_BLOCK, __FILE__, __LINE__)

void EnableMemLeakCheck();

#endif