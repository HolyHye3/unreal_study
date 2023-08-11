#pragma once

#include "Singleton.h"

class CSingleton
{
private:
	CSingleton();
	~CSingleton();

public:
	CSingleton Singleton = new CSingleton; // 자기 자신에게 객체 할당..??

};

