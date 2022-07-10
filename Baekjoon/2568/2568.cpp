#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int board[500'001];
int ans[500'001];
int main() {
	fastio;
	int N, tmp1, tmp2; int cnt =0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i=0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		pq.push(tmp1);
		board[tmp1] = tmp2;
		ans[tmp1] = true;
	}

	vector<int> line;
	vector<vector<pair<int, int>>> dl;
	while (!pq.empty()) {
		int idx = pq.top(); pq.pop();
		auto tmp = lower_bound(line.begin(), line.end(), board[idx]);
		if (tmp == line.end()) {
			line.push_back(board[idx]);
			// cout << idx << " " << board[idx] << " 1 " << line.size() << endl;
			dl.push_back(vector<pair<int, int>>(1, {idx, idx}));
		}
		else {
			cnt++;
			*tmp = board[idx];
			auto pos = tmp - line.begin();
			// cout << idx << " " << board[idx] << " 2 " << pos + 1 << endl;
			dl[pos].push_back({idx, idx});
		}
	}

	int criteria = dl[dl.size() - 1][(dl[dl.size() - 1]).size() - 1].second;
	for (int i = dl.size() - 1; i >= 0; i--) {
		for (int j = (dl[i]).size() - 1; j >= 0; j--) {
			if (dl[i][j].second <= criteria) {
				ans[dl[i][j].first] = false;
				criteria = dl[i][j].second;
				break;
			}
		}
	}

	cout << cnt << "\n";
	for (int i=0; i < 500'001; i++) {
		if (ans[i]) cout << i << "\n";
	}
}