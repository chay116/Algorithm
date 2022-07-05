#include <iostream>
#include <vector>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
int board[10][10];
int xy_plus[20];
int xy_minus[20];
// int step[101];
int answer;
int now_total;
// int ending;

void dfs(int x, int y) {
	// if (ending == 1) return ;
	// if (now_total == N - 1) {
	// 	answer = N - 1;
	// 	ending = 1;
	// 	return ;
	// }
	int index = x * N + y;
	if (index >= N * N) {
		answer = max(now_total, answer);
		return ;
	}
	if (board[x][y] == 1 && xy_plus[x + y] == 0 && xy_minus[N - 1 + x - y] == 0)
	{
		xy_plus[x + y] = 1;
		xy_minus[N - 1 + x - y] = 1;
		now_total++;
		if (y == N - 1) {
			if (N % 2) dfs(x + 1 , 1);
			else dfs(x + 1 , 0);
		} else if (y == N - 2) {
			if (N % 2) dfs(x + 1 , 0);
			else dfs(x + 1 , 1);
		}
		else dfs(x, y + 2);
		now_total--;
		xy_plus[x + y] = 0;
		xy_minus[N - 1 + x - y] = 0;
	}
	if (y == N - 1) {
		if (N % 2) dfs(x + 1 , 1);
		else dfs(x + 1 , 0);
	} else if (y == N - 2) {
		if (N % 2) dfs(x + 1 , 0);
		else dfs(x + 1 , 1);
	}
	else dfs(x, y + 2);
}

int main() {
	fastio;
	cin >> N;
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0);
	// ending = 0;
	int ans = answer;
	answer = 0;
	dfs(0, 1);
	cout << ans + answer << endl;
}



// void dfs(int index) {
// 	if (ending == 1) return ;
// 	if (now_total == 2 * N - 2) {
// 		answer = 2 * N - 2;
// 		ending = 1;
// 		return ;
// 	}
// 	if (index == N * N) {
// 		answer = max(now_total, answer);
// 		return ;
// 	}
// 	int x = index / N;
// 	int y = index % N;
// 	// cout << x << " " << y << " " << step[index] << endl;
// 	if (!xy_plus[x + y] && !xy_minus[10 + x - y])
// 	{
// 		xy_plus[x + y] = 1;
// 		xy_minus[10 + x - y] = 1;
// 		now_total++;
// 		dfs(index + step[index + 1]);
// 		now_total--;
// 		xy_plus[x + y] = 0;
// 		xy_minus[10 + x - y] = 0;
// 	}
// 	dfs(index + step[index + 1]);
// }

// int main() {
// 	fastio;
// 	cin >> N;
// 	int step_count = 1;
// 	int prev_index = 0;
// 	for (int i=0; i < N; i++) {
// 		for (int j=0; j < N; j++) {
// 			cin >> board[i][j];
// 			if (board[i][j] == 1 || (i * N + j == N * N - 1)) {
// 				// cout << i << " " << j << " previous_index : " << prev_index << " step_count : " << step_count << endl;
// 				step[prev_index] = step_count;
// 				prev_index = i * N + j + 1;
// 				step_count = 0;
// 			}
// 			step_count++;
// 		}
// 	}
// 	step[N * N] = 1;
// 	dfs(step[0]);
// 	cout << answer << endl;
// }

