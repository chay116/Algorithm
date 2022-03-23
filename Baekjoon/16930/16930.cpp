#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M, K;
int board[1001][1001];
int move_xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int init_x, init_y, end_x, end_y;
struct s_txy {
	int type;
	int x;
	int y;
	s_txy(int _t, int _x, int _y) : type(_t), x(_x), y(_y) {};
};
queue<s_txy> q;
queue<s_txy> water;
vector<string> arr(1001);

int bfs() {
	q.push({K - 1, init_x, init_y});
	q.push({K * 2 - 1, init_x, init_y});
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int type = q.front().type;
		for (int i =0; i < 4; i++) {
			int time = 0;
			if (type / K == i && type % K != K - 1) continue;
			if (type / K == ((i + 2) % 4)) continue;
			while (time < K) {
				time++;
				int nx = x + time * move_xy[i][0];
				int ny = y + time * move_xy[i][1];
				if (end_x == nx && end_y == ny) return board[x][y] + 1;
				if (!(nx >= 0 && nx < N && ny >= 0 && ny < M)) break ;
				if (arr[nx][ny] == '#') break ;
				if (board[nx][ny] == board[x][y] + 1) continue;
				else if (board[nx][ny] != 0) break;
				board[nx][ny] = board[x][y] + 1;
				q.push({i * K + time - 1, nx, ny});
			}
		}
		q.pop();
	}
	return -1;
}

int main() {
	fastio;
	string tmp;
	cin >> N >> M >> K;
	for (int j=0; j < N; j++) {
		cin >> tmp; arr[j] = tmp;
	}
	cin >> init_x >> init_y >> end_x >> end_y;
	init_x--; init_y--; end_x--; end_y--;

	cout << bfs() << endl;
}

