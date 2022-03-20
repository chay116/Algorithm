#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int R, C;
int board[1501][1501];
int move_xy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct s_txy {
	int time;
	int x;
	int y;
	s_txy(int _t, int _x, int _y) : time(_t), x(_x), y(_y) {};
};
struct cmp {
	bool operator()(const s_txy &u, const s_txy &v) {
		return u.time > v.time;
	}
};
priority_queue<s_txy, vector<s_txy>, cmp> q;
queue<s_txy> water;
vector<string> arr(1501);

int bfs() {
	int time = 0;
	while (true) {
		while (!q.empty() && q.top().time == time) {
			int x = q.top().x;
			int y = q.top().y;
			int t = q.top().time;
			// cout << "q : " << x << " " << y << endl;
			int check = 0;
			for (int i =0; i < 4; i++) {
				int nx = x + move_xy[i][0];
				int ny = y + move_xy[i][1];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					if (board[nx][ny] == board[x][y]) continue;
					if (arr[nx][ny] == 'X') check = 1;
					if (board[nx][ny] != 0 && board[nx][ny] != board[x][y])
						return (time);
					else if (arr[nx][ny] == '.') {
						q.push({t, nx, ny});
						board[nx][ny] = board[x][y];
					}
				}
			}
			q.pop();
			if (check == 1) q.push({t + 1, x, y});
		}
		// cout << time << endl;
		// for (int l=0; l<R; l++) {
		// 	cout << arr[l] << endl;
		// }
		// for (int l=0; l<R; l++) {
		// 	for (int i=0; i<C; i++)
		// 		cout << board[l][i];
		// 	cout << endl;
		// }
		time++;
		while (!water.empty() && water.front().time == time) {
			int x = water.front().x;
			int y = water.front().y;
			int t = water.front().time;
			water.pop();
			if (arr[x][y] == '.') continue;
			arr[x][y] = '.';
			for (int i =0; i < 4; i++) {
				int nx = x + move_xy[i][0];
				int ny = y + move_xy[i][1];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] == 'X') {
					water.push({t + 1, nx, ny});
				}
			}
		}
	}
	return 0;
}

int main() {
	// fastio;
	string tmp;
	cin >> R >> C;
	for (int j=0; j < R; j++) {
		cin >> tmp; arr[j] = tmp;
	}

	int type = 1;
	for (int i=0; i < R; i++) {
		for (int j=0; j < C; j++) {
			if (arr[i][j] == '.') continue;
			int k = 0;
			if (arr[i][j] == 'L') {
				q.push({0, i, j});
				board[i][j] = type++;
			}
			else {
				for (k = 0; k < 4; k++) {
					int nx = i + move_xy[k][0];
					int ny = j + move_xy[k][1];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
						if (arr[nx][ny] != 'X') break;
					}
				}
				if (k != 4) {
					water.push({1, i, j});
					arr[i][j] = 'X';
				}
			}
		}
	}
	cout << bfs() << endl;
}
