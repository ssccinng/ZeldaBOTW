#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <conio.h>
#include "Link.h"
#include "DTime.h"
#include "Sword.h"
#include "duty.h"


// #include <stdio.h

using namespace std;

void init();
void start();
void shiny1(string );
void shiny2(string );
void info();
void gamestart(Link, DTime );
void Theend();
void EXIT();
void printline(string[], int);
void duringtime(int);
int	 menu(string[], int, string, int);


int main(int argc, char const *argv[])
{
	// /* code */C:\Users\dell\Documents\Visual Studio 2015\Projects\Zelda\Zelda\Main.cpp
	init();
	return 0;
}



void init() {
	ifstream infile;   //������
	ofstream outfile;   //�����
	infile.open("data", ios::in);
	if (!infile) {
		start();
		info();
		Link player = Link();
		gamestart(player, DTime(1, 8));

		//�Զ�����
	}
	else {
		int a = 3;
		infile >> a;
		if (a != 1) {
			start();
			info();
			Link player = Link();
			gamestart(player, DTime(1, 8));

		}
		else {
			string m1[] = { "��ʼ��Ϸ", "��Ϸ˵��", "ɾ���浵", "�˳���Ϸ" };
			int flag = 1;
			Link player1;
			int ruby = 100, energy = 6, HP = 6;
			int HPlim = 6, energylim = 6;
			int HPex = 0, energyex = 0;
			int day = 1, time = 8;
			int spirit_orb = 0;
			int spirit_orbget = 0;
			int master_swordstat = 0;
			while (flag) {
				switch (menu(m1, 4, "The Legend of Zelda", 0))
				{
				case 0:

					infile >> ruby >> energy >> HP >> HPlim >> energylim >> HPex >> energyex >> day >> time >> spirit_orb >> spirit_orbget >> master_swordstat;
					player1 = Link(HPlim, energylim, ruby, energy, HP, energyex, HPex, spirit_orb, spirit_orbget, master_swordstat);
					infile.close();
					gamestart(player1, DTime(day, time));
					break;
				case 1:
					info();
					break;
				case 2:
					if (!menu(new string[2]{ "��", "��" }, 2, "���Ҫɾ���浵��(�޷��ָ���)", 0)) {
						infile.close();
						if (remove("data") == 0)
						{
							cout << "ɾ���ɹ�, ��������˳���Ϸ" << endl;
							system("pause");
							flag = 0;
						}
						else
						{
							cout << "ɾ��ʧ�ܣ� (δ֪ԭ��)" << endl;
						}
					}
					break;

				case 3:
					EXIT();
					break;
				case 4:
					EXIT();
				default:
					break;
				}
			}
		}
	}
}
void start() {
	cout << "��⵽��������������....\n";
	Sleep(1000);
	cout << "���ڳ�ʼ����, ���Ժ�";
	for (int i = 0; i < 5; ++i) Sleep(1000), cout << ".";
	cout << "\n";
	Sleep(2000);
	system("cls");
	cout << "��ʼ�����!";
	Sleep(1000);
	system("cls");
	void(*shiny[2])(string a) = { shiny1, shiny2 };
	cout << "\n";

	string a = "          ", b = "          ";
	for (int i = 0; i < 15; ++i) {
		a += "**..";
		b += "..**";
	}
	a += "\n";
	b += "\n";
	for (int i = 0; i < 10; ++i) {
		Sleep(500), cout << b;
		Sleep(500);
		cout << a;
	}

	Sleep(1000);
	system("cls");
	string f[] = { "","","","","", "������...." ,"", "������....", "�ֿ�", "����ȴ�����....", "������..", "�ֿ�","","","","","...","","","" };
	int index = 0;
	for (string a : f) {
		shiny[index++ % 2](a);
		Sleep(1500);
		system("cls");
	}
	ofstream fout("data");
	fout << "1";
	fout.close();
}

void shiny1(string text) {
	cout << "\n";
	string a = "          ", b = "          ";
	for (int i = 0; i < 15; ++i) {
		a += "**..";
		b += "..**";
	}
	a += "\n";
	b += "\n";
	for (int i = 0; i < 5; ++i)
		cout << a << b;
	string c = "          ";
	for (int i = 0; i < (60 - text.length()) / 2; ++i)
		c += "-";
	c += text;
	for (int i = 0; i < (60 - text.length()) / 2; ++i)
		c += "-";
	cout << c << '\n';
	for (int i = 0; i < 5; ++i)
		cout << a << b;
}

