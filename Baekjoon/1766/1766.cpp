#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N,M;
int ans = INT_MAX;
int checks[32'001];
vector<vector<int>> arr;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	fastio;
	cin >> N >> M;
	arr.assign(32'001, vector<int>());
	int tmp1, tmp2;
	for (int i=0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		arr[tmp1].push_back(tmp2);
		checks[tmp2]++;
	}

	for (int i=1; i <= N; i++) {
		if (checks[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int idx = q.top(); q.pop();
		cout << idx << " ";
		for (auto ar : arr[idx]) {
			if (--checks[ar] == 0) q.push(ar);
		}
	}
	cout << endl;
};
