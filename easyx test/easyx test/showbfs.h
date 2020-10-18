#ifndef _SHOWBFS_H_
#define _SHOWFBS_H_

#include<iostream>
#include<queue>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>

using namespace std;

class maze_bfs 
{

private:

	int length = 30, sleep_time = 200, lx, ly, downx = 0, downy = 0, n = 0, m = 0;
	//length��С��߳� sleep_time��ͣ��ʱ�� lx��ly����ͼ��Ӧ�����Ͻ����꣬downx��downy����ͼ��Ӧ���º��ҵ����� n��m���к���
	int stx = -1, sty = -1, edx = -1, edy = -1;//��ʼ�������к���
	int Next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	bool flag[100][100];//���ͼ��û�߹�
	struct node {//bfs�õĽṹ��
		int x, y, num;
	}now, add;
	struct butt {//��ť�ṹ��
		int l, t, r, d;
	}add_but;
	vector<butt>select_button;//�水ť��

public:

	void paint_square_loc(int x, int y) {//���ݵ�ͼÿ��С�������Ͻǵ�����x��y������ÿһ��С����
		fillrectangle(x, y, x + length, y + length);
		return;
	}

	pair<int, int> get_loc(int x, int y) { //����Ǹ�������x��y���x��y��Ӧ���ǵ�i�е�j�еĸ��ӣ�����i��j��Ϊpair����
		return make_pair((y - ly) / length, (x - lx) / length);
	}

	void cls_box() {//����Ǹ���ͼ������գ����ǻ�һ����ڷ���
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(100, 100, 400, 400);
		return;
	}

	void set_button() {//���ð�ť��Ϣ������
		string write;
		add_but.l = 600; add_but.t = 80;  add_but.r = 730; add_but.d = 130; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 180; add_but.r = 730; add_but.d = 230; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 280; add_but.r = 730; add_but.d = 330; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 380; add_but.r = 730; add_but.d = 430; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 480; add_but.r = 730; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 300; add_but.t = 480; add_but.r = 430; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 100; add_but.t = 480; add_but.r = 230; add_but.d = 530; select_button.push_back(add_but);
	}

	void draw_button(int x) {//������x����ť
		setlinecolor(0xD2691E); setfillcolor(0xDBDBDB);
		fillrectangle(select_button[x].l, select_button[x].t, select_button[x].r, select_button[x].d);
	}

