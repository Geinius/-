#pragma once
#include <iostream>
#define MAX 255

struct list {
	char letter;
	list* pNext;
};

class MyList {
private:
	list* apHead;
	list* apTail;
	int			aSize;
	static const int	MAX_SIZE;
	void Add(char);
	MyList& Copy(const MyList&);
public:
	MyList();
	MyList(const MyList&);
	~MyList();
	int			GetSize() const;
	int			GetMaxSize() const;
	void		Input();
	void		Print();
	void		operator+(char);
	void		operator--(int);
	bool		operator!=(MyList&);
	MyList& operator=(MyList&);
};

const int MyList::MAX_SIZE = MAX;
MyList::MyList() {
	apHead = nullptr;
	apTail = nullptr;
	aSize = 0;
}
MyList::MyList(const MyList& rMyList) {
	Copy(rMyList);
}
MyList::~MyList() {
	while (apHead != nullptr) {
		list* pTemp = apHead->pNext;
		delete apHead;
		apHead = pTemp;
	}
}
int MyList::GetSize()		const { return aSize; }
int MyList::GetMaxSize()	const { return MAX_SIZE; }
void MyList::Add(char symbol) {
	list* pTemp = new list;
	pTemp->letter = symbol;
	pTemp->pNext = nullptr;
	if (apHead != nullptr) {
		apTail->pNext = pTemp;
		apTail = pTemp;
	}
	else {
		apHead = pTemp;
		apTail = pTemp;
	}
	aSize++;
}
MyList& MyList::Copy(const MyList& rMyList) {
	if (rMyList.apHead != nullptr) {
		list* pTemp = new list;
		pTemp->letter = rMyList.apHead->letter;
		pTemp->pNext = nullptr;
		apHead = pTemp;
		apTail = pTemp;
		list* pNextPointer = new list;
		pNextPointer = rMyList.apHead->pNext;
		while (pNextPointer) {
			apTail->pNext = new list;
			apTail = apTail->pNext;
			apTail->letter = pNextPointer->letter;
			pNextPointer = pNextPointer->pNext;
		}
		apTail->pNext = nullptr;
		delete pNextPointer;
	}
	else {
		apHead = nullptr;
		apTail = nullptr;
		aSize = 0;
	}
	aSize = rMyList.aSize;
	return *this;
}
void MyList::Input() {
	char symbol = NULL;
	while (aSize < MAX_SIZE) {
		symbol = std::cin.get();
		if ('.' == symbol) {
			break;
		}
		else {
			Add(symbol);
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void MyList::Print() {
	if (!apHead) {
		std::cout << "List is Empty!\n";
	}
	else {
		int counter = 0;
		list* pHead = apHead;
		list* pTail = nullptr;
		do {
			std::cout << pHead->letter;
			pTail = pHead->pNext;
			pHead = pTail;
			counter++;
		} while (counter != aSize);
		std::cout << std::endl;
	}
}
inline void MyList::operator+(char symbol) {
	Add(symbol);
}
inline void MyList::operator--(int i) {
	if (nullptr == apTail->pNext) {
		int counter = 1;
		list* pTail = apHead;
		while (counter != aSize - 1) {
			pTail = pTail->pNext;
			counter++;
		}
		delete apTail;
		pTail->pNext = nullptr;
		apTail = pTail;
		aSize--;
	}
	else {
		std::cout << "List is empty!\n";
	}
}
inline bool MyList::operator!=(MyList& rMyList) {
	if ((!apHead) || !rMyList.apHead) {
		std::cout << "Some List is Empty!\n";
	}
	else {
		if (aSize != rMyList.aSize) {
			return true;
		}
		else {
			list* pTemp = apHead;
			list* pTempSecond = rMyList.apHead;
			while (pTemp->pNext != nullptr) {
				if (pTemp->letter != pTempSecond->letter) {
					return true;
				}
				pTemp = pTemp->pNext;
				pTempSecond = pTempSecond->pNext;
			}
		}
		return false;
	}
	return false;
}
inline MyList& MyList::operator=(MyList& rMyList) {
	return Copy(rMyList);
}
