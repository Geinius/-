#include <QCoreApplication>
#include <QVector>
#include <iostream>
#include <QTextStream>

static QTextStream gOutput(stdout);

void Task1();
void Task2();

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
	Task1();
	Task2();
	return a.exec();
}

void Task1() {
	gOutput << "Task 1 - position changes in the array" << endl;
	QVector<double> vectorArray{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	QVector<double> temp(0);
	gOutput << "source array:" << endl;
	foreach(double item, vectorArray) {
		gOutput << item << "\t";
	}
	gOutput << endl << "result array:" << endl;
	for (int i = 1, j = vectorArray.size() - 2; i < vectorArray.size(), j >= 0; i += 2, j -= 2) {
		temp.push_back(vectorArray[i]);
		temp.push_front(vectorArray[j]);
	}
	foreach(double item, temp) {
		gOutput << item << "\t";
	}
	gOutput << endl;
}

void Task2() {
	gOutput << endl << "Task 2 - addition of elements modulo";
	QVector<double> vectorArray{ 5, 6 , 2, -2, 4, -5, 4 , 10 };
	gOutput << "source array:" << endl;
	foreach(double item, vectorArray) {
		gOutput << item << "\t";
	}
	gOutput << endl;
	double result = 0;
	QVector<double>::const_iterator iter = vectorArray.begin();
	while (iter != vectorArray.end()) {
		if (*iter < 0) {
			while (iter != vectorArray.end()) {
				result += abs(*iter);
				iter++;
			}
			break;
		}
		iter++;
	}
	gOutput << "answer = " << result;
}
