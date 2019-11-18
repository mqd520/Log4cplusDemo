// ConsoleDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "LogHelper.h"

#include "LogThread.h"


int _tmain(int argc, _TCHAR* argv[])
{
	LogHelper::Init();


	LogThread thd;
	thd.Run();


	getchar();

	thd.Exit(10 * 1000);
	LogHelper::Exit();

	return 0;
}

