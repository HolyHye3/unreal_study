#include "GameManager.h"
#include "Timer.h"
#include "resource.h"

CGameManager* CGameManager::mInst = nullptr;
bool CGameManager::mLoop = true;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

// â�� �ʺ�� ���̸� �����Ͽ� ���� �����ڸ� �ʱ�ȭ
bool CGameManager::Init(HINSTANCE hInst)
{
	mhInst = hInst;

	mRS.Width = 1280;
	mRS.Height = 720;

    MyRegisterClass();

    AddWindow();

    mhDC = GetDC(mhWnd);

    // Ÿ�̸� �ʱ�ȭ
    CTimer::Init();

	return true;
}

int CGameManager::Run()
{

	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
	while (mLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// �޼����� ���� �κ�.
		else
		{
			Logic();
		}
	}

	return (int)msg.wParam;
}

// ���� ���� ������Ʈ
void CGameManager::Logic()
{
	float DeltaTime = CTimer::Update();

	Input(DeltaTime);       
	Update(DeltaTime);
	Collision(DeltaTime);   

    // FPS ȭ�鿡 ǥ�� �� ���� ������
	Render();
}

void CGameManager::Input(float DeltaTime)
{
}

void CGameManager::Update(float DeltaTime)
{
}

void CGameManager::Collision(float DeltaTime)
{
}

void CGameManager::Render()
{
	char FPS [256] = {};

	sprintf_s(FPS, "FPS : %.5f", CTimer::GetFPS());

	TextOutA(mhDC, 1000, 30, FPS, strlen(FPS));

}

//  ���ø����̼��� â Ŭ���� ���
ATOM CGameManager::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = mhInst;
    wcex.hIcon = LoadIcon(mhInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;// MAKEINTRESOURCEW(IDC_MY230808);
    wcex.lpszClassName = L"TestWindows";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

// ���� ���α׷� â�� ����� ǥ��
bool CGameManager::AddWindow()
{
    mhWnd = CreateWindowW(L"TestWindows", L"���� ��Ÿ����", WS_OVERLAPPEDWINDOW,
        -mRS.Width, 100, 1000, 600, nullptr, nullptr, mhInst, nullptr);

    if (!mhWnd)
    {
        return false;
    }

    RECT    rc = { 0, 0, mRS.Width, mRS.Height };

    // �޴�, ƽ������ ���� �����Ͽ� Ŭ���̾�Ʈ ������ ũ�Ⱑ ������ �ػ󵵸�ŭ
    // ������ �� �ְ� ���� ũ�⸦ �����ش�.
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(mhWnd, HWND_TOPMOST, -mRS.Width, 100, rc.right - rc.left,
        rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);

    ShowWindow(mhWnd, SW_SHOW);
    UpdateWindow(mhWnd);

    return true;
}

// �޽����� ó���ϴ� ������ ���ν��� �Լ�.
LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam,
    LPARAM lParam)
{
    switch (message)
    {
        // ����Ʈ
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        // HDC : ȭ�鿡 ���𰡸� �׸��� ����Ѵ�.
        HDC hdc = BeginPaint(hWnd, &ps);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        mLoop = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
