#include "Timer.h"

float CTimer::mDeltaTime = 0.f; // 연속 프레임 사이의 시간 간격(초)
float CTimer::mFPS = 0.f; // 응용 프로그램의 FPS(초당 프레임 수)
float CTimer::mFPSTime = 0.f; // 프레임 사이에 경과된 시간을 누적
int CTimer::mTick = 0; // 통과한 프레임 수를 계산

// 고해상도 타이머 값을 저장하는 데 사용되는 LARGE_INTEGER 유형의 변수
LARGE_INTEGER CTimer::mSecond = {};
LARGE_INTEGER CTimer::mPrevTime = {};


// 고해상도 타이머를 초기화
void CTimer::Init()
{
    // 윈도우 고해상도 타이머의 초당 값을 얻어온다.
    QueryPerformanceFrequency(&mSecond);

    // 윈도우 고해상도 타이머의 현재 값을 얻어온다.
    QueryPerformanceCounter(&mPrevTime);
}

/*
1. 이전 프레임 이후 경과된 시간(mDelta Time)을 계산
2. 다음 프레임에 대한 mPrevTime을 업데이트
3. FPS 계산을 위한 시간(mFPSTime)을 누적
4. 60 프레임이 경과한 후 FPS를 계산
*/
float CTimer::Update()
{
    LARGE_INTEGER   Time;
    QueryPerformanceCounter(&Time);

    // 현재와 이전 고해상도 타이머 값의 차이를 고해상도 타이머의 빈도로 나누 값으로 계산된다.
    // (현재 고해상도 타이머값 - 이전프레임 고해상도 타이머값) / 초당 타이머 값
    mDeltaTime = (Time.QuadPart - mPrevTime.QuadPart) / (float)mSecond.QuadPart;

    // 다음 프레임에서는 현재의 타이머값이 이전프레임의 타이머 값이 되어야하므로 mPrevTime을 현재 타이머값으로 갱신해준다.
    mPrevTime = Time;

    // 시간을 누적시켜서 저장한다.
    mFPSTime += mDeltaTime;
    ++mTick;

    if (mTick == 60)
    {
        // 60만큼 프레임이 반복될동안 몇초가 흘렀는지를 이용해서 1초가 흘렀을경우 기대되는 프레임 수를 구한다.
        // 예를 들어 60프레임이 흐를 동안 mFPSTime이 0.2라면 0.2초가 흘렀다는 것이다.
        // 그렇다면 1초가 되었을 때 예상할 수 있는 프레임은 300프레임이 될 것이다.
        mFPS = mTick / mFPSTime;
        mFPSTime = 0.f;
        mTick = 0;
    }

    return mDeltaTime;
}
