#include<stdio.h>
#include<easyx.h>
#include<iostream>
#include<cstring>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<queue>
#include<vector>
#include"showbfs.h"
#include"showdfs.h"
#include"showqueue.h"
#include"showstack.h"
using namespace std;

class Draw {
public:
	int x, y;
	int number;
	Draw(int x, int y, int number) {
		this->x = x;
		this->y = y;
		this->number = number;
	}
	virtual void draw(COLORREF color) {}
};

class Circle : public Draw {
public:
	int radius;

	Circle(int x, int y, int radius, int number) : Draw(x, y, number) {
		this->x = x;
		this->y = y;
		this->radius = radius;
	}

	void draw(COLORREF color) {
		setfillcolor(color);
		fillcircle(this->x, this->y, this->radius);
	}
};

class Rect : public Draw {
public:
	int width, height;

	Rect(int x, int y, int width, int height, int number) : Draw(x, y, number) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	void draw(COLORREF color) {
		setfillcolor(color);
		fillrectangle(x, y, x + width, y + height);
	}
};

vector<Draw*> vec;

void drawFrame() {
	cleardevice();
	for (int i = 0; i < vec.size(); i++) {
		vec[i]->draw(RED);
	}
	Sleep(20);
}

void mySwap(int i, int j) {
	int raw_x1 = vec[i]->x;
	int raw_x2 = vec[j]->x;

	int fh = (raw_x2 - raw_x1) > 0 ? 1 : -1;

	while (vec[i]->x != raw_x2) {
		vec[i]->x += fh;
		vec[j]->x -= fh;
		drawFrame();
	}
}
void zqyOut();
void wOut();
void qqOut();
void ssOut();
void EoveOut();
bool loveOut();
bool shendu();
bool guangdu();
bool addOut();
bool changeOut();
bool delOut();

bool monthOut();
bool addIn();
bool changeIn();
bool delIn();
bool showIn() { return true; };

bool showRest();
bool cleanOut() { return true; };
bool cleanIn() { return true; };
bool showOut();

bool drawMenu() {
	MOUSEMSG m;
	//菜单
	initgraph(800, 600);//初始化绘图窗口默认640×480，函数里如果加SHWOCONSOLE同时显示控制台窗口
	setbkcolor(YELLOW);//设置当前绘图背景色，我设置的是黄色
	cleardevice();//刷新一次 略等于那个system(cls)差不多但是俩者还有不同的区别
	setfillcolor(LIGHTBLUE);//设置当前填充颜色；
	fillrectangle(300, 10, 500, 30);//函数就是用于画有边框的填充矩形函数里有4个参数，分别是矩形左部x坐标上部y坐标，矩形右部x坐标下部y坐标
	fillrectangle(300, 50, 500, 70);
	fillrectangle(300, 90, 500, 110);
	fillrectangle(300, 130, 500, 150);

	fillrectangle(300, 200, 500, 220);
	fillrectangle(300, 240, 500, 260);
	fillrectangle(300, 280, 500, 300);
	fillrectangle(300, 320, 500, 340);

	fillrectangle(300, 390, 500, 410);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);

	settextstyle(15, 0, "宋体");//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景

	outtextxy(370, 15, "排序");
	outtextxy(370, 55, "栈");
	outtextxy(370, 95, "队列");
	outtextxy(370, 135, "搜索");


	outtextxy(370, 205, "图");
	outtextxy(370, 245, "树");
	outtextxy(370, 280, "暴力枚举");
	outtextxy(370, 320, "迭代加深");

	outtextxy(370, 395, "高精度计算");
	outtextxy(370, 433, "并查集");
	outtextxy(370, 472, "贪心与动态规划");

	settextcolor(BLACK);
	settextstyle(45, 0, "楷体");
	outtextxy(120, 530, "数据结构与算法的可视化");

	while (1) {
		//

		//
		m = GetMouseMsg();//用于获取鼠标信息的函数
		if (m.x >= 300 && m.x <= 500 && m.y >= 10 && m.y <= 30) {
			setlinecolor(RED);//这个函数用于设置当前画线颜色
			rectangle(295, 5, 505, 35);//这个函数用于画空心矩形
			//这个就是鼠标左键按下消息  如果点击了排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (addOut()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 50 && m.y <= 70) {
			setlinecolor(RED);
			rectangle(295, 45, 505, 75);
			//如果点击了栈
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (delOut()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 90 && m.y <= 110) {
			setlinecolor(RED);
			rectangle(295, 85, 505, 115);
			//如果点击了队列
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (showOut()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 130 && m.y <= 150) {
			setlinecolor(RED);
			rectangle(295, 125, 505, 155);
			//如果点击了搜索
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (changeOut()) break;
				}
				return false;
			}
		}
		//
		else if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 220) {//
			setlinecolor(RED);
			rectangle(295, 195, 505, 225);
			//如果点击了图
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (addIn()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 240 && m.y <= 260) {//
			setlinecolor(RED);
			rectangle(295, 235, 505, 265);
			//如果点击了树
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (delIn()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 280 && m.y <= 300) {
			setlinecolor(RED);
			rectangle(295, 275, 505, 305);
			//如果点击了暴力枚举
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (showIn())break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 320 && m.y <= 340) {
			setlinecolor(RED);
			rectangle(295, 315, 505, 345);
			//如果点击了迭代加深
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (changeIn()) break;
				}
				return false;
			}

		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 390 && m.y <= 410) {
			setlinecolor(RED);
			rectangle(295, 385, 505, 415);
			//如果点击了高精度计算
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (showRest()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了并查集
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (cleanOut()) break;
				}
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击贪心与动态规划
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (cleanOut()) break;
				}
				return false;
			}
		}


		else {
			setlinecolor(WHITE);
			rectangle(295, 5, 505, 35);
			rectangle(295, 45, 505, 75);
			rectangle(295, 85, 505, 115);
			rectangle(295, 125, 505, 155);

			rectangle(295, 235, 505, 265);
			rectangle(295, 275, 505, 305);
			rectangle(295, 315, 505, 345);
			rectangle(295, 195, 505, 225);

			rectangle(295, 385, 505, 415);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);
		}
	}
	closegraph();//这个函数用来关闭图形环境
}

