#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<pair<long long, long long>> board;
int main() {
	fastio;
	int N; cin >> N;
	double ans = 0;
	long long ox, oy, tmp1, tmp2;
	cin >> ox >> oy;
	for (int i=1; i < N; i++) {
		cin >> tmp1 >> tmp2;
		board.push_back({tmp1, tmp2});
	}
	for (int i=0; i < N - 2; i++) {
		ans += (ox - board[i].first) * (oy - board[i + 1].second)
			- (ox - board[i + 1].first) * (oy - board[i].second);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans/2) << endl;
}
