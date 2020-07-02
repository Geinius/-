#include <stdio.h>
#include <iostream>

using namespace std;

class Persona {
public:
	Persona();
	Persona(const char* Name, int Age, float Coast);
	Persona(Persona const& obj);
	char* getName();
	int getAge();
	float getCoast();
	void setName(const char* name);
	void setAge(int age);
	void setCoast(float coast);
	~Persona();
private:
	char Name[20];
	int Age;
	float Coast;
};

void proCopy(Persona copy) {}
Persona::Persona() {
	setlocale(0, "");
	cout << "Конструктор без параметров вызван!" << endl;
	strcpy_s(Name, " ");
	Age = 0;
	Coast = 0;
}
Persona::Persona(const char* name, int age, float coast)
{
	setlocale(0, "");
	strcpy_s(Name, name);
	Age = age;
	Coast = coast;
	cout << "Имя: " << Name << " Возраст: " << Age << " Зарплата:" << Coast << "  -конструктор с прараметрами вызван" << endl;
}
Persona::Persona(Persona const& obj) {
	setlocale(0, "");
	strcpy_s(Name, obj.Name);
	Age;
	Coast;
	cout << "Имя: " << Name << " Возраст: " << Age << " Зарплата:" << Coast << "  -конструктор копирования вызван" << endl;
}
void Persona::setName(const char* name) {
	strcpy_s(Name, name);
}
char* Persona::getName() {
	return Name;
}
void Persona::setAge(int age) {
	Age = age;
}
int Persona::getAge() {
	return Age;
}
void Persona::setCoast(float coast) {
	Coast = coast;
}
float Persona::getCoast() {
	return Coast;
}
Persona::~Persona() {
	cout << "destructor for" << Name << endl;
}
void pro() {
	Persona Human;
	Persona gvr("Ilya", 18, 500.9);
	Persona* hum = new Persona("Jane", 23, 200.89); 
	proCopy(gvr);
	delete hum;
}
int main() {
	pro();
	system("pause");
	return 0;
}
