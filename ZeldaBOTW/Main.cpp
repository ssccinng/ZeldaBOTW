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
	ifstream infile;   //输入流
	ofstream outfile;   //输出流
	infile.open("data", ios::in);
	if (!infile) {
		start();
		info();
		Link player = Link();
		gamestart(player, DTime(1, 8));

		//自动进入
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
			string m1[] = { "开始游戏", "游戏说明", "删除存档", "退出游戏" };
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
					if (!menu(new string[2]{ "是", "否" }, 2, "真的要删除存档吗？(无法恢复！)", 0)) {
						infile.close();
						if (remove("data") == 0)
						{
							cout << "删除成功, 按任意键退出游戏" << endl;
							system("pause");
							flag = 0;
						}
						else
						{
							cout << "删除失败！ (未知原因)" << endl;
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
	cout << "检测到您初次启动程序....\n";
	Sleep(1000);
	cout << "正在初始化中, 请稍后";
	for (int i = 0; i < 5; ++i) Sleep(1000), cout << ".";
	cout << "\n";
	Sleep(2000);
	system("cls");
	cout << "初始化完成!";
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
	string f[] = { "","","","","", "醒来吧...." ,"", "醒来吧....", "林克", "世界等待着你....", "醒来吧..", "林克","","","","","...","","","" };
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
		"100年前的海拉鲁, 遭受到了加农的致命打击...",
		"四位英杰, 全部丧生",
		"100年后的今天..",
		"林克作为唯一幸存的英杰, 在复苏神庙...",
		"受到塞尔达的召唤, 醒了过来..",
		"在不断的磨炼之后",
		"林克解放了四神兽, 打败了加农",
		"只是他100年前的战友...",
		"永远变成了灵魂...", "...", "...", "如今你继续奋斗着", "希望能继续的..", "拯救他们", "" , "" };
	printline(f, 16);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n";
	printline(new string[5]{"塞尔达传说...", "旷野之息", "试练的霸者", "" , "" }, 5);
}
void gamestart(Link player, DTime Time) {
	string m1[] = { "查看状态", "消磨时间", "休息(一小时)", "修行", "打工", "保存游戏", "退出游戏" };
	
	int flag = 1;
	int index = 0;
	while (flag) {
		ostringstream a;
		a << "第" << Time.getday() << "天" << " " << Time.gettime() << "点";
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
			bed = menu(new string[3]{ "普通床", "幸福至极的水床", "算了" }, 3, "要用什么床?");
			if (bed == 2) continue;
			int nt;
			nt = menu(new string[5]{ "早上", "中午", "傍晚", "算了" }, 5, "消磨到什么时候?");
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
				"剑之试炼",
				"神庙解密",
				"女神之泉",
				"恶之女神", 
				more == 5 ? "退出" : "拯救米法!!!!!!", "退出" }, more, "选择修行项目", 0))
			{
			case 0:
				system("cls");
				if (player.getmaster() == 3) {
					cout << "你已经完成了剑之试炼了.... 去挑战其他试炼吧..";
					getchar();
				}
				sl = jzsl();
				sl.Set(player.getmaster());
				switch (menu(new string[3]{ "是", "查看剑之试炼说明", "否" }, 3, "剑之试炼.. 意不定者.. 丧与此.. 是否继续?", 0))
				{
				case 0:
					if (!menu(new string[2]{ "是", "否" }, 2, dirc(dirc("挑战剑之试炼将会消耗", sl.getene()), dirc(dirc("点精力, 以及", sl.gethp()), "点体力, 确认解开谜题?")), 0)) {
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
					cout << "你已经完成所有的神庙试炼了.... 去挑战剑之试炼吧..";
					getchar();
				}
				switch (menu(new string[3]{"是", "查看神庙说明", "否"}, 3, dirc(dirc("寻找神庙将会消耗", 1 + player.getorbs() / 7), "点精力, 确认探索神庙?"), 0))
				{
				case 0:
					sm = smsl();
					player.work(1 + player.getorbs() / 15);
					if (!menu(new string[2]{ "是", "否" }, 2, dirc(dirc("解开神庙将会消耗", sm.getene()), dirc(dirc("点精力, 以及", sm.gethp()), "点体力, 确认解开谜题?")), 0)) {
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

				if (!menu(new string[2]{"是", "否"}, 2, "这里你可以通过2个试炼通过证, 来兑换精力或体力..", 0))
				{
					if (!player.isenouf()) {
						system("cls");
						cout << "体力... 精力... 两者同在... 方可祈祷...";
						getchar();
						break;
					}
					int flag = 1;
					int index = 0;
					while (flag) {
						switch (index = menu(new string[3]{ "兑换精力", "兑换体力", "不兑换了" }, 3, "请选择", index))
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
				if (!menu(new string[2]{ "是", "否" }, 2, "这里你可以通过20卢布, 来实现精力, 体力间的转换..", 0))
				{
					if (!player.isenouf()) {
						system("cls");
						cout << "体力... 精力... 两者同在... 方可交易...";
						getchar();
						break;
					}
					int flag = 1;
					int index = 0;
					while (flag) {
						switch (index = menu(new string[3]{ "精力兑换体力", "体力兑换精力", "不兑换了" }, 3, "请选择", index))
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
				if (!menu(new string[2]{ "是", "否" }, 2, "当你有足够的信心时.. 请来挑战.. 失败将无法反悔...", 0)) {
					system("cls");
					Sleep(5);
					if (player.pay(3000) && player.work(35) && player.hurt(35)) {
						cout << "\n\n\n\n\n\n\n\n\n";
						cout << "                             体力: " << 35 << endl;
						cout << "                             精力: " << 35 << endl;
						Sleep(5000);
						for (int i = 0; i < 13; ++i) {

							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n";
							cout << "                             体力: " << 35 - i << endl;
							cout << "                             精力: " << 35 - i << endl;
							Sleep(500);

						}
						Sleep(2000);
						for (int i = 13; i < 35; ++i) {
							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n";
							cout << "                             体力: " << 35 - i << endl;
							cout << "                             精力: " << 35 - i << endl;
							Sleep(100);
						}
						Sleep(4000);
						system("cls");
						cout << "\n\n\n\n\n";
						printline(new string[9]{ "仙法!", "...", "轮回天生!", "!!", "!!" ,"回来吧!!", "..", "我们伟大的英杰!!", "米法!"}, 9);
						Sleep(5000);
						system("cls");
						Theend();

					}
					else {
						cout << "\n\n\n\n\n";

						printline(new string[5]{ "仙法!", "...", "呃啊!!!!", "...", "..." }, 5);
					}

				}
			default:
				break;
			}
			break;
		case 4:
			system("cls");
			if (Time.gettime() > 18) {
				cout << "已经很晚了, 明天再来工作吧";
				getchar();
			}
			if (Time.gettime() < 7) {
				cout << "现在还太早了, 天亮了再来工作吧";
				getchar();
			}
			else {
				switch (menu(new string[6]{"洗碗(5小时 5精力 20卢比)", "送信(10小时 10精力 50卢比)",
				"照看马匹(10小时 20精力 100卢比)", "指路(20小时 5精力 50卢布)", "卓拉任务(3小时 30精力 200卢布)"
				, "不工作了"}, 6, "可选工作", 0))
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
			if (!menu(new string[2]{ "是", "否" }, 2, "退出前是否想保存?")) {
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
	Person Mipha("米法");
	Person Link("林克");
	//Mipha.tell("!");
	//Mipha.tell("我..");
	//Mipha.tell("回来了吗..");
	//Link.tell("..");
	//Mipha.tell("林克..");
	//Link.tell("我尽了全力..");
	//Link.tell("终于, 能救回..你");
	//Link.tell("..");

	Link.tell("米法!");
	Mipha.tell("?");
	Link.tell("终于看到你了!");
	Mipha.tell("?");
	Link.tell("哈哈, 我是作者啦, 在正作你们的故事真的太令人感动了");
	Link.tell("正好借大作业的机会, 想要自己魔改一下剧情呢");
	Mipha.tell("(凝视)");
	Link.tell("虽然我无法改变正作的剧情, 不过在这里, 我还是能做到的呢..");
	Link.tell("接下来, 这里就交给你们了..");
	Link.tell("懂了懂了, 我马上走啦, 能够见到你真的非常高兴了(死肥宅的笑声)");
	Mipha.tell("作者: 太感动了, 我都不知道让米法要说啥了, 终于 完成了(泪奔)!");
	Link.tell("感谢游玩!");
	Link.tell("The end");
	Sleep(10000);
	EXIT();
}

void duringtime(int e) {
	
	for (int i = e; i >= 0; --i) {
		system("cls");
		cout << dirc("               快速度过时间中: ", i);
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
