/*
  KHURAM ZAHID
  L10-4381
  "DOUBLY CIRCULAR LINKED LIST"
  WITH TEMPLATES and STACK and QUEUE
  CopyRight. All Rights Reserved.
  NOTE:
       Please use Bloodshed Dev C++ compiler. I have tested the code
       and it works perfectly
*/
#include <iostream>
using namespace std;
template <class KeyType>
class DCListNode
{
	public:
		DCListNode(KeyType pdata = 0);
		void setData(KeyType pVal);
		KeyType getData();
		DCListNode* getNext();
		void setNext(DCListNode* x);
		DCListNode* getPrevious();
		void setPrevious(DCListNode* x);
	private:
		KeyType data;
		DCListNode *next ;
		DCListNode *previous ;
};
template <class KeyType>
class DCList
{
	public:
		DCList();
		DCListNode<KeyType>* GetFirst();
		void Insert(DCListNode<KeyType>* pNew, DCListNode<KeyType>* pBefore = NULL);
		void Delete(DCListNode<KeyType>* pToBeDeleted, DCListNode<KeyType>* pPrev = NULL);
		void printList(DCListNode<KeyType>* pFirst = NULL);
	private:
		DCListNode<KeyType> *first ;
};
template <class KeyType>
class Stack
{
	public:
		Stack(int maxsize = 0);
		bool IsFull();
		bool IsEmpty();
		void Push(KeyType item);
		KeyType* Pop();
		void PushNode(DCListNode<KeyType>* item);
		DCListNode<KeyType> PopNode();
	private:
		int top;
		DCList<KeyType>* list;
		int maxsize;
};
template <class KeyType>
class Queue
{
	public:
		Queue(int maxsize = 0);
		bool IsFull();
		bool IsEmpty();
		void Put(KeyType item);
		KeyType* Get();
		void PutNode(DCListNode<KeyType>* item);
		DCListNode<KeyType> GetNode();
	private:
		int top;
		DCList<KeyType>* list;
		int maxsize;
};
int main()
{
    cout<<"\n STACK: \n";
	DCListNode<int>* node1 = new DCListNode<int>(30);
	Stack<int> *s = new Stack<int>(3);
	cout<<"\nAttempting to PUSH 2...\n";
	s->Push(2);
	cout<<"\nAttempting to PUSH 30...\n";
	s->PushNode(node1);
	cout<<"\nAttempting to PUSH 40...\n";
	s->Push(40);
	cout<<"\nAttempting to PUSH 44...\n";
	s->Push(44);
	cout<<"\nAttempting to POP 40...\n";
	cout<<s->PopNode().getData()<<endl;
	cout<<"\nAttempting to POP 30...\n";
	cout<<*(s->Pop())<<endl;
	cout<<"\nAttempting to POP 2...\n";
	cout<<*(s->Pop())<<endl;
	cout<<"\nAttempting to POP VOID...\n";
	s->Pop();
	//-------------------------------------
    cout<<"\n QUEUE: \n";
	DCListNode<int>* node2 = new DCListNode<int>(30);
	Queue<int> *q = new Queue<int>(3);
	cout<<"\nAttempting to PUT 2...\n";
	q->Put(2);
	cout<<"\nAttempting to PUT 30...\n";
	q->PutNode(node2);
	cout<<"\nAttempting to PUT 40...\n";
	q->Put(40);
	cout<<"\nAttempting to PUT 44...\n";
	q->Put(44);
	cout<<"\nAttempting to GET 2...\n";
	cout<<q->GetNode().getData()<<endl;
	cout<<"\nAttempting to GET 30...\n";
	cout<<*(q->Get())<<endl;
	cout<<"\nAttempting to GET 40...\n";
	cout<<*(q->Get())<<endl;
	cout<<"\nAttempting to GET VOID...\n";
	q->Get();
	system("pause");
	return 0;
}
//----------------------------------------------------
template <class KeyType>
DCListNode<KeyType>::DCListNode(KeyType element)
{
	data = element;
	previous = this;
	next = this;
}
template <class KeyType>
void DCListNode<KeyType>::setData(KeyType pVal)
{
	DCListNode::data = pVal;
}
template <class KeyType>
KeyType DCListNode<KeyType>::getData()
{
	return data;
}
template <class KeyType>
void DCListNode<KeyType>::setPrevious(DCListNode<KeyType>* x)
{
	previous = x;
}
template <class KeyType>
DCListNode<KeyType>* DCListNode<KeyType>::getPrevious()
{
	return previous;
}
template <class KeyType>
void DCListNode<KeyType>::setNext(DCListNode<KeyType>* x)
{
	next = x;
}
template <class KeyType>
DCListNode<KeyType>* DCListNode<KeyType>::getNext()
{
	return next;
}
//----------------------------------------------------
template <class KeyType>
DCList<KeyType>::DCList()
{
	first = NULL;
}
template <class KeyType>
DCListNode<KeyType>* DCList<KeyType>::GetFirst()
{
	return first;
}
template <class KeyType>
void DCList<KeyType>::Insert(DCListNode<KeyType>* pNew, DCListNode<KeyType>* pBefore)
{
	pBefore = first;
	if(first != NULL)
	{
		pNew->setNext(pBefore);
		pNew->setPrevious(pBefore->getPrevious());
		(pBefore->getPrevious())->setNext(pNew);
		pBefore->setPrevious(pNew);
	}
	first = pNew;
}
template <class KeyType>
void DCList<KeyType>::Delete(DCListNode<KeyType>* pToBeDeleted, DCListNode<KeyType>* pPrev)
{
	if(first == pToBeDeleted)
		first = pToBeDeleted->getNext();
	else
	{
        pPrev = pToBeDeleted->getPrevious();
		pPrev->setNext(pToBeDeleted->getNext());
		(pToBeDeleted->getNext())->setPrevious(pPrev);
	}
	delete pToBeDeleted;
}
template <class KeyType>
void DCList<KeyType>::printList(DCListNode<KeyType>* pFirst)
{
	//system("cls");
	pFirst = first;
	DCListNode<KeyType>* pNext = pFirst;
	cout<<"The DOUBLY CIRCULAR LINKED LIST:\n";
	int count = 1;
	while(true)
	{
		cout<<count++<<") "<<pNext->getData()<<endl;
		pNext = pNext->getNext();
		if(pNext==first)
			break;
	}
}
//--------------------------------------------------------------
template <class KeyType>
Stack<KeyType>::Stack(int maxsize)
{
	top = -1;
	Stack::maxsize = maxsize;
	list = new DCList<KeyType>();
}
template <class KeyType>
bool Stack<KeyType>::IsFull()
{
	if(maxsize==0)
		return false;
	if(top == maxsize-1)
		return true;
	return false;
}
template <class KeyType>
bool Stack<KeyType>::IsEmpty()
{
	if(top == -1)
		return true;
	return false;
}
template <class KeyType>
void Stack<KeyType>::Push(KeyType item)
{
	if(IsFull()==false)
	{
		DCListNode<KeyType> *pNew = new DCListNode<KeyType>(item);
		list->Insert(pNew);
		top++;
		return;
	}
	cout<<"\nSorry, the Stack has reached its limit.\n";
}
template <class KeyType>
KeyType* Stack<KeyType>::Pop()
{
	if(IsEmpty()==false)
	{
		KeyType* val = new KeyType;
		*val = (list-> GetFirst())->getData();
		list->Delete(list->GetFirst());
		top--;
		return val;
	}
	cout<<"\nSorry, the Stack is Empty.\n";
	//return NULL;
}
template <class KeyType>
void Stack<KeyType>::PushNode(DCListNode<KeyType>* item) // ok
{
	if(IsFull()==false)
	{
		list->Insert(item);
		top++;
		return;
	}
	cout<<"\nSorry, the Stack has reached its limit.\n";
}
template <class KeyType>
DCListNode<KeyType> Stack<KeyType>::PopNode()
{
	if(IsEmpty()==false)
	{
		DCListNode<KeyType> val;
		val = *(list-> GetFirst());
		list->Delete(list->GetFirst());
		top--;
		return val;
	}
	cout<<"\nSorry, the Stack is Empty.\n";
	//return NULL;
}
//--------------------------------------------------------------------------
template <class KeyType>
Queue<KeyType>::Queue(int maxsize)
{
	top = -1;
	Queue::maxsize = maxsize;
	list = new DCList<KeyType>();
}
template <class KeyType>
bool Queue<KeyType>::IsFull()
{
	if(maxsize==0)
		return false;
	if(top == maxsize-1)
		return true;
	return false;
}
template <class KeyType>
bool Queue<KeyType>::IsEmpty()
{
	if(top == -1)
		return true;
	return false;
}
template <class KeyType>
void Queue<KeyType>::Put(KeyType item)
{
	if(IsFull()==false)
	{
		DCListNode<KeyType> *pNew = new DCListNode<KeyType>(item);
		list->Insert(pNew);
		top++;
		return;
	}
	cout<<"\nSorry, the Queue has reached its limit.\n";
}
template <class KeyType>
KeyType* Queue<KeyType>::Get()
{
	if(IsEmpty()==false)
	{
		KeyType* val = new KeyType;
		*val = (list-> GetFirst()->getPrevious())->getData();
		list->Delete(list->GetFirst()->getPrevious());
		top--;
		return val;
	}
	cout<<"\nSorry, the Queue is Empty.\n";
	//return NULL;
}
template <class KeyType>
void Queue<KeyType>::PutNode(DCListNode<KeyType>* item) // ok
{
	if(IsFull()==false)
	{
		list->Insert(item);
		top++;
		return;
	}
	cout<<"\nSorry, the Queue has reached its limit.\n";
}
template <class KeyType>
DCListNode<KeyType> Queue<KeyType>::GetNode()
{
	if(IsEmpty()==false)
	{
		DCListNode<KeyType> val;
		val = *(list->GetFirst()->getPrevious());
		list->Delete(list->GetFirst()->getPrevious());
		top--;
		return val;
	}
	cout<<"\nSorry, the Queue is Empty.\n";
}
