#include <vector>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int board[100][10][1024];

int main() {
	fastio;
	int N;
	cin >> N;
	for (int i = 0; i < 10; ++i) {
		board[0][i][1 << i] = 1;
	}

	for (int i = 1; i < N ; ++i) {
		for (int k = 1; k < 1024; ++k) {
			board[i][0][(k | 1)] += board[i - 1][1][k];
			board[i][0][(k | 1)] %= 1'000'000'000;
		}
		for (int j=1; j < 9; ++j) {
			for (int k = 1; k < 1024; ++k) {
				board[i][j][(k | (1 << j))] += board[i - 1][j + 1][k] + board[i - 1][j - 1][k];
				board[i][j][(k | (1 << j))] %= 1'000'000'000;
			}
		}
		for (int k = 1; k < 1024; ++k) {
			board[i][9][(k | 512)] += board[i - 1][8][k];
			board[i][9][(k | 512)] %= 1'000'000'000;
		}
	}

	long long ans = 0;
	for (int i = 1; i < 10 ; ++i) {
		ans = (ans + board[N-1][i][1023]) % 1'000'000'000;
	}
	cout << ans << endl;
}