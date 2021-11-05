#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
#define int int64_t

const int dx[8] = {1, 0, -1, 1, 0, -1, 1, -1};
const int dy[8] = {1, 1, 1, -1, -1, -1, 0, 0};
vector<string> board;
bool	check[5][5][11];
string	name;

bool	finding(int x, int y, int size) {
	if (name.size() == size + 1) return true;
	for (int i = 0; i < 8; i++) {
		if (x + dx[i] < 5 && x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < 5) {
			if (name[size + 1] == board[x + dx[i]][y + dy[i]] && check[x + dx[i]][y + dy[i]][size + 1]) {
				if (finding(x + dx[i], y + dy[i], size + 1)) return true;
				else check[x + dx[i]][y + dy[i]][size + 1] = false;
			}
		}
	}
	return false;
}

bool	solving(void) {
	for (int i = 0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			if ((name[0] == board[i][j]) && finding(i, j, 0)) return true;
		}
	}
	return false;
}

int32_t main() {
	fastio;
	for (int i = 0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			for (int k=0; k < 11; k++) check[i][j][k] = true;
		};
	};

	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		for (int j=0; j < 5; j++) {
			cin >> name;
			board.push_back(name);
		};

		int N; cin >> N;
		for (int j=0; j < N; j++) {
			cin >> name;
			cout << name;
			if (solving()) cout << " YES\n";
			else cout << " NO\n";
			for (int l = 0; l < 5; l++) {
				for (int m=0; m < 5; m++) {
					for (int n=0; n < 11; n++) check[l][m][n] = true;
				};
			};
		};
		board.clear();
	}
}
