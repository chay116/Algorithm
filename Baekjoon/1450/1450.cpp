#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long weights[31];
long long acc[31];
long long N, C;
long long ans;

void dfs(int i, int target) {
	if (i == N) {
		ans++;
		return;
	}
	if (target + acc[i] <= C) ans += 1 << (N - i);
	else {
		if (target + weights[i] <= C) dfs(i + 1, target + weights[i]);
		dfs(i + 1, target);
	}
}

int main() {
	fastio;
	cin >> N >> C;
	for (int i=0; i < N; i++) cin >> weights[i];
	sort(weights, weights + N, greater<int>());
	acc[N-1] = weights[N-1];
	for (int i = N - 2; i >= 0; --i) acc[i] = acc[i + 1] + weights[i];
	dfs(0, 0);
	cout << ans << endl;
}

