#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long visited[16][1 << 16];
long long weight[16][16];
long long N;
long long allvisited;
long long MAXX = 987654321;
long long dfs(long long visiting, long long start) {
	if (visiting == allvisited) {
		if (weight[start][0] == 0) return MAXX;
		return weight[start][0];
	};
	if (visited[start][visiting]) return visited[start][visiting];
	visited[start][visiting] = MAXX;
	for (long long i=1; i < N; i++) {
		if (!weight[start][i] || visiting & (1 << i)) continue;
		visited[start][visiting] = min(visited[start][visiting], dfs(visiting | (1 << i), i) + weight[start][i]);
	}
	return visited[start][visiting];
}

int main() {
	fastio;
	cin >> N;
	for (long long i=0; i < N; i++) {
		for (long long j=0; j < N; j++) {
			cin >> weight[i][j];
		}
	}
	allvisited = (1 << N) - 2;
	cout << dfs(0, 0) << endl;
}