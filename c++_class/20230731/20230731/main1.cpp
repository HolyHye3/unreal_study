#include "GameManger.h"

/*
Ŭ������ static �������
�Ϲ� ��������� Ŭ������ �̿��ؼ� ��ü�� �����ϸ� ������ ��ü���� �޸𸮰� �Ҵ�ǰ� �ȴ�.
static ��������� Ŭ������ �̿��ؼ� ��ü�� �ƹ��� ���� �����ص� ������ 1���� ������ ��������� �ǰ� �� ��ü���� �̸� �����ؼ� ����ϰ� �ȴ�.
static ��������� Ŭ���� �ܺο� �ش� static ������ ����ϰڴٴ� ���Ǻκ��� �ݵ�� �ʿ��ϴ�.
	����Ÿ�� Ŭ�����̸�::�����̸�; ���� ������ �� �ִ�.
	����Ÿ�� Ŭ�����̸�::�����̸� = �ʱⰪ; ���ε� ������ �� �ִ�.
*/
/*
class CStatic
{
public:
	CStatic()
	{
	}

	~CStatic()
	{
	}
public:
	int mNumber1;
	static int mNumberStatic;
	static int mNumberStatic2;

public:
	void Output()
	{
		std::cout << "Output Fuction" << std::endl;
		std::cout << "mNumber1: " << mNumber1 << std::endl;
		std::cout << "mNumberStatic: " << mNumberStatic << std::endl;
		std::cout << "mNumberStatic2: " << mNumberStatic2 << std::endl;
	}

	static void OutputStatic()
	{
		std::cout << "OutputStatic Fuction" << std::endl;

		// static ����Լ��� this�� ����. �׷��� ������ �Ϲ� ��������� ������ �� ���� static ��������� ����� �����ϴ�.
		// std::cout << "mNumber1: " << mNumber1 << std::endl; // error
		std::cout << "mNumberStatic: " << mNumberStatic << std::endl;
		std::cout << "mNumberStatic2: " << mNumberStatic2 << std::endl;
	}
};

// Ŭ���� �ܺο� �ش� static ������ ����ϰڴٴ� ����
int CStatic::mNumberStatic;
int CStatic::mNumberStatic2;

int main()
{
	CStatic st1, st2;

	st1.mNumber1 = 100;
	st2.mNumber1 = 200;

	st1.mNumberStatic = 300;
	st2.mNumberStatic = 400;
	CStatic::mNumberStatic = 500;

	st1.Output();
	st2.Output();

	st1.OutputStatic();
	st2.OutputStatic();
	CStatic::OutputStatic();

	return 0;
}
*/

/*
class CSingleton
{
	// �ܺο��� �߰������� �������� ���ϵ��� �������� private�� ����
private:
	CSingleton()
	{
	}

	~CSingleton()
	{
	}

	// �̱��� ��ü�� �����ǰ� �ش� �޸� �ּҸ� �����ϱ� ���� ������ �����Ѵ�.
private:
	static CSingleton* mInst;

public:
	static CSingleton* GetInst()
	{
		
		// mInst�� nullptr�̶�� ���� �����Ҵ�� ��ü�� �޸� �ּҰ� ���� ���ٴ� ���̴�.
		// �׷��Ƿ� CSingleton Ŭ������ �ϳ� �����Ҵ��ϰ� �� �޸� �ּҸ� mInst������ �����صд�.
		// ������ mInst�� nullptr�� �ƴ϶�� �̹� �����Ҵ�� �޸� �ּҸ� ������ �����Ƿ� �׳� �� �ּҸ� ���ϸ����ش�.
		if (nullptr == mInst)
			mInst = new CSingleton;

		return mInst;

	}

	static void DestroyInst()
	{
		// nullptr�� �ƴҶ� delete�ϸ� ũ������ �߻��� �� �ִ�.
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

};
*/


int main()
{
	// 1. GetInst �Լ� ȣ���Ͽ� CGameManager �ν��Ͻ� �ʱ�ȭ
	// 2. �̱��� �ν��Ͻ��� ���� ������ ��ȯ
	// 3. �ش� �ν��Ͻ����� Init() �Լ�ȣ�� -> ���н� �̱��� �ν��Ͻ� �ı�
	if (CGameManager::GetInst()->Init() == false)
	{
		CGameManager::DestoryInst();
		return 0;
	}

	// �ʱ�ȭ ������ ���ӽ��� �Լ� ȣ��
	CGameManager::GetInst()->Run();

	// ���ӽ��� �� �̱��� �ν��Ͻ� �����Ͽ� �޸� ����
	CGameManager::DestoryInst();

	// CGameManager�� �̱��� ��ü�� �Ǿ����Ƿ� ��ü �����Ұ�
	/*
		CGameManager		Mgr;

		// ��ü ���� �ʱ�ȭ
		Mgr.Init();

		// ��ü ���� ����
		Mgr.Run();
	*/

	return 0;
}