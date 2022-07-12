#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<int>> board(2501, vector<int>());
int minboard[2501];
int len;

int dfs(int step, int total) {
	if (step == len) return 1;
	if (minboard[step] != 0) return minboard[step];
	minboard[step] = 2501;
	for (auto num : board[step]) minboard[step] = min(minboard[step], dfs(num + 1, total) + 1);
	return minboard[step];
}

int main() {
	fastio;
	std::string str;
	cin >> str;
	len = str.size();

	for (int i=0; i < len; i++) {
		int x = i;
		int y = i;
		while (x >= 0 && y < len) {
			if (str[x] != str[y]) break;
			board[x].push_back(y);
			x--; y++;
		}
		x = i;
		y = i + 1;
		while (x >= 0 && y < len) {
			if (str[x] != str[y]) break;
			board[x].push_back(y);
			x--; y++;
		}
	}
	cout << dfs(0, 0) - 1<< endl;
}
