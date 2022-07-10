#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int board[1002][1002];
char str1[1002];
char str2[1002];

int main() {
	fastio;
	cin >> (str1 + 1) >> (str2 + 1);
	for (int i=1; i < 1002; i++) {
		if (str1[i] == 0) {
			i = 1001; continue;
		}
		for (int j=1; j < 1002; j++) {
			if (str1[i] == str2[j]) {
				board[i][j] = board[i - 1][j - 1] + 1;
			} else {
				board[i][j] = max(board[i-1][j], board[i][j-1]);
			}
		}
	}
	std::string answer{};
	int x = strlen(str1 + 1);
	int y = strlen(str2 + 1);
	while (board[x][y] != 0) {
		if (str1[x] == str2[y]) {
			answer += str1[x]; x--; y--;
		} else {
			if (board[x-1][y] == board[x][y]) x--;
			else y--;
		}
	}
	cout << answer.size() << endl;
	if (answer.size()) {
		reverse(answer.begin(), answer.end());
		cout << answer << endl;
	}
}