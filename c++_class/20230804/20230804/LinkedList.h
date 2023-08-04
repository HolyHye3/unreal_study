#pragma once

/*
	friend: �ٸ� Ŭ�������� �� Ŭ������ private�� ������ �� �ְ� ���ִ� ����̴�.

	- �迭�� ��,�� ����/������ �ַ� �Ͼ�� �ڷᱸ���� �迭�� ������. ����Ʈ�� �޸� ���� �Ҵ��� ������ �ֱ� ������ �迭���� ���� ���� �ִ�.
	- ������ �߰� ����/������ ����ϰ� �Ͼ�� �ڷᱸ���� ����Ʈ�� ������.
	- �迭�� ����Ʈ�� ���������������� �˰��־�� ��!

	- �ؼ�����: Ŭ���� ������� -> �Լ�
*/

// ���� ���� ����� ���
template <typename T>
class CLinkedListNode
{
	// CLinkedList Ŭ���� ���� ���
	template <typename T>
	friend class CLinkedList;

	// CLinkedListIterator Ŭ���� ���� ���
	template <typename T>
	friend class CLinkedListIterator;

private:
	CLinkedListNode():
		mNext(nullptr),
		mPrev(nullptr)
	{
	}
	~CLinkedListNode()
	{

	}

private:
	T					mData;		// ����� �����͸� ����
	CLinkedListNode<T>* mNext;		// ���� ���
	CLinkedListNode<T>* mPrev;		// ���� ���
};


// ���� ���� ����� �ݺ���. ��� ��ȸ�� ����Ѵ�.
template <typename T>
class CLinkedListIterator
{
	// CLinkedList ���� ���
	template <typename T>
	friend class CLinkedList;

public:
	CLinkedListIterator() :
		mNode(nullptr)
	{

	}

	~CLinkedListIterator()
	{
	}

private:
	// Iterator�� ���� �����Ǵ� ���� ��带 ����Ų��.
	CLinkedListNode<T>* mNode;

// ��, ����, ���� �� ������ �۾��� ���� ������ �����ε�
public:
	bool operator == (const CLinkedListIterator<T>& iter) const
	{
		return mNode == iter.mNode;
	}

	bool operator != (const CLinkedListIterator<T>& iter) const
	{
		return mNode != iter.mNode;
	}

	// ��������
	void operator ++ ()
	{
		mNode = mNode->mNext;
	}

	// ��������
	void operator ++ (int)
	{
		mNode = mNode->mNext;
	}

	// ��������
	void operator -- ()
	{
		mNode = mNode->mPrev;
	}

	// ��������
	void operator -- (int)
	{
		mNode = mNode->mPrev;
	}

	T& operator * ()
	{
		return mNode->mData;
	}

private:
	void operator = (CLinkedListNode<T>* Node)
	{
		mNode = Node;
	}
};


// ���� ���� ����Ʈ�� ��Ÿ���� ���� Ŭ�����̴�.
template <typename T>
class CLinkedList
{
public:

	
	CLinkedList()
	{
		mBegin = new CNode;
		mEnd = new CNode;

		mBegin->mNext = mEnd;
		mEnd->mPrev = mBegin;

		mCount = 0;
	}

	~CLinkedList()
	{
		CNode* Node = mBegin;

		while (nullptr != Node)
		{
			// ���� ��带 �̸� �޾Ƶд�. ���� ��带 �����ϰԵǸ� ���� ����� �ּҸ� �� �� ���� ������ ���� ��带 �̸� �޾Ƶΰ� ���� ��带 �����Ѵ�.
			CNode* Next = Node->mNext;

			delete Node;

			Node = Next;
		}
	}

private:
	// typeof: Ÿ���� ������ �Ѵ�.
	// �Ʒ��� CLinkListNode<T> Ÿ�� ��ſ� Node�� Ÿ���� ����� �� �ֵ��� �����Ѵ�.
	typedef CLinkedListNode<T> CNode;

public:
	// public���� typedef�� �صθ� Ŭ���� �ܺο����� �� Ÿ���� ����Ͽ� ������ ������ �� �ִ�.
	typedef CLinkedListIterator<T> iterator;

private:
	// ����� ���۰� ���� ���� ���� ����̴�.
	CNode<T>* mBegin;	// ����� ù ��° ���� ���
	CNode<T>* mEnd;		// ����� ���� ��Ÿ���� ��Ŀ
	int mCount;			// ����� ��� ���� ����

public:
	void push_back(const T& Data)
	{
		CNode* Node = new CNode;

		Node->mData = Data;

		// �ڿ� �߰��� End���� End����� ������� ���̿� �߰��� �ؾ��Ѵ�.
		CNode* Prev = mEnd->mPrev;

		Prev->mNext = Node;
		Node->mPrev = Prev;

		mEnd->mPrev = Node;
		Node->mNext = mEnd;

		++mCount;
	}


