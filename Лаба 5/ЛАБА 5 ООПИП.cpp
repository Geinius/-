#include <iostream>
#include "TestMyList.h"

void DataBasicTest();
void OperationTest();

int main() {
	DataBasicTest();
	OperationTest();
	system("pause");
	return 0;
}

void DataBasicTest() {
	std::cout << "Test basic data\n\n\n";
	TestMyList* pTestData = new TestMyList();
	pTestData->TestPrintData();
	pTestData->TestInputData();
	pTestData->TestPrintData();
	pTestData->TestGetCurrentSize();
	TestMyList* pTestMaxSize = new TestMyList();
	pTestMaxSize->TestGetMaxSize();
	pTestMaxSize->TestMaxSize();
	std::cout << "\n\n\n";
	delete pTestData;
	delete pTestMaxSize;
}

void OperationTest() {
	std::cout << "Test binary operation\n\n\n";
	TestMyList* pTestBinaryOperation = new TestMyList();
	pTestBinaryOperation->TestCopyList();
	pTestBinaryOperation->TestAddItemList();
	pTestBinaryOperation->TestAddItemList();
	pTestBinaryOperation->TestMoveItemList();
	TestMyList* pTestEquals = new TestMyList();
	pTestEquals->TestEqualsList();
	std::cout << "\n\n\n";
	delete pTestBinaryOperation;
	delete pTestEquals;
}
