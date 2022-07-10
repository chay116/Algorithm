#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int board[9][9];
int block[3][3][10];
int horizon[9][10];
int vertical[9][10];
vector<pair<int, int>> candidate;
bool ending = false;
void dfs(int step) {
	if (ending) return;
	if (step == candidate.size()) {
		for (int i=0; i < 9; i++) {
			for (int j=0; j < 9; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}
		ending = true;
		return ;
	}
	int i = candidate[step].first;
	int j = candidate[step].second;
	for (int k=1; k <= 9; k++) {
		if (block[i/3][j/3][k] || horizon[i][k] != 0 || vertical[j][k] != 0) continue;
		block[i/3][j/3][k] = 1;
		horizon[i][k] = 1;
		vertical[j][k] = 1;
		board[i][j] = k;
		dfs(step + 1);
		board[i][j] = 0;
		block[i/3][j/3][k] = 0;
		horizon[i][k] = 0;
		vertical[j][k] = 0;
	}
}

int main() {
	fastio;
	int tmp;
	for (int i=0; i < 9; i++) {
		cin >> tmp;
		for (int j=8; j >= 0; --j) {
			board[i][j] = tmp % 10;
			block[i/3][j/3][board[i][j]] = 1;
			horizon[i][board[i][j]] = 1;
			vertical[j][board[i][j]] = 1;
			tmp /= 10;
		}
		for (int j=0; j < 9; ++j) {
			if (board[i][j] == 0) candidate.push_back({i, j});
		}
	}

	dfs(0);
}