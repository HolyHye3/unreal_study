#pragma once

#include "Singleton.h"

class CSingleton
{
private:
	CSingleton();
	~CSingleton();

public:
	CSingleton Singleton = new CSingleton; // �ڱ� �ڽſ��� ��ü �Ҵ�..??

};

