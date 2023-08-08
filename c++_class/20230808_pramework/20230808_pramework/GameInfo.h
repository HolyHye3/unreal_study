#pragma once

#include <Windows.h>

#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

struct Resolution
{
	int Width;
	int Height;
};