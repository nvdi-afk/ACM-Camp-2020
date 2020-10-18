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
	//length：小格边长 sleep_time：停顿时间 lx，ly：地图对应的左上角坐标，downx，downy：地图对应得下和右得坐标 n，m：行和列
	int stx = -1, sty = -1, edx = -1, edy = -1;//开始结束的行和列
	int Next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	bool flag[100][100];//存地图走没走过
	struct node {//bfs用的结构体
		int x, y, num;
	}now, add;
	struct butt {//按钮结构体
		int l, t, r, d;
	}add_but;
	vector<butt>select_button;//存按钮的

public:

	void paint_square_loc(int x, int y) {//根据地图每个小个子左上角的坐标x，y来画出每一个小格子
		fillrectangle(x, y, x + length, y + length);
		return;
	}

	pair<int, int> get_loc(int x, int y) { //这个是根据坐标x，y算出x，y对应的是第i行第j列的格子，并把i，j作为pair返回
		return make_pair((y - ly) / length, (x - lx) / length);
	}

	void cls_box() {//这个是给地图区域清空，就是画一个大黑方框
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(100, 100, 400, 400);
		return;
	}

	void set_button() {//设置按钮信息，坐标
		string write;
		add_but.l = 600; add_but.t = 80;  add_but.r = 730; add_but.d = 130; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 180; add_but.r = 730; add_but.d = 230; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 280; add_but.r = 730; add_but.d = 330; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 380; add_but.r = 730; add_but.d = 430; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 480; add_but.r = 730; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 300; add_but.t = 480; add_but.r = 430; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 100; add_but.t = 480; add_but.r = 230; add_but.d = 530; select_button.push_back(add_but);
	}

	void draw_button(int x) {//画出第x个按钮
		setlinecolor(0xD2691E); setfillcolor(0xDBDBDB);
		fillrectangle(select_button[x].l, select_button[x].t, select_button[x].r, select_button[x].d);
	}

	void init() {//绘制地图
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

	int get_from_box(const char GG[]) {//从对话框读入用户输入信息

		char s[10];
		InputBox(s, 10, GG);//用于以对话框的形式获取用户输入
		int r;
		sscanf_s(s, "%d", &r);
		return r;
	}

	void run_bfs() {//运行bfs
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

	bool run_button(int x) {//运行第x个按钮
		MOUSEMSG mouse;
		switch (x) {
		case 1://运行按钮
			run_bfs();
			break;
		case 2://设置起点按钮
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
		case 3://设置终点按钮
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
		case 4://设置障碍按钮
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
		case 5://调节大小按钮
			while (n = get_from_box("请输入竖直范围(1≤n≤10)："), n < 1 || n>10);
			while (m = get_from_box("请输入水平范围(1≤m≤10)："), m < 1 || m>10);
			downx = m * length + lx;
			downy = n * length + ly;
			init();
			break;
		case 6://清除按钮
			memset(flag, false, sizeof(flag));//清除走过的痕迹
			init();//重新画地图
			break;
		case 7://退出按钮
			return true;//退出
		}
		return false;
	}

	bool run() {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 800, 800);//初始化界面，画个大黑方块
		set_button();//设置按钮信息
		lx = 100; ly = 100;

		setfillcolor(0xAAAA00);
		fillrectangle(520, 0, 800, 800);//画出右面的那个蓝色背景方块

		for (int i = 0; i < select_button.size(); i++) {
			draw_button(i);//画出所有的按钮
		}
		//画出所有的字
		settextcolor(GREEN); settextstyle(20, 0, _T("宋体")); setbkmode(TRANSPARENT);
		outtextxy(625, 95, _T("开    始"));
		outtextxy(625, 195, _T("设置起点"));
		outtextxy(625, 295, _T("设置终点"));
		outtextxy(625, 395, _T("设置障碍"));
		outtextxy(625, 495, _T("调节大小"));
		outtextxy(325, 495, _T("清    除"));
		outtextxy(125, 495, _T("返    回"));

		run_button(5);//运行按钮5，就是让用户输入m和n

		MOUSEMSG mouse;
		while (true) {
			mouse = GetMouseMsg();
			for (int i = 0; i < select_button.size(); i++) {//循环每一个按钮
				if (mouse.x >= select_button[i].l && mouse.x <= select_button[i].r && mouse.y >= select_button[i].t && mouse.y <= select_button[i].d) {
					setlinecolor(RED);//↑如果鼠标在第i个按钮上
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);//画出选择框
					if (mouse.uMsg == WM_LBUTTONDOWN) {//如果点击则运行按钮i+1，因为i是从0开始的所以+1
						if (run_button(i + 1)) return true;//运行第i+1个按钮
					}
				}
				else {
					setlinecolor(0xAAAA00);//变成浅灰色
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);//消除选择框
				}
			}
		}
	}

};

#endif