bool addOut()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 200, 600, 220);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 320, 600, 340);
	fillrectangle(200, 380, 600, 400);
	fillrectangle(200, 440, 600, 460);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "选择排序");
	outtextxy(250, 202, "冒泡排序");
	outtextxy(250, 262, "插入排序");
	outtextxy(250, 322, "桶排序");
	outtextxy(250, 382, "快速排序");
	outtextxy(250, 442, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//检测鼠标的位置 是否满足条件
			setlinecolor(RED);//满足后 设置新的边框为红色
			rectangle(190, 135, 610, 165);//画新的边框
			//如果点击了 选择排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();//响应功能
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 200 && m.y <= 220) {
			setlinecolor(RED);
			rectangle(190, 195, 610, 225);
			//如果点击了冒泡排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				monthOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了插入排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 320 && m.y <= 340) {
			setlinecolor(RED);
			rectangle(190, 315, 610, 345);
			//点击了桶排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	memOut();
				return false;
			}
		}

		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了快速排序
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	show();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 460) {
			setlinecolor(RED);
			rectangle(190, 435, 610, 465);
			//点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		//一旦鼠标不在相应位置 将画出白色边框 覆盖之前的红色边框
		else {
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 195, 610, 225);
			rectangle(190, 255, 610, 285);
			rectangle(190, 315, 610, 345);
			rectangle(190, 375, 610, 405);
			rectangle(190, 435, 610, 465);
		}
	}
}

bool changeOut()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 380, 600, 400);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "深度优先搜索");
	outtextxy(250, 262, "广度优先搜索");
	outtextxy(250, 382, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//检测鼠标的位置 是否满足条件
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);//画新的边框
			//如果点击了 深度优先搜索
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (shendu()) break;
				}
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了广度优先搜索
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (guangdu()) break;
				}
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	show();
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 255, 610, 285);
			rectangle(190, 375, 610, 405);
		}
	}
}

bool changeIn()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 380, 600, 400);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "迭代深度优先搜索");
	outtextxy(250, 262, "迭代广度优先搜索");
	outtextxy(250, 382, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//检测鼠标的位置 是否满足条件
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);//画新的边框
			//如果点击了 深度优先搜索
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (shendu()) break;
				}
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了广度优先搜索
			if (m.uMsg == WM_LBUTTONDOWN) {
				while (true) {
					if (guangdu()) break;
				}
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	show();
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 255, 610, 285);
			rectangle(190, 375, 610, 405);
		}
	}
}