	void init() {//���Ƶ�ͼ
		cls_box();
		stx = -1; sty = -1; edx = -1; edy = -1;
		memset(flag, false, sizeof(flag));
		setlinecolor(0xD2691E);
		BeginBatchDraw();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!flag[i][j]) {
					setfillcolor(0xDBDBDB);
				}
				else {
					setfillcolor(BLACK);
				}
				paint_square_loc(lx + j * length, ly + i * length);
			}
		}
		EndBatchDraw();
	}

	int get_from_box(const char GG[]) {//�ӶԻ�������û�������Ϣ

		char s[10];
		InputBox(s, 10, GG);//�����ԶԻ������ʽ��ȡ�û�����
		int r;
		sscanf_s(s, "%d", &r);
		return r;
	}

	void run_bfs() {//����bfs
		setlinecolor(0xD2691E);
		setfillcolor(BLUE);
		bool book = false;
		queue<node>que;
		now.x = sty; now.y = stx; now.num = 0; flag[now.x][now.y] = true;
		que.push(now);
		while (!que.empty()) {
			now = que.front();
			for (int i = 0; i < 4; i++) {
				int xx = now.x + Next[i][0];
				int yy = now.y + Next[i][1];


				if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
				if (flag[xx][yy]) continue;
				if (xx == edy && yy == edx) {
					book = true;
					break;
				}
				add.x = xx; add.y = yy; add.num = now.num + 1;
				flag[xx][yy] = true;
				que.push(add);
				paint_square_loc(ly + yy * length, lx + xx * length);
				Sleep(sleep_time);
			}
			que.pop();
			if (book) break;
		}
	}

	bool run_button(int x) {//���е�x����ť
		MOUSEMSG mouse;
		switch (x) {
		case 1://���а�ť
			run_bfs();
			break;
		case 2://������㰴ť
			setlinecolor(0xD2691E);
			while (true) {
				mouse = GetMouseMsg();
				if (mouse.x >= lx && mouse.x <= downx && mouse.y >= ly && mouse.y <= downy) {
					if (mouse.uMsg == WM_LBUTTONDOWN) {
						pair<int, int>setnew = get_loc(mouse.x, mouse.y);
						if (stx != -1 || sty != -1) {
							setfillcolor(0xDBDBDB);
							int locx = ly + stx * length;
							int locy = lx + sty * length;
							paint_square_loc(locx, locy);
						}
						sty = setnew.first;
						stx = setnew.second;
						int locx = ly + stx * length;
						int locy = lx + sty * length;
						setfillcolor(RED);
						paint_square_loc(locx, locy);
						break;
					}
				}
			}
			break;
		case 3://�����յ㰴ť
			setlinecolor(0xD2691E);
			while (true) {
				mouse = GetMouseMsg();
				if (mouse.x >= lx && mouse.x <= downx && mouse.y >= ly && mouse.y <= downy) {
					if (mouse.uMsg == WM_LBUTTONDOWN) {
						pair<int, int>setnew = get_loc(mouse.x, mouse.y);
						if (edx != -1 || edy != -1) {
							setfillcolor(0xDBDBDB);
							int locx = ly + edx * length;
							int locy = lx + edy * length;
							paint_square_loc(locx, locy);
						}
						edy = setnew.first;
						edx = setnew.second;
						int locx = ly + edx * length;
						int locy = lx + edy * length;
						setfillcolor(RED);
						paint_square_loc(locx, locy);
						break;
					}
				}
			}
			break;
		case 4://�����ϰ���ť
			setlinecolor(0xD2691E);
			while (true) {
				mouse = GetMouseMsg();
				if (mouse.x >= lx && mouse.x <= downx && mouse.y >= ly && mouse.y <= downy) {
					while (true) {
						mouse = GetMouseMsg();
						if (mouse.uMsg == WM_LBUTTONDOWN) {
							pair<int, int>setnew = get_loc(mouse.x, mouse.y);
							int locx = ly + setnew.second * length;
							int locy = lx + setnew.first * length;
							flag[setnew.first][setnew.second] = true;
							setfillcolor(BLACK);
							paint_square_loc(locx, locy);
							break;
						}
						if (mouse.x < lx || mouse.x > downx || mouse.y < ly || mouse.y > downy) return false;
					}
				}
			}
			break;
		case 5://���ڴ�С��ť
			while (n = get_from_box("��������ֱ��Χ(1��n��10)��"), n < 1 || n>10);
			while (m = get_from_box("������ˮƽ��Χ(1��m��10)��"), m < 1 || m>10);
			downx = m * length + lx;
			downy = n * length + ly;
			init();
			break;
		case 6://�����ť
			memset(flag, false, sizeof(flag));//����߹��ĺۼ�
			init();//���»���ͼ
			break;
		case 7://�˳���ť
			return true;//�˳�
		}
		return false;
	}

	bool run() {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 800, 800);//��ʼ�����棬������ڷ���
		set_button();//���ð�ť��Ϣ
		lx = 100; ly = 100;

		setfillcolor(0xAAAA00);
		fillrectangle(520, 0, 800, 800);//����������Ǹ���ɫ��������

		for (int i = 0; i < select_button.size(); i++) {
			draw_button(i);//�������еİ�ť
		}
		//�������е���
		settextcolor(GREEN); settextstyle(20, 0, _T("����")); setbkmode(TRANSPARENT);
		outtextxy(625, 95, _T("��    ʼ"));
		outtextxy(625, 195, _T("�������"));
		outtextxy(625, 295, _T("�����յ�"));
		outtextxy(625, 395, _T("�����ϰ�"));
		outtextxy(625, 495, _T("���ڴ�С"));
		outtextxy(325, 495, _T("��    ��"));
		outtextxy(125, 495, _T("��    ��"));

		run_button(5);//���а�ť5���������û�����m��n

		MOUSEMSG mouse;
		while (true) {
			mouse = GetMouseMsg();
			for (int i = 0; i < select_button.size(); i++) {//ѭ��ÿһ����ť
				if (mouse.x >= select_button[i].l && mouse.x <= select_button[i].r && mouse.y >= select_button[i].t && mouse.y <= select_button[i].d) {
					setlinecolor(RED);//���������ڵ�i����ť��
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);//����ѡ���
					if (mouse.uMsg == WM_LBUTTONDOWN) {//�����������а�ťi+1����Ϊi�Ǵ�0��ʼ������+1
						if (run_button(i + 1)) return true;//���е�i+1����ť
					}
				}
				else {
					setlinecolor(0xAAAA00);//���ǳ��ɫ
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);//����ѡ���
				}
			}
		}
	}

};

#endif