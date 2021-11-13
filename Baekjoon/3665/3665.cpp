#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define MAX_LEN 502

int arr[MAX_LEN][MAX_LEN];
int teams[MAX_LEN];
int node[MAX_LEN];

int main() {
	fastio;
	int C; cin >> C;
	while (C--) {
		memset(arr, 0, sizeof(arr));
		memset(teams, 0, sizeof(teams));
		memset(node, 0, sizeof(node));
		int N, M, tmp1, tmp2; cin >> N;
		for (int i=1; i <= N; i++) {
			cin >> tmp1;
			for (int j=1; j < i; j++) {
				arr[teams[j]][tmp1] = 1;
				node[tmp1]++;
			}
			teams[i] = tmp1;
		}
		cin >> M;
		for (int i=0; i < M; i++) {
			cin >> tmp1 >> tmp2;
			if (arr[tmp1][tmp2]) {
				arr[tmp1][tmp2] = 0; node[tmp2]--;
				arr[tmp2][tmp1] = 1; node[tmp1]++;
			} else {
				arr[tmp2][tmp1] = 0; node[tmp1]--;
				arr[tmp1][tmp2] = 1; node[tmp2]++;
			}
		}

		queue <int> q;
		vector<int> result;
		for (int i=1; i <= N; i++) {
			if (node[i] == 0) q.push(i);
		}
		int now, end = 0;
		while (!q.empty()) {
			now = q.front(); q.pop();
			result.push_back(now);
			for (int i=1; i <= N; i++) {
				if (arr[now][i] && --(node[i]) == 0) q.push(i);
			}
		}
		if (end == 1 || result.size() != N){
			result.clear();
			cout << "IMPOSSIBLE" << endl;
		} else {
			for (int i=0; i < result.size() - 1; i++) cout << result[i] << " ";
			cout << result[result.size() - 1] << endl;
			result.clear();
		}
	}
}
