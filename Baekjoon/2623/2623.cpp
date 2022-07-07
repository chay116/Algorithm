#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int inDegree[2001];

int main() {
	fastio;
	int N, M;
	cin >> N >> M;
	queue<int> q;
	vector<int> ans;
	vector<vector<int>> board(N + 1, vector<int>());

	while (M--) {
		int len, prev, next; cin >> len;
		prev = 0;
		while (len--) {
			cin >> next;
			board[prev].push_back(next);
			if (prev != 0) inDegree[next]++;
			prev = next;
		}
	}

	for (int i=1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		};
	}

	for (int i=0; i < N; i++) {
		if (q.empty()) {
			cout << 0 << endl; return 0;
		}
		int next = q.front(); q.pop(); ans.push_back(next);
		for (int j = 0; j < board[next].size(); j++) {
			if (--inDegree[board[next][j]] == 0) {
				q.push(board[next][j]);
			}
		}
	}

	for (int i=0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}