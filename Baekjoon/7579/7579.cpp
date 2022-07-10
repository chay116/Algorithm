#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;
vector<pair<int, int>> board;
vector<pair<float, int>> arr;
int ansboard[101][10001];

int main() {
	fastio;
	cin >> N >> M;
	board.assign(N, {0, 0});
	arr.assign(N, {0, 0});
	for (int i=0; i < N; i++) {
		cin >> board[i].first;
	}
	for (int i=0; i < N; i++) {
		cin >> board[i].second;
		arr[i].first = (float)board[i].first / (float)board[i].second;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());
	for (int i=0; i < N; i++) {
		int memory = board[arr[i].second].first;
		int cost = board[arr[i].second].second;
		for (int j=0; j < 10001; j++) {
			if (j >= cost)
				ansboard[i + 1][j] = max(ansboard[i][j], ansboard[i][j - cost] + memory);
			else
				ansboard[i + 1][j] = ansboard[i][j];
		}
	}
	int i = 0;
	while (ansboard[N][i] < M) i++;
	cout << i << endl;
}