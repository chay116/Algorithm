#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

queue<int> q;
int place1, place2, N;

int checking(int weight, vector<vector<int>> board, vector<int> visited) {
	int now;

	visited.assign(N, 0);
	visited[place1] = 1;
	q.push(place1);
	while (!q.empty()) {
		now = q.front(); q.pop();
		if (now == place2) {
			while (!q.empty()) q.pop();
			return 1;
		}
		for (int i=0; i < N; i++) {
			if (visited[i] == 0 && weight <= board[now][i]) {
				q.push(i); visited[i] = 1;
			}
		}
	}
	return 0;
}

int main() {
	fastio;
	int M, num1, num2, weight; cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(N, 0));
	vector<int> visited(N, 0);
	for (int i=0; i < M; i++) {
		cin >> num1 >> num2 >> weight;
		board[num1 - 1][num2 - 1] = weight;
		board[num2 - 1][num1 - 1] = weight;
	}
	cin >> place1 >> place2;
	place1--; place2--;
	int start = 0; int end = 1000000000;
	while (start + 1 < end) {
		weight = (start + end) / 2;
		cout << weight << endl;
		if (checking(weight, board, visited)) start = weight;
		else end = weight;
	}
	if (checking(start, board, visited)) cout << start << endl;
	else cout << start + 1 << endl;
}


