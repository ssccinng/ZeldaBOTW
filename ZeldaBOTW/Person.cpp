#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;



class Person {
private:
	string name;
public:
	void tell(string a) {
		cout << name << ": " << a << endl;
		Sleep(2000);

	}
	void printline(string str[], int len) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < 36 - str[i].length() / 2; ++j) cout << " ";
			cout << str[i] << "\n";
			Sleep(1500);
		}
	}
	Person(string name) : name(name) {}
};