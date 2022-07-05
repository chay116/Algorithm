#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int main() {
	fastio;
	int board[2][25];
	for (int j = 0; j < 25; ++ j) {
		board[0][j] = INT_MAX;
		board[1][j] = INT_MAX;
	}
	board[0][0] = 0;
	int N;
	while(1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		for (int j = 0; j < 25; ++ j) {
			if (board[0][j] == INT_MAX) continue;
			int left = j % 5;
			int right = j / 5;
			int force = 0;
			if (left == 0) force = 2;
			else if (abs(left - N) == 2) force = 4;
			else if (left == N) force = 1;
			else force = 3;
			board[1][N * 5 + right] = min(board[1][N * 5 + right], board[0][j] + force);

			if (right == 0) force = 2;
			else if (abs(right - N) == 2) force = 4;
			else if (right == N) force = 1;
			else force = 3;
			board[1][left * 5 + N] = min(board[1][left * 5 + N], board[0][j] + force);
		}
		for (int j = 0; j < 25; ++ j) {
			board[0][j] = board[1][j];
			board[1][j] = INT_MAX;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < 25; ++i) {
		ans = min(ans, board[0][i]);
	}
	cout << ans << endl;
}