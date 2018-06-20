#include "Person.h"
#include "stringtool.h"
#include "DTime.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

class Link : Person
{
public:
	Link() : Person("Link")
	{
		ruby = 100;
		HP = HPlim;
		energy = energylim;
		HPex = energyex = spirit_orb = spirit_orbget = 0;
		mastersword_stat = 0;
	}

	Link(int HPlim, int energylim, int ruby, int energy, int HP, int energyex, int HPex, int sorb, int orbget, int mastersword_stat) : Person("Link")
	{
		this->energy = energy;
		this->energylim = energylim;
		this->HPlim = HPlim;
		this->ruby = ruby;
		this->HP = HP;
		this->energyex = energyex;
		this->HPex = HPex;
		this->spirit_orb = sorb;
		this->spirit_orbget = orbget;
		this->mastersword_stat = mastersword_stat;
		sort();
	}

	bool work(int e) {

		if (energy >= e) {
			energy -= e;
			return true;
		}
		else {
			e -= energy;
			energy = 0;
			if (energyex > 0) {
				if (energyex >= e) {
					energyex -= e;
					e = 0;
					return true;
				}
				else {
					e -= energyex;
					energyex = 0;
				}
			}
		}
		cout << "��������, ִ��ʧ��";
		getchar();
		return false;
	}
	bool isenouf() {
		return HPlim == HP && energy == energylim;
	}

	bool hurt(int e) {
		if (HPex >= e) {
			HPex -= e;
			return true;
		}
		else {
			e -= HPex;
			HPex = 0;
			if (HP > 0) {
				if (HP >= e) {
					HP -= e;
					e = 0;
					return true;
				}
				else {
					e -= HP;
					HP = 0;
				}
			}
		}
		cout << "��������, ִ��ʧ��";
		getchar();
		return false;
	}
	void rest() {
		energy = min(energy + 1, energylim);
		printline(new string[4]{ "����", "yo~" }, 2);
	}
	void jzslpj() {
		mastersword_stat++;
		cout << "              ��ʦ���õ��˼�ǿ";
		getchar();
	}
	void pjsm() {
		spirit_orb++;
		spirit_orbget++;

		printline(new string[9]{ "��", "...", "?", "����", "��", "", "", "��������ɹ��ƽ�", ""}, 9);
	}
	void sleepnight() {
		if (pay(20)) {
			energy = energylim;
			HP = HPlim;
			printline(new string[1]{ "һ���ȥ��..." }, 1);
		}

	}

	bool pay(int m) {
		if (ruby >= m) {
			ruby -= m;
			return true;
		}
		cout << "¬�Ȳ���! ����ʧ��\n";
		getchar();
		return false;
	}

	int getorbs() {
		return spirit_orbget;
	}
	int getorb() {
		return spirit_orb;
	}

	void evo(int type) {
		system("cls");
		if (spirit_orb < 2) {
			cout << "���������Ŀ��黹������..";
			getchar();
			return;
		}
		spirit_orb -= 2;
		if (type) {
			HPlim++;
			HP = HPlim;
		}
		else {
			energylim++;
			energy = energylim;
		}
		cout << "��������õ��˼�ǿ..";
		getchar();
	}
	void addruby(int a) {
		ruby += a;
	}
	void change(int type) {
		system("cls");
		if (!pay(20)) {
			return;
		}
		if (type) {
			if (HPlim > 6) {
				HPlim--;
				energylim++;
				energy = energylim;
				HP = HPlim;

			}
			else {
				cout << "ת��ʧ��!";
				getchar();
				return;
			}
		}
		else {
			if (energylim > 6) {
				HPlim++;
				energylim--;
				energy = energylim;
				HP = HPlim;
			}
			else {
				cout << "ת��ʧ��!";
				getchar();
				return;
			}
		}
		cout << "ת���ɹ�!";
		getchar();
		return;
	}

	void sleepnight2() {
		if (pay(80))
		{
			energy = energylim;
			HP = HPlim;
			if (energyex < 6) {
				energyex = 6;
			}
			if (HPex < 6) {
				HPex = 6;
			}
			printline(new string[6]{ "��.", "��", "���", "��", "����" , "һ���ȥ��..." }, 6);
		}

	}

	~Link()
	{
	}
	bool Save(DTime Time) {
		ofstream ost("data", ios::out);
		system("cls");
		if (ost)
		{
			ost << "1   " << ruby << " " << energy << " " << HP << " " << HPlim << " " << energylim << " " << HPex << " " << energyex << " " << Time.getday() << " " << Time.gettime() << " " << spirit_orb << " " << spirit_orbget << " " << mastersword_stat;
			ost.close();
			cout << "����ɹ�\n";
			getchar();
			return true;
		}
		cout << "����ʧ��\n";
		ost.close();
		return false;
	}

	int getmaster() {
		return mastersword_stat;
	}

	void showdetail() {
		string pre = "�ֿ�";
		int index = 0;
		system("cls");
		string str[100];
		str[index++] = dirc(dirc("����: ", HP), dirc(" / ", HPlim));
		if (HPex > 0)   str[index++] = dirc("��������: ", HPex);
		str[index++] = dirc(dirc("����: ", energy), dirc(" / ", energylim));
		if (energyex > 0)   str[index++] = dirc("���⾫��: ", energyex);
		str[index++] = dirc("¬��: ", ruby);
		str[index++] = dirc("����ͨ��֤: ", spirit_orb);
		str[index++] = dirc(dirc("��������: ", spirit_orbget), dirc("/ ", 120));
		if (mastersword_stat != 0) {
			str[index++] = dirc("��ʦ���׶�: ", mastersword_stat);
		}
		for (int j = 0; j < 32 - pre.length() / 2; ++j) cout << " ";

		cout << pre << "\n";
		cout << "               ";
		cout << "*************************************\n";
		for (int i = 0; i < index; ++i) {
			cout << "               ";

			cout << "*";
			for (int j = 0; j < (32 - str[i].length()) / 2; ++j) {
				cout << ' ';
			}
			cout << "  ";
			cout << str[i];
			for (int j = 0; j < (35 - str[i].length()) / 2; ++j) {
				cout << ' ';
			}
			//for (int j = 0; j < 21 - str[i].length(); ++j) cout << " ";
			cout << "*\n";
			//cout 
		}
		cout << "               ";
		cout << "*************************************\n";

		getchar();
	}
private:
	int ruby, energy, HP;
	int HPlim = 6, energylim = 10;
	int HPex, energyex;
	int spirit_orb = 0;
	int spirit_orbget = 0;
	int mastersword_stat = 0;
	void sort() {
		energy = min(energy, energylim);
		HP = min(HP, HPlim);
	}


};