bool showRest()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 200, 600, 220);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 320, 600, 340);
	fillrectangle(200, 380, 600, 400);
	fillrectangle(200, 440, 600, 460);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "高精度加法");
	outtextxy(250, 202, "高精度减法");
	outtextxy(250, 262, "高精度乘法");
	outtextxy(250, 322, "高精度除法");
	outtextxy(250, 382, "高精度快速慕");
	outtextxy(250, 442, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//如果点击了高精度加法
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();//响应功能
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 200 && m.y <= 220) {
			setlinecolor(RED);
			rectangle(190, 195, 610, 225);
			//如果点击了高精度减法
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	monthOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了高精度乘法
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 320 && m.y <= 340) {
			setlinecolor(RED);
			rectangle(190, 315, 610, 345);
			//点击了高精度除法
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	memOut();
				return false;
			}
		}

		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了高精度快速慕
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	show();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 460) {
			setlinecolor(RED);
			rectangle(190, 435, 610, 465);
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 195, 610, 225);
			rectangle(190, 255, 610, 285);
			rectangle(190, 315, 610, 345);
			rectangle(190, 375, 610, 405);
			rectangle(190, 435, 610, 465);
		}
	}
}

bool addIn()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 380, 600, 400);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "图的存储");
	outtextxy(250, 262, "图的遍历");
	outtextxy(250, 382, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//如果点击了 图的存储
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了图的遍历
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 255, 610, 285);
			rectangle(190, 375, 610, 405);
		}
	}
}

bool delIn()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 380, 600, 400);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "树的存储");
	outtextxy(250, 262, "树的遍历");
	outtextxy(250, 382, "返回主菜单");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//如果点击了 树的存储
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//点击了树的遍历
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//点击了返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 255, 610, 285);
			rectangle(190, 375, 610, 405);
		}
	}
}


bool guangdu()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "广度优先算法的核心思想是:从初始结点开始，应用算符生");
	outtextxy(0, 40, "成第一次结点，检查目标节点是否在这些后继节点中，若没");
	outtextxy(0, 80, "有，再用产生式规则将所有的第一层的结点逐一扩展得到");
	outtextxy(0, 120, "第二层结点……如此依次扩展下去，直到发现目标结点为止");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_bfs bfs;
				bfs.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}

bool shendu()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "深度优先搜索的核心思想:为了求得问题的解，先选择某一");
	outtextxy(0, 40, "种可能的情况向前探索，在探索过程中一旦发现原来的选择");
	outtextxy(0, 80, "是错误的，就退回一步重新选择，继续向前探索，如此反复");
	outtextxy(0, 120, "进行，直至得到解或证明无解");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_dfs dfs;
				dfs.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}

bool monthOut()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "冒泡排序的基本思想就是:每次比较俩个相邻的元素，如果");
	outtextxy(0, 40, "它们的顺序错误就把它们交换过来");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				loveOut();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}
