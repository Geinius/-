#include <iostream>
#include "MyList.h"

class TestMyList {
private:
	MyList aTestList;
public:
	TestMyList();
	TestMyList(const TestMyList&);
	~TestMyList();
	void TestInputData();
	void TestPrintData();
	void TestGetCurrentSize();
	void TestGetMaxSize();
	void TestMaxSize();
	void TestCopyList();
	void TestAddItemList();
	void TestMoveItemList();
	void TestEqualsList();
};

TestMyList::TestMyList() { TestMyList::aTestList; }
TestMyList::TestMyList(const TestMyList& rTestList) { }
TestMyList::~TestMyList() { }
void TestMyList::TestInputData() {
	std::cout << "Enter the String(read to the first dot character ('.') or 255 characters):\n";
	aTestList.Input();
}
void TestMyList::TestPrintData() {
	std::cout << "Text in variable  ->  ";
	aTestList.Print();
}
void TestMyList::TestGetCurrentSize() {
	std::cout << "Current list size  =  "
		<< aTestList.GetSize() << std::endl;
}
void TestMyList::TestGetMaxSize() {
	std::cout << "Max list size  =  " << aTestList.GetMaxSize() << std::endl;
}
void TestMyList::TestMaxSize() {
	std::cout << "Max size test! Enter more than 255 characters:\n";
	aTestList.Input();
	std::cout << "Read data is  ->  ";
	aTestList.Print();
	std::cout << "Current list size  =  " << aTestList.GetSize()
		<< "\nMax list size  =  " << aTestList.GetMaxSize() << std::endl;
}
void TestMyList::TestCopyList() {
	TestInputData();
	MyList pTestList;
	pTestList = aTestList;
	std::cout << "One list has been assigned"
		<< " to another by the operator '=' (list1=list2)  ->  ";
	aTestList.Print();
	std::cout << "Copied list  ->  ";
	pTestList.Print();
}
void TestMyList::TestAddItemList() {
	char item = NULL;
	std::cout << "Enter one item  ->  ";
	std::cin >> item;
	aTestList + item;
	std::cout << "An item was added to the"
		<< "list using the operation '+' (list+char)  ->  ";
	aTestList.Print();
}
void TestMyList::TestMoveItemList() {
	aTestList--;
	std::cout << "Item in the list was "
		<< "deleted using the operation '--' (list--)  ->  ";
	aTestList.Print();
}
void TestMyList::TestEqualsList() {
	char item = '!';
	TestInputData();
	MyList pTestList;
	pTestList = aTestList;
	pTestList--;
	aTestList + item;
	std::cout << "Text entered with last character removed  ->  ";
	pTestList.Print();
	std::cout << "Copied text with a symbol added at the end '!' ->  ";
	aTestList.Print();
	std::cout << "Comparison of two texts with an operation '!=' (compare "
		<< "if the list characters do not match the characters"
		<< "in another list, then 'true')  ->  ";
	if (aTestList != pTestList) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}
