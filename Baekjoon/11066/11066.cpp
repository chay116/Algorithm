#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long N, T;
pair<long long, long long> board[501][501];

int main() {
	long long MAXX = __LONG_LONG_MAX__;
	fastio;
	cin >> T;
	while (T--) {
		cin >> N;
		for (long long i=0; i<N; i++) {
			cin >> board[i][i].second;
			board[i][i].first = 0;
			for (long long j=i-1; j>=0; j--) {
				board[i][j].first = MAXX;
				for (long long k=i; k>j; k--) {
					long long tmp = board[i][k].first + board[k-1][j].first + board[i][k].second + board[k-1][j].second;
					if (board[i][j].first > tmp) {
						board[i][j].first = tmp;
						board[i][j].second = board[i][k].second + board[k-1][j].second;
					}
				}
			}
		}
		cout << board[N-1][0].first << endl;
	}
}

