#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
int board[1001][3];
int dp[3][1001][3];

int main() {
	int MAXX = 1'000'001;
	fastio;
	cin >> N;
	int tmp1, tmp2, tmp3;
	int ans = MAXX;
	for (int i=0; i < N; i++) {
		cin >> board[i][0] >> board[i][1] >> board[i][2];
	}

	dp[0][0][0] = board[0][0]; dp[0][0][1] = MAXX; dp[0][0][2] = MAXX;
	dp[1][0][0] = MAXX; dp[1][0][1] = board[0][1]; dp[1][0][2] = MAXX;
	dp[2][0][0] = MAXX; dp[2][0][1] = MAXX; dp[2][0][2] = board[0][2];
	for (int j=0; j < 3; j++) {
		for (int i=1; i < N; i++) {
			dp[j][i][0] = min(dp[j][i-1][1] + board[i][0], dp[j][i-1][2] + board[i][0]);
			dp[j][i][1] = min(dp[j][i-1][0] + board[i][1], dp[j][i-1][2] + board[i][1]);
			dp[j][i][2] = min(dp[j][i-1][0] + board[i][2], dp[j][i-1][1] + board[i][2]);
		}
	}
	for (int j=0; j < 3; j++) {
		for (int i=0; i < 3; i++) {
			if (i != j && dp[i][N-1][j]) ans = min(dp[i][N-1][j], ans);
		}
	}
	cout << ans << endl;
}

