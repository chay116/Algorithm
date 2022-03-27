#include <queue>
#include <vector>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct s_txy {
	int t;
	int x;
	int y;
};
int N, w, h;

void solution() {
	cin >> w >> h;
	queue<s_txy> fire;
	queue<s_txy> people;
	vector<string> board(h);
	for (int i=0; i < h; i++)
		cin >> board[i];
	for (int i=0; i < h; i++) {
		for (int j=0; j < w; j++){
			if (board[i][j] == '*') fire.push({0, i, j});
			if (board[i][j] == '@') people.push({0, i, j});
		}
	}
	int time = 0;
	while (!people.empty()) {
		while (!fire.empty() && fire.front().t == time) {
			int x = fire.front().x;
			int y = fire.front().y;
			for (int i=0; i < 4; i++) {
				int nx = x + dxy[i][0];
				int ny = y + dxy[i][1];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#' || board[nx][ny] == '*') continue;
				board[nx][ny] = '*';
				fire.push({time + 1, nx, ny});
			}
			fire.pop();
		}
		while (!people.empty() && people.front().t == time) {
			int x = people.front().x;
			int y = people.front().y;
			for (int i=0; i < 4; i++) {
				int nx = x + dxy[i][0];
				int ny = y + dxy[i][1];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << time + 1 << endl;
					return ;
				}
				if (board[nx][ny] == '#' || board[nx][ny] == '*'|| board[nx][ny] == '@') continue;
				board[nx][ny] = '@';
				people.push({time + 1, nx, ny});
			}
			people.pop();
		}
		time++;
		// cout << "\n\n" << endl;
		// cout << time << endl;
		// for (int i=0; i < h; i++) {
		// 	cout << board[i] << endl;
		// }
	}
	cout << "IMPOSSIBLE" << endl;
}
int main()
{
	fastio;
	cin >> N;
	while (N--) solution();
}