bool loveOut()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "请把下面4个数进行升序排列");
	settextcolor(WHITE);
	outtextxy(45, 90, "3");
	outtextxy(195, 90, "1");
	outtextxy(345, 90, "5");
	outtextxy(495, 90, "2");
	setlinecolor(WHITE);
	setfillcolor(RED);
	circle(50, 100, 40);
	circle(200, 100, 40);
	circle(350, 100, 40);
	circle(500, 100, 40);
	floodfill(50, 100, WHITE);
	floodfill(200, 100, WHITE);
	floodfill(345, 100, WHITE);
	floodfill(495, 100, WHITE);

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				EoveOut();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}
void EoveOut()
{
	initgraph(640, 480);

	setlinecolor(WHITE);
	setfillcolor(RED);

	BeginBatchDraw();
	for (int i = 50, u = 200; i <= 200, u >= 50; i++, u--)
	{
		circle(i, 100, 40);
		circle(u, 100, 40);
		circle(350, 100, 40);
		circle(500, 100, 40);
		outtextxy(i - 10, 90, "3");
		outtextxy(u - 5, 90, "1");
		outtextxy(345, 90, "5");
		outtextxy(495, 90, "2");
		floodfill(i, 100, WHITE);
		floodfill(u, 100, WHITE);
		floodfill(345, 100, WHITE);
		floodfill(495, 100, WHITE);
		FlushBatchDraw();
		Sleep(20);
		cleardevice();

	}
	EndBatchDraw();
	qqOut();
}
void qqOut()
{
	initgraph(640, 480);

	setlinecolor(WHITE);
	setfillcolor(RED);

	BeginBatchDraw();
	for (int i = 350, u = 500; i <= 500, u >= 350; i++, u--)
	{
		circle(50, 100, 40);
		circle(200, 100, 40);
		circle(i, 100, 40);
		circle(u, 100, 40);
		outtextxy(45, 90, "1");
		outtextxy(195, 90, "3");
		outtextxy(i-10, 90, "5");
		outtextxy(u-5, 90, "2");
		floodfill(i, 100, WHITE);
		floodfill(u, 100, WHITE);
		floodfill(345, 100, WHITE);
		floodfill(495, 100, WHITE);
		FlushBatchDraw();
		Sleep(20);
		cleardevice();

	}
	EndBatchDraw();
	ssOut();
}
void ssOut()
{
	initgraph(640, 480);

	setlinecolor(WHITE);
	setfillcolor(RED);

	BeginBatchDraw();
	for (int i = 200, u = 350; i <= 350, u >= 200; i++, u--)
	{
		circle(50, 100, 40);
		circle(i, 100, 40);
		circle(u, 100, 40);
		outtextxy(45, 90, "1");
		outtextxy(i-10, 90, "3");
		outtextxy(u-5, 90, "2");
		floodfill(45, 100, WHITE);
		floodfill(i, 100, WHITE);
		floodfill(u, 100, WHITE);
		FlushBatchDraw();
		Sleep(20);
		cleardevice();

	}
	EndBatchDraw();
	wOut();
}
void wOut()
{
	MOUSEMSG m;
	initgraph(800, 600);
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "高级演示");
	outtextxy(370, 472, "返回");
	setlinecolor(WHITE);
	setfillcolor(RED);
	outtextxy(45, 90, "1");
	outtextxy(195, 90, "2");
	circle(50, 100, 40);
	circle(200, 100, 40);
	floodfill(50, 100, WHITE);
	floodfill(200, 100, WHITE);
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
		setlinecolor(RED);
		rectangle(295, 465, 505, 495);
		//如果点击了返回
		if (m.uMsg == WM_LBUTTONDOWN) {
			return ;
		}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了高级演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				zqyOut();
				return ;
			}
		}
		else
		{
		setlinecolor(WHITE);
		rectangle(295, 465, 505, 495);

		}
	}
}
void zqyOut()
{
	initgraph(800, 600);
	MOUSEMSG m;

	vec.push_back(&Circle(50, 200, 80, 3)); 
	vec.push_back(&Circle(250, 200, 40, 1)); 
	vec.push_back(&Circle(450, 200, 100, 5)); 
	vec.push_back(&Circle(650, 200, 60, 2));
	mySwap(1,0);
	mySwap(2, 3);
	mySwap(0, 3);
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 0 && m.x <= 800 && m.y >= 0 && m.y <= 600)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
				return;
		}
	}
}

bool showOut() {
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "队列是一种特殊的线性表，特殊之处在于它只允许在表的");
	outtextxy(0, 40, "前端进行删除操作，而在表的后端进行插入操作，和栈一样");
	outtextxy(0, 80, "，队列是一种操作受限制的线性表。进行插入操作的端称为");
	outtextxy(0, 120, "队尾，进行删除操作的端称为队头。");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_dl dl;
				dl.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}

bool delOut() {
	MOUSEMSG m;
	initgraph(800, 600);
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(300, 430, 500, 450);
	fillrectangle(300, 470, 500, 490);
	settextstyle(15, 0, "宋体");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "演示");
	outtextxy(370, 472, "返回");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	outtextxy(30, 0, "栈又名堆栈，它是一种运算受限的线性表。限定仅在表尾");
	outtextxy(0, 40, "进行插入和删除操作的线性表。这一端被称为栈顶，相对地");
	outtextxy(0, 80, "，把另一端称为栈底。向一个栈插入新元素又称作进栈、入");
	outtextxy(0, 120, "栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新");
	outtextxy(0, 160, "的栈顶元素；从一个栈删除元素又称作出栈或退栈，它是把");
	outtextxy(0, 200, "栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//如果点击了演示
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_zhan zhan;
				zhan.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//如果点击了返回
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(295, 425, 505, 455);
			rectangle(295, 465, 505, 495);

		}
	}
}

int main() {
	while (true) {
		if (drawMenu()) break;
	}
	return 0;
}