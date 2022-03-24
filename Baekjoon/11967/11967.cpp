#include <queue>
#include <vector>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M;
int board[101][101];
vector<pair<int, int>> arr[101][101];

int check(int x, int y) {
	return 0;
}

int bfs() {
	queue<pair<int, int>> q;
	int ans = 1;
	board[1][1] = 3;
	q.push({1, 1});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		// cout << "\n\n";
		// cout << x << " " << y << "\n";
		// for (int i =0; i <=N; i++) {
		// 	for (int j=0; j<=N; j++) {
		// 		cout << board[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		q.pop();
		for (auto ar : arr[x][y]) {
			// cout << ar.first << " " << ar.second << "\n";
			if (board[ar.first][ar.second] == 0) {
				board[ar.first][ar.second] = 1;
				ans++;
			} else if (board[ar.first][ar.second] == 2) {
				board[ar.first][ar.second] = 3;
				q.push({ar.first, ar.second});
				ans++;
			}
		}
		if (board[x-1][y] == 1) {
			q.push({x-1, y}); board[x-1][y] = 3;
		} else if (board[x-1][y] == 0) board[x-1][y] = 2;

		if (board[x+1][y] == 1) {
			q.push({x+1, y}); board[x+1][y] = 3;
		} else if (board[x+1][y] == 0) board[x+1][y] = 2;

		if (board[x][y-1] == 1) {
			q.push({x, y-1}); board[x][y-1] = 3;
		} else if (board[x][y-1] == 0) board[x][y-1] = 2;

		if (board[x][y+1] == 1) {
			q.push({x, y+1}); board[x][y+1] = 3;
		} else if (board[x][y+1] == 0) board[x][y+1] = 2;
	}
	return ans;
}

int main() {
	fastio;
	int tmpx, tmpy, tmpx2, tmpy2;
	cin >> N >> M;
	for (int i=0; i < M; i++) {
		cin >> tmpx >> tmpy >> tmpx2 >> tmpy2;
		arr[tmpx][tmpy].push_back({tmpx2, tmpy2});
	}
	cout << bfs() << endl;
	return 0;
}
