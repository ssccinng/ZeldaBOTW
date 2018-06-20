#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

class Sword
{
public:
	Sword(int attark) : attark(attark)
	{
	}

	~Sword()
	{
	}
	virtual bool dec() = 0;
	void printline(string str[], int len) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < 36 - str[i].length() / 2; ++j) cout << " ";
			cout << str[i] << endl;
			Sleep(1500);
		}
	}
private:
	int attark;
};

class Mastersword: Sword
{
public:
	Mastersword(int arratk): Sword(arratk) {
		HPneed = 30;
	}
	~Mastersword() {

	}

	bool dec() {
		show();
		return true;
	}

private:
	void show() {
		for (int i = 0; i < 10; ++i) {

			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n";
			cout << "                             体力: " << 30 - i << endl;
			Sleep(500);
			
		}
		Sleep(2000);
		for (int i = 10; i < 30; ++i) {
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n";
			cout << "                             体力: " << 30 - i << endl;
			Sleep(200);
		}
		Sleep(4000);
		system("cls");
		cout << "\n\n\n\n\n\n\n";

		printline(new string[7]{"恭喜你...", "你已经完成了剑之试炼...", "大师剑将展现出新的光辉...", "...", "...", "", ""}, 7);
	}
	int HPneed;
	
};