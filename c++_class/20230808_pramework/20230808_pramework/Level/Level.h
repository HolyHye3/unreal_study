#pragma once

#include "../GameInfo.h"

class CLevel
{
public:
	CLevel();
	~CLevel();

public:
	void Init();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Collision(float DeltaTime);

	void Rander(HDC hdc);


};