void shiny2(string text) {
	cout << "\n";
	string a = "          ", b = "          ";
	for (int i = 0; i < 15; ++i) {
		a += "**..";
		b += "..**";
	}
	a += "\n";
	b += "\n";
	for (int i = 0; i < 5; ++i)
		cout << b << a;
	string c = "          ";
	for (int i = 0; i < (60 - text.length()) / 2; ++i)
		c += "-";
	c += text;
	for (int i = 0; i < (60 - text.length()) / 2; ++i)
		c += "-";
	cout << c << '\n';
	for (int i = 0; i < 5; ++i)
		cout << b << a;
}

int menu(string str[], int len, string pre = "", int index = 0) {
	char ch = 0;
	do {
		if (ch == 72) {
			index--;
		}
		else if (ch == 80) {
			index++;
		}
		system("cls");
		for (int j = 0; j < 32 - pre.length() / 2; ++j) cout << " ";

		cout << pre << "\n";
		if (index < 0) {
			index = 0;
		}
		if (index >= len) {
			index = len - 1;
		}
		cout << "               ";
		cout << "*************************************\n";
		for (int i = 0; i < len; ++i) {
			cout << "               ";

			cout << "*";
			for (int j = 0; j < (32 - str[i].length()) / 2; ++j) {
				cout << ' ';
			}
			if (i == index) {
				cout << "> ";
			}
			else {
				cout << "  ";
			}
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

	} while ((ch = _getch()) != '\r');
	system("cls");
	return index;
}

void EXIT() {
	exit(0);
}

void info() {
	string f[] = {
		"100��ǰ�ĺ���³, ���ܵ��˼�ũ���������...",
		"��λӢ��, ȫ��ɥ��",
		"100���Ľ���..",
		"�ֿ���ΪΨһ�Ҵ��Ӣ��, �ڸ�������...",
		"�ܵ���������ٻ�, ���˹���..",
		"�ڲ��ϵ�ĥ��֮��",
		"�ֿ˽����������, ����˼�ũ",
		"ֻ����100��ǰ��ս��...",
		"��Զ��������...", "...", "...", "���������ܶ���", "ϣ���ܼ�����..", "��������", "" , "" };
	printline(f, 16);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n";
	printline(new string[5]{"�����ﴫ˵...", "��Ұ֮Ϣ", "�����İ���", "" , "" }, 5);
}
void gamestart(Link player, DTime Time) {
	string m1[] = { "�鿴״̬", "��ĥʱ��", "��Ϣ(һСʱ)", "����", "��", "������Ϸ", "�˳���Ϸ" };
	
	int flag = 1;
	int index = 0;
	while (flag) {
		ostringstream a;
		a << "��" << Time.getday() << "��" << " " << Time.gettime() << "��";
		smsl sm;
		jzsl sl;
		Mastersword mstswd(30);
		switch (index = menu(m1, 7, a.str(), index)) {
		case 0:
			player.showdetail();
			break;
		case 1:
			system("cls");
			int bed;
			bed = menu(new string[3]{ "��ͨ��", "�Ҹ�������ˮ��", "����" }, 3, "Ҫ��ʲô��?");
			if (bed == 2) continue;
			int nt;
			nt = menu(new string[5]{ "����", "����", "����", "����" }, 5, "��ĥ��ʲôʱ��?");
			if (nt == 3) continue;
			if (bed == 0) {
				player.sleepnight();
			}
			else {
				player.sleepnight2();
				
			}
			Time = DTime(1, -Time.gettime()+ nt * 6 + 6) + Time;
			break;
		case 2:
			Time = DTime(0, 1) + Time;
			player.rest();
			break;
		case 3:
			
			int more;
			more = 5;
			if (player.getorbs() > 100 && player.getmaster() == 3) more++;
			switch (menu(new string[6]{ 
				"��֮����",
				"�������",
				"Ů��֮Ȫ",
				"��֮Ů��", 
				more == 5 ? "�˳�" : "�����׷�!!!!!!", "�˳�" }, more, "ѡ��������Ŀ", 0))
			{
			case 0:
				system("cls");
				if (player.getmaster() == 3) {
					cout << "���Ѿ�����˽�֮������.... ȥ��ս����������..";
					getchar();
				}
				sl = jzsl();
				sl.Set(player.getmaster());
				switch (menu(new string[3]{ "��", "�鿴��֮����˵��", "��" }, 3, "��֮����.. �ⲻ����.. ɥ���.. �Ƿ����?", 0))
				{
				case 0:
					if (!menu(new string[2]{ "��", "��" }, 2, dirc(dirc("��ս��֮������������", sl.getene()), dirc(dirc("�㾫��, �Լ�", sl.gethp()), "������, ȷ�Ͻ⿪����?")), 0)) {
						int flag1 = player.work(sl.getene());
						if (!player.hurt(sl.gethp())) {
							cout << "game over...\n";
							getchar();
							EXIT();
						}
						
						if (flag1) {
							if (player.getmaster() == 2) {
								mstswd.dec();
							}
							Time = Time + DTime(0, 10 * player.getmaster());

							player.jzslpj();
						}
					}
					break;
				case 1:
					sl.showdetail();
					break;
				default:
					break;
				}
				break;
			case 1: 
				system("cls"); 
				if (player.getorbs() == 120) {
					cout << "���Ѿ�������е�����������.... ȥ��ս��֮������..";
					getchar();
				}
				switch (menu(new string[3]{"��", "�鿴����˵��", "��"}, 3, dirc(dirc("Ѱ������������", 1 + player.getorbs() / 7), "�㾫��, ȷ��̽������?"), 0))
				{
				case 0:
					sm = smsl();
					player.work(1 + player.getorbs() / 15);
					if (!menu(new string[2]{ "��", "��" }, 2, dirc(dirc("�⿪����������", sm.getene()), dirc(dirc("�㾫��, �Լ�", sm.gethp()), "������, ȷ�Ͻ⿪����?")), 0)) {
						int flag1 = player.work(sm.getene());
						if (!player.hurt(sm.gethp())) {
							cout << "game over...\n";
							getchar();
							EXIT();
						}
						if (flag1) {
							player.pjsm();
							Time = Time + DTime(0, 5);
						}
					}
					break;
				case 1:
					sm.showdetail();
					break;
				default:
					break;
				}
				
				break;
			case 2: 

				if (!menu(new string[2]{"��", "��"}, 2, "���������ͨ��2������ͨ��֤, ���һ�����������..", 0))
				{
					if (!player.isenouf()) {
						system("cls");
						cout << "����... ����... ����ͬ��... ������...";
						getchar();
						break;
					}
					int flag = 1;
					int index = 0;
					while (flag) {
						switch (index = menu(new string[3]{ "�һ�����", "�һ�����", "���һ���" }, 3, "��ѡ��", index))
						{
						case 0:
							duringtime(1);

							player.evo(0);
							break;
						case 1:
							duringtime(1);
							player.evo(1);
							break;
						default:
							flag = 0;
							break;
						}
						system("cls");
					}
				}
				break;
			case 3: 
				if (!menu(new string[2]{ "��", "��" }, 2, "���������ͨ��20¬��, ��ʵ�־���, �������ת��..", 0))
				{
					if (!player.isenouf()) {
						system("cls");
						cout << "����... ����... ����ͬ��... ���ɽ���...";
						getchar();
						break;
					}
					int flag = 1;
					int index = 0;
					while (flag) {
						switch (index = menu(new string[3]{ "�����һ�����", "�����һ�����", "���һ���" }, 3, "��ѡ��", index))
						{
						case 0:
							duringtime(1);
							player.change(0);
							break;
						case 1:
							duringtime(1);
							player.change(1);
							break;

						default:
							flag = 0;
							break;
						}
						system("cls");
					}
				}
				break;
			case 4:

				system("cls");
				if (more == 5) {
					break;
				}
				if (!menu(new string[2]{ "��", "��" }, 2, "�������㹻������ʱ.. ������ս.. ʧ�ܽ��޷�����...", 0)) {
					system("cls");
					Sleep(5);
					if (player.pay(3000) && player.work(35) && player.hurt(35)) {
						cout << "\n\n\n\n\n\n\n\n\n";
						cout << "                             ����: " << 35 << endl;
						cout << "                             ����: " << 35 << endl;
						Sleep(5000);
						for (int i = 0; i < 13; ++i) {

							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n";
							cout << "                             ����: " << 35 - i << endl;
							cout << "                             ����: " << 35 - i << endl;
							Sleep(500);

						}
						Sleep(2000);
						for (int i = 13; i < 35; ++i) {
							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n";
							cout << "                             ����: " << 35 - i << endl;
							cout << "                             ����: " << 35 - i << endl;
							Sleep(100);
						}
						Sleep(4000);
						system("cls");
						cout << "\n\n\n\n\n";
						printline(new string[9]{ "�ɷ�!", "...", "�ֻ�����!", "!!", "!!" ,"������!!", "..", "����ΰ���Ӣ��!!", "�׷�!"}, 9);
						Sleep(5000);
						system("cls");
						Theend();

					}
					else {
						cout << "\n\n\n\n\n";

						printline(new string[5]{ "�ɷ�!", "...", "����!!!!", "...", "..." }, 5);
					}

				}
			default:
				break;
			}
			break;
		case 4:
			system("cls");
			if (Time.gettime() > 18) {
				cout << "�Ѿ�������, ��������������";
				getchar();
			}
			if (Time.gettime() < 7) {
				cout << "���ڻ�̫����, ����������������";
				getchar();
			}
			else {
				switch (menu(new string[6]{"ϴ��(5Сʱ 5���� 20¬��)", "����(10Сʱ 10���� 50¬��)",
				"�տ���ƥ(10Сʱ 20���� 100¬��)", "ָ·(20Сʱ 5���� 50¬��)", "׿������(3Сʱ 30���� 200¬��)"
				, "��������"}, 6, "��ѡ����", 0))
				{
				case 0:
					if (player.work(5)) {
						Time = Time + DTime(0, 5);
						duringtime(5);
						player.addruby(20);
					}
					break;
				case 1:
					if (player.work(10)) {
						Time = Time + DTime(0, 10);
						duringtime(10);

						player.addruby(50);
					}
					break;
				case 2:
					if (player.work(20)) {
						Time = Time + DTime(0, 10);
						duringtime(10);

						player.addruby(100);
					}
					break;

				case 3:
					if (player.work(5)) {
						Time = Time + DTime(0, 20);
						duringtime(20);

						player.addruby(50);
					}
					break;
				case 4:
					if (player.work(30)) {
						Time = Time + DTime(0, 3);
						duringtime(3);
						player.addruby(20);
					}
					break;
				default:
					
					break;
				}
			}
			break;
		case 5:
			player.Save(Time);
			break;
		case 6:
			if (!menu(new string[2]{ "��", "��" }, 2, "�˳�ǰ�Ƿ��뱣��?")) {
				player.Save(Time);
			}
			EXIT();
			break;
		default:
			break;
		}
		system("cls");
	}


}

void Theend() {
	Person Mipha("�׷�");
	Person Link("�ֿ�");
	//Mipha.tell("!");
	//Mipha.tell("��..");
	//Mipha.tell("��������..");
	//Link.tell("..");
	//Mipha.tell("�ֿ�..");
	//Link.tell("�Ҿ���ȫ��..");
	//Link.tell("����, �ܾȻ�..��");
	//Link.tell("..");

	Link.tell("�׷�!");
	Mipha.tell("?");
	Link.tell("���ڿ�������!");
	Mipha.tell("?");
	Link.tell("����, ����������, ���������ǵĹ������̫���˸ж���");
	Link.tell("���ý����ҵ�Ļ���, ��Ҫ�Լ�ħ��һ�¾�����");
	Mipha.tell("(����)");
	Link.tell("��Ȼ���޷��ı������ľ���, ����������, �һ�������������..");
	Link.tell("������, ����ͽ���������..");
	Link.tell("���˶���, ����������, �ܹ���������ķǳ�������(����լ��Ц��)");
	Mipha.tell("����: ̫�ж���, �Ҷ���֪�����׷�Ҫ˵ɶ��, ���� �����(�ᱼ)!");
	Link.tell("��л����!");
	Link.tell("The end");
	Sleep(10000);
	EXIT();
}

void duringtime(int e) {
	
	for (int i = e; i >= 0; --i) {
		system("cls");
		cout << dirc("               ���ٶȹ�ʱ����: ", i);
		Sleep(500);
	}
}

void printline(string str[], int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < 36 - str[i].length() / 2; ++j) cout << " ";
		cout << str[i] << "\n";
		Sleep(1500);
	}
}
