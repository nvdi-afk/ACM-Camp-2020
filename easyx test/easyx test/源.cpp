#include<iostream>
#include<cstring>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>
#include<queue>
using namespace std;
const int length = 30;
const int sleep_time = 200;
int Next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool flag[10][10];
struct node {
	int x, y, num;
}now, add;

void paint_square(int x, int y) {
	fillrectangle(x, y, x + length, y + length);
	return;
}

void set_rock() {
	flag[0][2] = true; flag[2][2] = true; flag[3][2] = true;
	flag[3][0] = true; flag[3][1] = true; flag[3][2] = true; flag[3][3] = true; flag[3][4] = true; flag[3][7] = true; flag[3][8] = true; flag[3][9] = true;
	flag[6][4] = true; flag[6][5] = true; flag[6][6] = true; flag[6][7] = true;
	flag[1][4] = true; flag[1][5] = true; flag[1][6] = true; flag[1][7] = true; flag[1][8] = true; flag[1][9] = true;
	flag[5][3] = true; flag[6][3] = true; flag[7][3] = true; flag[8][3] = true; flag[9][3] = true;
	flag[5][2] = true; flag[5][1] = true;
	flag[7][0] = true; flag[7][1] = true;
	flag[8][5] = true; flag[8][6] = true; flag[8][7] = true; flag[8][8] = true; flag[8][9] = true;
}

void init(int n, int m, int lx, int ly) {
	set_rock();
	setlinecolor(0xD2691E);
	BeginBatchDraw();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (flag[i][j]) {
				setfillcolor(0xDBDBDB);
			}
			else {
				setfillcolor(BLACK);
			}
			paint_square(lx + j * length, ly + i * length);
		}
	}
	setfillcolor(RED);
	paint_square(lx + 0, ly + 0);
	paint_square(lx + 9 * length, ly + 9 * length);
	EndBatchDraw();
	setfillcolor(0xEEAD0E);
}
int main()
{
	int n = 10, m = 10, lx = 40, ly = 40;
	bool book = false;
	memset(flag, false, sizeof(flag));
	int stx = 0, sty = 0, edx = 9, edy = 9;
	initgraph(640, 480);
	init(n, m, lx, ly);
	queue<node>que;
	now.x = stx; now.y = sty; now.num = 0; flag[stx][sty] = true;
	que.push(now);
	while (!que.empty()) {
		now = que.front();
		for (int i = 0; i < 4; i++) {
			int xx = now.x + Next[i][0];
			int yy = now.y + Next[i][1];
			if (xx < 0 || yy < 0 || xx >= 10 || yy >= 10) continue;
			if (flag[xx][yy]) continue;
			if (xx == edx && yy == edy) {
				book = true;
				break;
			}
			add.x = xx; add.y = yy; add.num = now.num + 1;
			flag[xx][yy] = true;
			que.push(add);
			paint_square(ly + yy * length, lx + xx * length);
			Sleep(sleep_time);
		}
		que.pop();
		if (book) break;
	}
	getchar();
	return 0;
}
