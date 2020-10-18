#ifndef _SHOWDFS_H_
#define _SHOWDFS_H_

#include<iostream>
#include<queue>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>

using namespace std;

class maze_dfs {

private:

	int length = 30, sleep_time = 200, lx, ly, downx = 0, downy = 0, n = 0, m = 0;
	int stx = -1, sty = -1, edx = -1, edy = -1;
	int Next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	bool flag[100][100],book=false;
	struct node {
		int x, y, num;
	}now, add;
	struct butt {
		int l, t, r, d;
	}add_but;
	vector<butt>select_button;

public:

	void paint_square_loc(int x, int y) {
		fillrectangle(x, y, x + length, y + length);
		return;
	}

	pair<int, int> get_loc(int x, int y) {
		return make_pair((y - ly) / length, (x - lx) / length);
	}

	void cls_box() {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(100, 100, 400, 400);
		return;
	}

	void set_button() {
		string write;
		add_but.l = 600; add_but.t = 80;  add_but.r = 730; add_but.d = 130; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 180; add_but.r = 730; add_but.d = 230; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 280; add_but.r = 730; add_but.d = 330; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 380; add_but.r = 730; add_but.d = 430; select_button.push_back(add_but);
		add_but.l = 600; add_but.t = 480; add_but.r = 730; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 300; add_but.t = 480; add_but.r = 430; add_but.d = 530; select_button.push_back(add_but);
		add_but.l = 100; add_but.t = 480; add_but.r = 230; add_but.d = 530; select_button.push_back(add_but);
	}

	void draw_button(int x) {
		setlinecolor(0xD2691E); setfillcolor(0xDBDBDB);
		fillrectangle(select_button[x].l, select_button[x].t, select_button[x].r, select_button[x].d);
	}

	void init() {
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

	int get_from_box(const char GG[]) {

		char s[10];
		InputBox(s, 10, GG);
		int r;
		sscanf_s(s, "%d", &r);
		return r;
	}

	void run_dfs(int x,int y) {
		setlinecolor(0xD2691E);
		

		if (x < 0 || y < 0 || x >= n || y >= m) return;
		if (flag[x][y]) return;
		if (x == edy && y == edx) {
			book = true;
			return;
		}
		flag[x][y] = true;
		setfillcolor(BLUE);
		paint_square_loc(ly + y * length, lx + x * length);
		Sleep(sleep_time - 100);
		for (int i = 0; i < 4; i++) {
			if (book) return;
			run_dfs(x + Next[i][0], y + Next[i][1]);
		}
		if (book) return;
		flag[x][y] = false;
		setfillcolor(0xDBDBDB);
		paint_square_loc(ly + y * length, lx + x * length);
		Sleep(sleep_time - 100);

	}

	bool run_button(int x) {
		MOUSEMSG mouse;
		switch (x) {
		case 1:
			flag[sty][stx] = true;
			for (int i = 0; i < 4; i++) {
				if (book)break;
				run_dfs(sty + Next[i][0], stx + Next[i][1]);
			}
			break;
		case 2:
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
		case 3:
			setlinecolor(0xD2691E);
			while (true) 
			{
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
		case 4:
			setlinecolor(0xD2691E);
			while (true)
			{
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
		case 5:
			while (n = get_from_box("请输入竖直范围(1≤n≤10)："), n < 1 || n>10);
			while (m = get_from_box("请输入水平范围(1≤m≤10)："), m < 1 || m>10);
			downx = m * length + lx;
			downy = n * length + ly;
			init();
			break;
		case 6:
			memset(flag, false, sizeof(flag));
			book = false;
			init();
			break;
		case 7:
			return true;
		}
		return false;
	}

	bool run()
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(0, 0, 800, 800);
		set_button();
		lx = 100; ly = 100;

		setfillcolor(0xAAAA00);
		fillrectangle(520, 0, 800, 800);

		for (int i = 0; i < select_button.size(); i++) {
			draw_button(i);
		}
		settextcolor(GREEN); settextstyle(20, 0, _T("宋体")); setbkmode(TRANSPARENT);
		outtextxy(625, 95, _T("开    始"));
		outtextxy(625, 195, _T("设置起点"));
		outtextxy(625, 295, _T("设置终点"));
		outtextxy(625, 395, _T("设置障碍"));
		outtextxy(625, 495, _T("调节大小"));
		outtextxy(325, 495, _T("清    除"));
		outtextxy(125, 495, _T("返    回"));

		run_button(5);

		MOUSEMSG mouse;
		while (true) 
		{
			mouse = GetMouseMsg();
			for (int i = 0; i < select_button.size(); i++) {
				if (mouse.x >= select_button[i].l && mouse.x <= select_button[i].r && mouse.y >= select_button[i].t && mouse.y <= select_button[i].d) {
					setlinecolor(RED);
					rectangle(select_button[i].l - 3, select_button[i].t - 3, select_button[i].r + 3, select_button[i].d + 3);
					if (mouse.uMsg == WM_LBUTTONDOWN) {
						if (run_button(i + 1)) return true;
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
