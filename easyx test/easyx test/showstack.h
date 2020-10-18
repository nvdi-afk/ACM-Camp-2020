#ifndef _SHOWSTACK_H_
#define _SHOWSTACK_H_

#include<iostream>
#include<queue>
#include<graphics.h>
#include<cstdlib>
#include<conio.h>
#include<ctime>

using namespace std;
class maze_zhan
{
private:
	int length = 50, sleep_time = 200;
	int lx = 100, ly = 200, tail = 0;
	struct butt {
		int l, t, r, d;
	}add_but;
	struct node {//������Ԫ�صĽṹ��
		int num, loc;
	}add_node, now_node;
	vector<butt>select_button;
	vector<node>st;

public:
	void cls_box() {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 100, 519, 400);
	}

	void paint_square_loc(int x, int y) {
		fillrectangle(x, y, x + length, y + length);
		return;
	}

	void init() {
		cls_box();
		setlinecolor(0xD2691E);
		setfillcolor(BLACK);
		for (int i = 0; i < 6; i++) {//����6������
			paint_square_loc(lx + i * length, ly);
		}
		for (int i = 0; i < st.size(); i++) {//���Ѿ����ڵ�Ԫ�ػ���
			settextcolor(GREEN); settextstyle(30, 0, _T("����")); setbkmode(TRANSPARENT);
			outtextxy(lx + st[i].loc * length + 20, 210, st[i].num);
		}
	}

	void set_button() {
		string write;
		add_but.l = 600; add_but.t = 180; add_but.r = 730; add_but.d = 230; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 380; add_but.r = 730; add_but.d = 430; select_button.push_back(add_but);
		add_but.l = 300; add_but.t = 480; add_but.r = 430; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 100; add_but.t = 480; add_but.r = 230; add_but.d = 530; select_button.push_back(add_but);
	}
	void draw_button(int x) {
		setlinecolor(0xD2691E);
		setfillcolor(0xDBDBDB);
		fillrectangle(select_button[x].l, select_button[x].t, select_button[x].r, select_button[x].d);
	}
	bool run_button(int x)
	{
		MOUSEMSG mouse;
		int get_num;
		switch (x) {
		case 1://��ջ��ť

			BeginBatchDraw();
			get_num = 65 + rand() % 26;//���������ĸ
			for (int i = 480; i > lx + tail * length + 20; i--)//����ĸ���Ҳ�����
			{
				settextcolor(GREEN); settextstyle(30, 0, _T("����")); setbkmode(TRANSPARENT);
				outtextxy(i, 210, get_num);
				FlushBatchDraw();
				Sleep(5);
				init();//��������ҲҪ������ֹ���Ƴ�Ԫ���ڵ�������
			}
			add_node.num = get_num; add_node.loc = tail;
			st.push_back(add_node); tail++;//Ԫ�����룬tail+1��ջ��λ��+1��
			init();
			EndBatchDraw();

			break;
		case 2://��ջ��ť
			if (st.size() == 0) break;//���ջΪ�գ����������
			now_node = st[st.size()-1];//ѡ�����һ��λ�õ�����
			st.erase(st.end()-1);//�����һ��Ԫ������ɾ��
			tail--;//β-1��ջ��λ�ü�һ
			BeginBatchDraw();
			for (int i = now_node.loc * length + lx + 20; i <480; i++)//����ĸ���Ҳ��Ƴ�
			{
				settextcolor(GREEN); settextstyle(30, 0, _T("����")); setbkmode(TRANSPARENT);
				outtextxy(i, 210, now_node.num);
				FlushBatchDraw();
				Sleep(5);
				init();//��������ҲҪ������ֹ���Ƴ�Ԫ���ڵ�������
			}
			EndBatchDraw();
			init();
			break;
		case 3://������ť
			tail = 0;//��ͷ��β��Ϊ0
			st.clear();//��ն���
			init();//���»����
			break;
		case 4:
			return true;//�����˳�

		}
		return false;
	}
	bool run() {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 800, 800);
		set_button();
		setfillcolor(0xAAAA00);
		fillrectangle(520, 0, 800, 800);
		for (int i = 0; i < select_button.size(); i++)
		{
			draw_button(i);
		}
		settextcolor(GREEN); settextstyle(20, 0, _T("����")); setbkmode(TRANSPARENT);
		outtextxy(625, 195, _T("��    ջ"));
		outtextxy(625, 395, _T("��    ջ"));
		outtextxy(325, 495, _T("��    ��"));
		outtextxy(125, 495, _T("��    ��"));
		init();
		srand(time(NULL));
		MOUSEMSG mouse;
		while (true) {
			mouse = GetMouseMsg();
			for (int i = 0; i < select_button.size(); i++) {
				if (mouse.x >= select_button[i].l && mouse.x <= select_button[i].r && mouse.y >= select_button[i].t && mouse.y <= select_button[i].d)
				{
					setlinecolor(RED);
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);
					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						if (run_button(i + 1))return true;
					}
				}
				else {
					setlinecolor(0xAAAA00);
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);
				}
			}

		}
	}
};

#endif
