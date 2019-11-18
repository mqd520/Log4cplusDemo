#include "stdafx.h"
#include "LogHelper.h"

#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/helpers/fileinfo.h>
#include <log4cplus/loggingmacros.h>
using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;


string GetCurrentDir();


LogHelper::LogHelper()
{

}

void LogHelper::Init()
{
	string path = GetCurrentDir() + "log4cplus.config";

	log4cplus::initialize();
	LogLog::getLogLog()->setInternalDebugging(true);
	PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(path.c_str()));
}

void LogHelper::Exit()
{
	Logger::shutdown();
}

void LogHelper::Info(const string& log)
{
	Logger logger = Logger::getRoot();

	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT(log.c_str()));
}

void LogHelper::Debug(const string& log)
{
	Logger logger = Logger::getRoot();

	LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT(log.c_str()));
}

void LogHelper::Warn(const string& log)
{
	Logger logger = Logger::getRoot();

	LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT(log.c_str()));
}

void LogHelper::Error(const string& log)
{
	Logger logger = Logger::getRoot();

	LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT(log.c_str()));
}

string GetCurrentDir()
{
	string str = "";

	char chPath[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, chPath, MAX_PATH);
	char* p = strrchr(chPath, '\\');
	if (p)
	{
		*(p + 1) = 0;
	}

	str = chPath;

	return str;
}