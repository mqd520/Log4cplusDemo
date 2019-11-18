#pragma once

#include "com/Thread.h"
using namespace com;


// LogThread
class LogThread : public Thread
{
public:
	LogThread();

protected:
	void OnWhile() override;
};