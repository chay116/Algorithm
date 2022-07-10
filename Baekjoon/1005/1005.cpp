#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int status[1001];
int timetable[1001];
vector<vector<int>> board(1001, vector<int>());

int main() {
	fastio;
	int tmp, T, N, K, W, num1, num2;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i=1; i <= N; i++) {
			cin >> tmp;
			timetable[i] = tmp;
			status[i] = 0;
			board[i].clear();
		}

		for (int i=0; i < K; i++) {
			cin >> num1 >> num2;
			board[num1].push_back(num2);
			status[num2]++;
		}
		cin >> W;
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
		for (int i=1; i <= N; i++) {
			if (status[i] == 0) {
				status[i] == -1;
				q.push(make_pair(timetable[i], i));
			}
		}

		int passedTime = -1;
		while (status[W] != -1) {
			passedTime = q.top().first;
			int next = q.top().second; q.pop();
			status[next] = -1;
			for (int i=0; i < board[next].size(); i++) {
				if (--status[board[next][i]] == 0) {
					q.push(make_pair(timetable[board[next][i]] + passedTime, board[next][i]));
				}
			}
		}
		cout << passedTime << endl;
	}
}


