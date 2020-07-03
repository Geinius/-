#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main()
{
	string str;
	string massStr[256];
	cout << "Enter string" << endl;
	getline(cin, str);
	str += ' ';
	int indexForStr = 0;
	int indexForMassStr = 0;
	while (indexForStr != str.length()) {
		while (str[indexForStr] != ' ') {
			if (indexForStr != str.length()) {
				massStr[indexForMassStr] += str[indexForStr];
				indexForStr++;
			}
			else
				break;
		}
		for (int i = 0; i < massStr[indexForMassStr].size(); i++) {
			if (ispunct(massStr[indexForMassStr][i]) && massStr[indexForMassStr][i] != '_') {
				massStr[indexForMassStr] = "";
				indexForMassStr--;
				break;
			}
		}
		if (!massStr[indexForMassStr].empty()) {
			if (!isalpha(massStr[indexForMassStr][0])) {
				if (massStr[indexForMassStr][0] != '_') {
					massStr[indexForMassStr] = "";
					indexForMassStr--;
				}
			}
		}
		indexForMassStr++;
		indexForStr++;
	}
	string str2;
	for (int i = 0; i < sizeof(massStr) / sizeof(massStr[0]); i++) {
		if (!massStr[i].empty())
			str2 += massStr[i] + ' ';
		else
			break;
	}
	cout << str2 << endl;
	system("pause");
	return 0;
}
