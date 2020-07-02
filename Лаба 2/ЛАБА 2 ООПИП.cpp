#include <fstream>
#include <iostream>
#include <vector>

char *pRever(std::string text);
void Task();

int main() {
	Task();
	system("pause");
	return 0;
}

void Task() {
	std::ifstream fin("cppFile.txt");
	std::ofstream fout("cppFile2.txt");
	char *pStr = 0;
	std::string str;
	pStr = new char[1024];
	while (fin) {
		fin.get(pStr, 1024);
		str += (char*)pStr;
		fout.seekp(0, std::ios::end);
	}
	fout << pRever(str);
	fin.close();
	fout.close();
	delete pStr;
}

char *pRever(std::string text) {
	int len = text.length();
	char *pNewArray = new char[len];
	for (int i = len; i > 0; i--) {
		pNewArray[i - 1] = text[len - i];
	}
	pNewArray[len] = '\0';
	return pNewArray;
	delete pNewArray;
}
