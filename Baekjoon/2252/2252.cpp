#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define MAX_LEN 32002

int arr[MAX_LEN];
queue <int> q;

int main() {
	fastio;
	int N, M, tmp1, tmp2; cin >> N >> M;
	vector<vector<int>> board(N + 1, vector<int>());
	for (int i=0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		board[tmp1].push_back(tmp2);
		arr[tmp2] += 1;
	}
	for (int i=1; i <= N; i++) {
		if (arr[i] == 0) q.push(i);
	}
	int now, next, start = 0;
	while (!q.empty()) {
		now = q.front(); q.pop();
		if (start == 0) {
			cout << now;
			start = 1;
		} else cout << " " << now;
		for (int i=0; i < board[now].size(); i++) {
			next = board[now][i];
			if (--(arr[next]) == 0) q.push(next);
		}
	}
	cout << endl;
}
