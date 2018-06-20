#include <string>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

class duty
{
public:
	int gethp() {
		return hp;
	}
	int getene() {
		return ene;
	}
	void set(int hp, int ene) {
		this->hp = hp;
		this->ene = ene;
	}
	duty(int hp, int ene): hp(hp), ene(ene)
	{
	}
	duty()
	{
	}
	~duty()
	{
	}
	virtual void showdetail() {}
private:
	int hp, ene;
};


class smsl: public duty
{
public:

	smsl() {
		srand(time(NULL));
		set(max(((int)fabs(rand())) % 10, 1), max(((int)fabs(rand())) % 10, 1));
	}
	~smsl() {}
	virtual void showdetail() {
		cout << "�ֲ��ں���³��½�ϵ�����, ֻ�����߲��ܽ��ܵ�����...\n";
		getchar();
	}
private:

};


class jzsl: public duty {
public:
	jzsl() :duty() {}
	void Set(int stat) {
		if (stat == 0)
			set(10, 15);
		else if (stat == 1)
		{
			set(20, 25);
		}
		else if (stat == 2) {
			set(30, 30);
		}
	}
	~jzsl() {}
	virtual void showdetail() {
		cout << "���޿�ɭ���з�ӡ�Ĵ�ʦ�������������. �˷���������ʦ�������������Ĺ��..\n";
		getchar();
	}
private:

};