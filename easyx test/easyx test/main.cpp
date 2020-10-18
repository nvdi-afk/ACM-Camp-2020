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
	//�˵�
	initgraph(800, 600);//��ʼ����ͼ����Ĭ��640��480�������������SHWOCONSOLEͬʱ��ʾ����̨����
	setbkcolor(YELLOW);//���õ�ǰ��ͼ����ɫ�������õ��ǻ�ɫ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls)��൫�����߻��в�ͬ������
	setfillcolor(LIGHTBLUE);//���õ�ǰ�����ɫ��
	fillrectangle(300, 10, 500, 30);//�����������ڻ��б߿�������κ�������4���������ֱ��Ǿ�����x�����ϲ�y���꣬�����Ҳ�x�����²�y����
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

	settextstyle(15, 0, "����");//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���

	outtextxy(370, 15, "����");
	outtextxy(370, 55, "ջ");
	outtextxy(370, 95, "����");
	outtextxy(370, 135, "����");


	outtextxy(370, 205, "ͼ");
	outtextxy(370, 245, "��");
	outtextxy(370, 280, "����ö��");
	outtextxy(370, 320, "��������");

	outtextxy(370, 395, "�߾��ȼ���");
	outtextxy(370, 433, "���鼯");
	outtextxy(370, 472, "̰���붯̬�滮");

	settextcolor(BLACK);
	settextstyle(45, 0, "����");
	outtextxy(120, 530, "���ݽṹ���㷨�Ŀ��ӻ�");

	while (1) {
		//

		//
		m = GetMouseMsg();//���ڻ�ȡ�����Ϣ�ĺ���
		if (m.x >= 300 && m.x <= 500 && m.y >= 10 && m.y <= 30) {
			setlinecolor(RED);//��������������õ�ǰ������ɫ
			rectangle(295, 5, 505, 35);//����������ڻ����ľ���
			//�������������������Ϣ  ������������
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
			//��������ջ
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
			//�������˶���
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
			//������������
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
			//��������ͼ
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
			//����������
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
			//�������˱���ö��
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
			//�������˵�������
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
			//�������˸߾��ȼ���
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
			//�������˲��鼯
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
			//������̰���붯̬�滮
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
	closegraph();//������������ر�ͼ�λ���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "ѡ������");
	outtextxy(250, 202, "ð������");
	outtextxy(250, 262, "��������");
	outtextxy(250, 322, "Ͱ����");
	outtextxy(250, 382, "��������");
	outtextxy(250, 442, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//�������λ�� �Ƿ���������
			setlinecolor(RED);//����� �����µı߿�Ϊ��ɫ
			rectangle(190, 135, 610, 165);//���µı߿�
			//�������� ѡ������
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();//��Ӧ����
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 200 && m.y <= 220) {
			setlinecolor(RED);
			rectangle(190, 195, 610, 225);
			//��������ð������
			if (m.uMsg == WM_LBUTTONDOWN) {
				monthOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//����˲�������
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 320 && m.y <= 340) {
			setlinecolor(RED);
			rectangle(190, 315, 610, 345);
			//�����Ͱ����
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	memOut();
				return false;
			}
		}

		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//����˿�������
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	show();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 460) {
			setlinecolor(RED);
			rectangle(190, 435, 610, 465);
			//����˷���
			if (m.uMsg == WM_LBUTTONDOWN) {
				return true;
			}
		}
		//һ����겻����Ӧλ�� ��������ɫ�߿� ����֮ǰ�ĺ�ɫ�߿�
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "�����������");
	outtextxy(250, 262, "�����������");
	outtextxy(250, 382, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//�������λ�� �Ƿ���������
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);//���µı߿�
			//�������� �����������
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
			//����˹����������
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
			//����˷������˵�
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "���������������");
	outtextxy(250, 262, "���������������");
	outtextxy(250, 382, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//�������λ�� �Ƿ���������
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);//���µı߿�
			//�������� �����������
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
			//����˹����������
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
			//����˷������˵�
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "�߾��ȼӷ�");
	outtextxy(250, 202, "�߾��ȼ���");
	outtextxy(250, 262, "�߾��ȳ˷�");
	outtextxy(250, 322, "�߾��ȳ���");
	outtextxy(250, 382, "�߾��ȿ���Ľ");
	outtextxy(250, 442, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//�������˸߾��ȼӷ�
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();//��Ӧ����
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 200 && m.y <= 220) {
			setlinecolor(RED);
			rectangle(190, 195, 610, 225);
			//�������˸߾��ȼ���
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	monthOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//����˸߾��ȳ˷�
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 320 && m.y <= 340) {
			setlinecolor(RED);
			rectangle(190, 315, 610, 345);
			//����˸߾��ȳ���
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	memOut();
				return false;
			}
		}

		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//����˸߾��ȿ���Ľ
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "ͼ�Ĵ洢");
	outtextxy(250, 262, "ͼ�ı���");
	outtextxy(250, 382, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//�������� ͼ�Ĵ洢
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//�����ͼ�ı���
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//����˷������˵�
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 142, "���Ĵ洢");
	outtextxy(250, 262, "���ı���");
	outtextxy(250, 382, "�������˵�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {
			setlinecolor(RED);
			rectangle(190, 135, 610, 165);
			//�������� ���Ĵ洢
			if (m.uMsg == WM_LBUTTONDOWN) {
				//yearOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(RED);
			rectangle(190, 255, 610, 285);
			//��������ı���
			if (m.uMsg == WM_LBUTTONDOWN) {
				//	dayOut();
				return false;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(190, 375, 610, 405);
			//����˷������˵�
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "��������㷨�ĺ���˼����:�ӳ�ʼ��㿪ʼ��Ӧ�������");
	outtextxy(0, 40, "�ɵ�һ�ν�㣬���Ŀ��ڵ��Ƿ�����Щ��̽ڵ��У���û");
	outtextxy(0, 80, "�У����ò���ʽ�������еĵ�һ��Ľ����һ��չ�õ�");
	outtextxy(0, 120, "�ڶ����㡭�����������չ��ȥ��ֱ������Ŀ����Ϊֹ");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_bfs bfs;
				bfs.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "������������ĺ���˼��:Ϊ���������Ľ⣬��ѡ��ĳһ");
	outtextxy(0, 40, "�ֿ��ܵ������ǰ̽������̽��������һ������ԭ����ѡ��");
	outtextxy(0, 80, "�Ǵ���ģ����˻�һ������ѡ�񣬼�����ǰ̽������˷���");
	outtextxy(0, 120, "���У�ֱ���õ����֤���޽�");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_dfs dfs;
				dfs.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "ð������Ļ���˼�����:ÿ�αȽ��������ڵ�Ԫ�أ����");
	outtextxy(0, 40, "���ǵ�˳�����Ͱ����ǽ�������");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				loveOut();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "�������4����������������");
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
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				EoveOut();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "�߼���ʾ");
	outtextxy(370, 472, "����");
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
		//�������˷���
		if (m.uMsg == WM_LBUTTONDOWN) {
			return ;
		}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//�������˸߼���ʾ
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "������һ����������Ա�����֮��������ֻ�����ڱ��");
	outtextxy(0, 40, "ǰ�˽���ɾ�����������ڱ�ĺ�˽��в����������ջһ��");
	outtextxy(0, 80, "��������һ�ֲ��������Ƶ����Ա����в�������Ķ˳�Ϊ");
	outtextxy(0, 120, "��β������ɾ�������Ķ˳�Ϊ��ͷ��");

	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_dl dl;
				dl.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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
	settextstyle(15, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(370, 433, "��ʾ");
	outtextxy(370, 472, "����");
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	outtextxy(30, 0, "ջ������ջ������һ���������޵����Ա��޶����ڱ�β");
	outtextxy(0, 40, "���в����ɾ�����������Ա���һ�˱���Ϊջ������Ե�");
	outtextxy(0, 80, "������һ�˳�Ϊջ�ס���һ��ջ������Ԫ���ֳ�����ջ����");
	outtextxy(0, 120, "ջ��ѹջ�����ǰ���Ԫ�طŵ�ջ��Ԫ�ص����棬ʹ֮��Ϊ��");
	outtextxy(0, 160, "��ջ��Ԫ�أ���һ��ջɾ��Ԫ���ֳ�����ջ����ջ�����ǰ�");
	outtextxy(0, 200, "ջ��Ԫ��ɾ������ʹ�����ڵ�Ԫ�س�Ϊ�µ�ջ��Ԫ�ء�");
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 430 && m.y <= 450) {
			setlinecolor(RED);
			rectangle(295, 425, 505, 455);
			//����������ʾ
			if (m.uMsg == WM_LBUTTONDOWN) {
				maze_zhan zhan;
				zhan.run();
				return false;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 470 && m.y <= 490) {
			setlinecolor(RED);
			rectangle(295, 465, 505, 495);
			//�������˷���
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