#include <queue>
#include <vector>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

typedef struct	txy {
	int t;
	int x;
	int y;
}				s_txy;
int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M, P;
char board[1001][1001];
vector<int> movements(10);
vector<queue<s_txy>> qs(10);
vector<int> answer(10);

void bfs() {
	int ending = 1;
	int time = 0;
	while (ending)
	{
		ending = 0;
		time++;
		for (int i=1; i <= P; i++) {
			while (!qs[i].empty() && qs[i].front().t < time * movements[i]) {
				ending = 1;
				int x = qs[i].front().x;
				int y = qs[i].front().y;
				for (int j=0; j<4; j++) {
					int nx = x + dxy[j][0];
					int ny = y + dxy[j][1];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (board[nx][ny] != '.') continue;
					answer[i]++;
					qs[i].push({qs[i].front().t + 1, nx, ny});
					board[nx][ny] = '0' + i;
				}
				qs[i].pop();
			}
		}
	}
	for (int i=1; i <= P; i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}

int main() {
	fastio;
	cin >> N >> M >> P;
	for (int i=1; i <= P; i++) {
		cin >> movements[i];
	}
	for (int i=0; i < N; i++) {
		cin >> board[i];
		for (int j=0; j < M; j++) {
			if (board[i][j] != '.' && board[i][j] != '#') {
				answer[board[i][j] - '0']++;
				qs[board[i][j] - '0'].push({0, i, j});
			}
		}
	}
	bfs();
	return 0;
}
