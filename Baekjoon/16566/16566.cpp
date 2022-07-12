#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int cards[4'000'003];
int quest[4'000'003];
int ans[10'000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main() {
	fastio;
	int N, M, K, tmp;
	cin >> N >> M >> K;
	for (int i=0; i < M; i++) {
		cin >> tmp; cards[tmp]++;
	}
	for (int i=0; i < K; i++) {
		cin >> tmp; pq1.push({tmp, i}); quest[tmp]++;
	}
	for (int i=1; i <= N+1; i++) {
		if (cards[i]) {
			while (!pq2.empty() && cards[i]--) {
				int idx = pq2.top(); pq2.pop();
				ans[idx] = i;
			}
		}
		if (quest[i]) {
			while (quest[i]--) {
				pq2.push(pq1.top().second); pq1.pop();
			};
		}
	}
	for (int i=0; i < K; i++) {
		cout << ans[i] << "\n";
	}
}