#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, finished;
vector<vector<int>> board(1001, vector<int>(1001, 0));
vector<int> status(1001, 0);
vector<int> timetable(1001, 0);
queue<pair<int, int>> q;

int main() {
	fastio;
	pair<int, int> tmp;
	int T, K, num1, num2, answer; cin >> N >> K;

	for (int i=1; i <= N; i++) {
		cin >> T; timetable[i] = T;
	}

	for (int i=0; i < K; i++) {
		cin >> num1 >> num2;
		board[num1][num2] = 1;
		status[num2]++;
	}

	for (int i=1; i <= N; i++) {
		if (status[i] == 0) q.push(make_pair(i, 0));
	}

	answer = -1;
	while(!q.empty()) {
		num1 = q.front().first;
		num2 = q.front().second;
		q.pop();
		if (num2 ==)
		for (int i=1; i <= N; i++) {
			if (board[tmp][i] == 1)
				if (!--status[i]) q.push(i);
	}
}


