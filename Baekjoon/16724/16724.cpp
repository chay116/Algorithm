#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;
int ans = 0;
int visited[1001][1001];
int parents[100'001];

int findParents(int step) {
	if (parents[step] == step) return step;
	else return parents[step] = findParents(parents[step]);
}

int main() {
	fastio;
	cin >> N >> M;
	vector<string> arr(N, string());
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}
	int step = 0;
	int total = 0;
	for (int io=0; io<N; io++) {
		for (int jo=0; jo<M; jo++)
		{
			int i = io;
			int j = jo;
			if (visited[i][j]) continue;
			step++;
			parents[step] = step;
			while (!visited[i][j]) {
				visited[i][j] = step;
				if (arr[i][j] == 'L') j--;
				else if (arr[i][j] == 'D') i++;
				else if (arr[i][j] == 'R') j++;
				else i--;
			}
			parents[step] = visited[i][j];
			if (parents[step] == step) total++;
		}
	}
	cout << total << endl;
}

