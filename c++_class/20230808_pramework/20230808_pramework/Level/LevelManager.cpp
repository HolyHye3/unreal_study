#include "LevelManager.h"
#include "Level.h"

CLevelManager* CLevelManager::mInst = nullptr;

CLevelManager::CLevelManager()
{
}

CLevelManager::~CLevelManager()
{
}

void CLevelManager::Init()
{
	mLevel->Init();
}

void CLevelManager::Input(float DeltaTime)
{
	mLevel->Input(DeltaTime);
}

void CLevelManager::Update(float DeltaTime)
{
	mLevel->Update(DeltaTime);
}

void CLevelManager::Collision(float DeltaTime)
{
	mLevel->Collision(DeltaTime);
}

void CLevelManager::Rander(HDC hDc)
{
	mLevel->Rander(hDc);
}