	void push_front(const T& Data)
	{
		CNode* Node = new CNode;

		Node->mData = Data;

		// �տ� �߰��� Begin���� Begin����� ������� ���̿� �߰��� �ؾ��Ѵ�.
		CNode* Next = mBegin->mNext;

		Next->mPrev = Node;
		Node->mNext = Next;

		mBegin->mNext = Node;
		Node->mPrev = mBegin;

		++mCount;
	}

	void pop_back()
	{
		// ������� ��� ����
		if (empty())
			return;

		CNode* DeleteNode = mEnd->mPrev;
		CNode* Prev = DeleteNode->mPrev;

		// ���� ����� �������� End��带 �����Ѵ�.
		Next->mPrev = mEnd;
		mEnd->mPrev = Prev;

		delete DeleteNode;

		--mCount;
	}

	void pop_front()
	{
		// ������� ��� ����
		if (empty())
			return;

		CNode* DeleteNode = mBegin->mNext;
		CNode* Next = DeleteNode->mNext;

		// ���� ����� �������� End��带 �����Ѵ�.
		Next->mPrev = mBegin;
		mBegin->mNext = Next;

		delete DeleteNode;

		--mCount;
	}

	int size() const
	{
		return mCount;
	}

	bool empty() const
	{
		return mCount == 0;
	}

	void clear()
	{
		// Begin�� End�� ������ ���� �����͸� �߰��ϱ� ���� ������ ��带 �����Ѵ�.
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			// ���� ��带 �̸� �޾Ƶд�. ���� ��带 �����ϰ� �Ǹ� ���� ����� �ּҸ� �� �� ���� ������ ���� ��带 �̸� �޾Ƶΰ� ���� ��带 �����Ѵ�.
			CNode* Next = Node->mNext;

			delete Node;

			Node = Next;
		}

		// Begin�� End�� �����Ѵ�.
		mBegin->mNext = mEnd;
		mEnd->mPrev = mBegin;

		mCount = 0;
	}

	iterator begin() const
	{
		iterator iter;
		iter.mNode = mBegin->mNext;
		return iter;
	}

	iterator end() const
	{
		iterator iter;
		iter.mNode = mEnd;
		return iter;
	}

	// erase �Լ��� ��带 �����ϰ� ������ ����� ���� ��带 iterator�� �����Ͽ� ��ȯ�Ѵ�.
	iterator erase(const T& Dtat)
	{
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			if (Node->mData == Data)
			{
				iterator	iter;
				iter = Node;

				return erase(iter);
			}

			Node = Node->mNext;
		}

		// �����Ͱ� ���� ��� end�� �����Ѵ�.
		return end();
	}

	iterator erase(const iterator& iter)
	{
		if (iter == end())
			return end();

		CNode* Prev = iter.mNode->mPrev;
		CNode* Next = iter.mNode->mNext;

		// ���� ����� �������� ������带 ���� �����Ѵ�.
		Prev->mNext = Next;
		Next->mPrev = Prev;

		// ���� ��带 �����Ѵ�.
		delete iter.mNode;

		// ������ ����� �������� iterator�� �����Ͽ� ��ȯ�Ѵ�.
		iterator result;
		result.mNode = Next;

		return result;
	}
};

