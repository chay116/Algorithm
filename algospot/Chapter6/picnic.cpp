#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int n, m;
int answer;

void solving(int pos, vector<int> member, vector<vector<int> > board) {
	if (pos == member.size()) {
		answer++;
		return ;
	}
	if (member[pos] == 1) {
		solving(pos + 1, member, board);
		return ;
	}
	for (int i=pos; i < member.size(); i++) {
			if (board[pos][i] == 1 && member[i] == 0) {
				member[i] = 1;
				member[pos] = 1;
				solving(pos + 1, member, board);
				member[i] = 0;
				member[pos] = 0;
			}
		}
}

int main() {
	fastio;
	int C; cin >> C;
	int m1, m2;

	while (C--) {
		cin >> n >> m;
		answer = 0;
		vector<vector<int> > board(n, vector<int>(n,0));
		vector<int>member(n,0);
		for (int i=0; i < m; i++) {
			cin >> m1 >> m2;
			board[m1][m2] = 1;
			board[m2][m1] = 1;
		}
		solving(0, member, board);
		cout << answer << endl;
	}
}