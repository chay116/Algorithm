#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int board[30][30];
int numbers[30][30];
int paths[30][30];
int n, m, tmp;
int answer=0;
int ending_x, ending_y;
deque<pair<int, int>> dq;
int dxys[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

int main() {
	fastio;
	cin >> n >> m;
	for (int i=0; i < n; i++)
		for (int j=0; j < m; j++) {
			cin >> tmp; board[i][j] = tmp;
			if (tmp == 3) {
				dq.push_back(make_pair(i, j)); numbers[i][j] = 1; paths[i][j] = 1;
			}
		}
	pair<int, int> current_point; int nx, ny, number, ending = 0;
	while (!dq.empty()) {
		current_point = dq.front(); dq.pop_front(); int number = numbers[current_point.first][current_point.second];
		if (ending && numbers[ending_x][ending_y] != number + 1) continue;
		for (int i=0; i < 8; i++) {
			nx = current_point.first + dxys[i][0]; ny = current_point.second + dxys[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 2)
				continue;
			if (board[nx][ny] == 0) {
				if (numbers[nx][ny] == 0) {
					numbers[nx][ny] = number + 1;
					dq.push_back(make_pair(nx, ny));
				} else if (numbers[nx][ny] != number + 1) continue;
				paths[nx][ny] += paths[current_point.first][current_point.second];
			} else if (board[nx][ny] == 1) {
				if (!(numbers[nx][ny] == number || numbers[nx][ny] == 0)) continue;
				numbers[nx][ny] = number;
				dq.push_front(make_pair(nx, ny));
				paths[nx][ny] = paths[current_point.first][current_point.second];
			} else if (board[nx][ny] == 4) {
				if (!(numbers[nx][ny] == number + 1 || numbers[nx][ny] == 0)) continue;
				if (!ending) {
					numbers[nx][ny] = number + 1; ending = 1; ending_x = nx; ending_y = ny;
				}
				paths[nx][ny] += paths[current_point.first][current_point.second];
			}
		}

		cout << "\nnumbers" << endl;
		for (int i =0; i < n; i++) {
			for (int j =0; j < m; j++) 	cout << numbers[i][j] << " ";
			cout << endl;
		}
		cout << "\npaths" << endl;
		for (int i =0; i < n; i++) {
			for (int j =0; j < m; j++) 	cout << paths[i][j] << " ";
			cout << endl;
		}
	}
	if (ending) {
		cout << numbers[ending_x][ending_y] - 2 << endl;
		cout << paths[ending_x][ending_y] << endl;
	} else cout << "-1" << endl;
}
