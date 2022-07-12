#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

unsigned long long D, num1, num2;
map<unsigned long long, unsigned long long**> mapping;

struct Path{
	unsigned long long **board;
	Path(unsigned long long **ref) : board(ref) {};
	Path() {
		board = new unsigned long long*[8];
		for (unsigned long long i=0; i < 8; i++) {
			board[i] = new unsigned long long[8];
		}
	};
	Path operator*(const Path& ref) const {
		Path tmp{};
		for (unsigned long long i=0; i < 8; i++) {
			for (unsigned long long j=0; j < 8; j++) {
				tmp.board[i][j] = 0;
				for (unsigned long long k=0; k < 8; k++) {
					tmp.board[i][j] += board[i][k] * ref.board[k][j];
					tmp.board[i][j] %= 1'000'000'007;
				};
			}
		}
		return tmp;
	}
};

Path dfs(unsigned long long step) {
	// cout << step << mapping[step] << endl;
	if (mapping[step]) return Path(mapping[step]);
	Path tmp;
	if (step % 2) {
		tmp = dfs(step/2) * dfs(step/2) * dfs(1);
	} else {
		tmp = dfs(step/2) * dfs(step/2);
	}
	mapping[step] = tmp.board;
	return tmp;
}

int main() {
	fastio;
	cin >> D;
	unsigned long long **board = new unsigned long long*[8];
	for (unsigned long long i=0; i < 8; i++) {
		board[i] = new unsigned long long[8];
		for (unsigned long long j=0; j < 8; j++) {
			board[i][j] = 0;
		}
	}
	board[0][1] = 1; board[0][2] = 1;
	board[1][0] = 1; board[1][2] = 1; board[1][3] = 1;
	board[2][0] = 1; board[2][1] = 1; board[2][3] = 1; board[2][4] = 1;
	board[3][1] = 1; board[3][2] = 1; board[3][4] = 1; board[3][5] = 1;
	board[4][2] = 1; board[4][3] = 1; board[4][5] = 1; board[4][7] = 1;
	board[5][3] = 1; board[5][4] = 1; board[5][6] = 1;
	board[6][5] = 1; board[6][7] = 1;
	board[7][4] = 1; board[7][6] = 1;
	mapping[1] = board;

	Path ans = dfs(D);
	cout << ans.board[0][0] << endl;
}