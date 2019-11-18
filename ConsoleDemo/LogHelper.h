#pragma once

#include <string>
using namespace std;


// LogHelper
class LogHelper final
{
private:
	LogHelper();

public:
	static void Init();

	static void Exit();

	static void Info(const string& log);

	static void Debug(const string& log);

	static void Warn(const string& log);

	static void Error(const string& log);
};