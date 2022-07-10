#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<vector<int>> ans(1'000'001, vector<int>());
int board[1'000'001];

int main() {
	int N; cin >> N;
	ans[1].push_back(1);
	for (int i=1; i <= N; i++) board[i] = 1000000;
	board[1] = 0;
	for (int i=1; i < N; i++) {
		if (N > i && board[i + 1] > board[i] + 1) {
			ans[i + 1] = ans[i]; ans[i + 1].push_back(i + 1);
			board[i + 1] = board[i] + 1;
		}
		if (N >= i * 2 && board[i * 2] > board[i] + 1) {
			ans[i * 2] = ans[i]; ans[i * 2].push_back(i * 2);
			board[i * 2] = board[i] + 1;
		}
		if (N >= i * 3 && board[i * 3] > board[i] + 1) {
			ans[i * 3] = ans[i]; ans[i * 3].push_back(i * 3);
			board[i * 3] = board[i] + 1;
		}
	}
	cout << board[N] << endl;
	for (int i = ans[N].size() - 1; i >= 0; --i) cout << ans[N][i] << " ";
	cout << endl;
}
