#include "stdafx.h"
#include "LogThread.h"

#include "com/TimeTool.h"
#include "com/CommonTool.h"
#include "com/StringTool.h"
#include "com/Log.h"
using namespace com;

#include "LogHelper.h"


#define  MaxCount		(100)


LogThread::LogThread()
	: Thread(2 * 1000, "LogThread")
{

}

void LogThread::OnWhile()
{
	int count = 0;

	while (count < CommonTool::Rand() % MaxCount)
	{
		string str1 = StringTool::Format("This is a Info log, time: %lld", TimeTool::GetCurTimeStamp());
		Log::Write_2_Console(ELogType::Info, str1, false, __FUNCDNAME__);
		LogHelper::Info(str1);

		string str2 = StringTool::Format("This is a Debug log, time: %lld", TimeTool::GetCurTimeStamp());
		Log::Write_2_Console(ELogType::Debug, str2, false, __FUNCDNAME__);
		LogHelper::Debug(str2);

		string str3 = StringTool::Format("This is a Warn log, time: %lld", TimeTool::GetCurTimeStamp());
		Log::Write_2_Console(ELogType::Warn, str3, false, __FUNCDNAME__);
		LogHelper::Warn(str3);

		string str4 = StringTool::Format("This is a Error log, time: %lld", TimeTool::GetCurTimeStamp());
		Log::Write_2_Console(ELogType::Error, str4, false, __FUNCDNAME__);
		LogHelper::Error(str4);

		count++;
	}
}