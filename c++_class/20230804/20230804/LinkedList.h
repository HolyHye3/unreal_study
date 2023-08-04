#pragma once

/*
	friend: 다른 클래스에서 이 클래스의 private에 접근할 수 있게 해주는 기능이다.

	- 배열의 앞,뒤 삽입/삭제가 주로 일어나는 자료구조는 배열이 빠르다. 리스트는 메모리 공간 할당의 과정이 있기 때문에 배열보다 느릴 수가 있다.
	- 하지만 중간 삽입/삭제가 빈번하게 일어나는 자료구조는 리스트가 빠르다.
	- 배열과 리스트의 성능차이점에대해 알고있어야 함!

	- 해석순서: 클래스 멤버변수 -> 함수
*/

// 이중 연결 목록의 노드
template <typename T>
class CLinkedListNode
{
	// CLinkedList 클래스 접근 허용
	template <typename T>
	friend class CLinkedList;

	// CLinkedListIterator 클래스 접근 허용
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
	T					mData;		// 노드의 데이터를 저장
	CLinkedListNode<T>* mNext;		// 다음 노드
	CLinkedListNode<T>* mPrev;		// 이전 노드
};


// 이중 연결 목록의 반복자. 목록 순회를 허용한다.
template <typename T>
class CLinkedListIterator
{
	// CLinkedList 접근 허용
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
	// Iterator에 의해 참조되는 현재 노드를 가르킨다.
	CLinkedListNode<T>* mNode;

// 비교, 증가, 감소 및 역참조 작업을 위한 연산자 오버로딩
public:
	bool operator == (const CLinkedListIterator<T>& iter) const
	{
		return mNode == iter.mNode;
	}

	bool operator != (const CLinkedListIterator<T>& iter) const
	{
		return mNode != iter.mNode;
	}

	// 전위연산
	void operator ++ ()
	{
		mNode = mNode->mNext;
	}

	// 후위연산
	void operator ++ (int)
	{
		mNode = mNode->mNext;
	}

	// 전위연산
	void operator -- ()
	{
		mNode = mNode->mPrev;
	}

	// 후위연산
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


// 이중 연결 리스트를 나타내는 메인 클래스이다.
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
			// 다음 노드를 미리 받아둔다. 현재 노드를 제거하게되면 다음 노드의 주소를 알 수 없기 때문에 다음 노드를 미리 받아두고 현재 노드를 제거한다.
			CNode* Next = Node->mNext;

			delete Node;

			Node = Next;
		}
	}

private:
	// typeof: 타입을 재정의 한다.
	// 아래는 CLinkListNode<T> 타입 대신에 Node로 타입을 사용할 수 있도록 지정한다.
	typedef CLinkedListNode<T> CNode;

public:
	// public으로 typedef을 해두면 클래스 외부에서도 이 타입을 사용하여 변수를 선언할 수 있다.
	typedef CLinkedListIterator<T> iterator;

private:
	// 목록의 시작과 끝을 위한 더미 노드이다.
	CNode<T>* mBegin;	// 목록의 첫 번째 실제 노드
	CNode<T>* mEnd;		// 목록의 끝을 나타내는 마커
	int mCount;			// 목록의 노드 수를 추적

public:
	void push_back(const T& Data)
	{
		CNode* Node = new CNode;

		Node->mData = Data;

		// 뒤에 추가는 End노드와 End노드의 이전노드 사이에 추가를 해야한다.
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

		// 앞에 추가는 Begin노드와 Begin노드의 다음노드 사이에 추가를 해야한다.
		CNode* Next = mBegin->mNext;

		Next->mPrev = Node;
		Node->mNext = Next;

		mBegin->mNext = Node;
		Node->mPrev = mBegin;

		++mCount;
	}

	void pop_back()
	{
		// 비어있을 경우 제외
		if (empty())
			return;

		CNode* DeleteNode = mEnd->mPrev;
		CNode* Prev = DeleteNode->mPrev;

		// 지울 노드의 이전노드와 End노드를 연결한다.
		Next->mPrev = mEnd;
		mEnd->mPrev = Prev;

		delete DeleteNode;

		--mCount;
	}

	void pop_front()
	{
		// 비어있을 경우 제외
		if (empty())
			return;

		CNode* DeleteNode = mBegin->mNext;
		CNode* Next = DeleteNode->mNext;

		// 지울 노드의 이전노드와 End노드를 연결한다.
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
		// Begin과 End를 제외한 실제 데이터를 추가하기 위해 생성한 노드를 제거한다.
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			// 다음 노드를 미리 받아둔다. 현재 노드를 제거하게 되면 다음 노드의 주소를 알 수 없기 때문에 다음 노드를 미리 받아두고 현재 노드를 제거한다.
			CNode* Next = Node->mNext;

			delete Node;

			Node = Next;
		}

		// Begin과 End를 연결한다.
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

	// erase 함수는 노드를 제거하고 제거한 노드의 다음 노드를 iterator로 구성하여 반환한다.
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

		// 데이터가 없을 경우 end를 리턴한다.
		return end();
	}

	iterator erase(const iterator& iter)
	{
		if (iter == end())
			return end();

		CNode* Prev = iter.mNode->mPrev;
		CNode* Next = iter.mNode->mNext;

		// 지울 노드의 이전노드와 다음노드를 서로 연결한다.
		Prev->mNext = Next;
		Next->mPrev = Prev;

		// 현재 노드를 제거한다.
		delete iter.mNode;

		// 제거한 노드의 다음노드로 iterator를 구성하여 반환한다.
		iterator result;
		result.mNode = Next;

		return result;
	}
};

