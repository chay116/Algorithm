#include <vector>
#include <iostream>
#include <queue>
#include <math.h>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, T;
double ans;
vector<pair<double, double>> storage;
void dfs(double totalx, double totaly, int step, int changed) {
	if (changed == N/2) {
		ans = min(ans, sqrt(totalx * totalx + totaly * totaly));
		return ;
	}
	if (step >= N) return ;
	dfs(totalx, totaly, step + 1, changed);
	dfs(totalx - 2 * storage[step].first, totaly - 2 * storage[step].second, step + 1, changed + 1);
}

int main() {
	fastio;
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 1000000000.0;
		storage.clear();
		double tmp1, tmp2;
		double totalx = 0; double totaly = 0;
		for (int i=0; i < N; i++) {
			cin >> tmp1 >> tmp2;
			totalx += tmp1; totaly += tmp2;
			storage.emplace_back(tmp1, tmp2);
		}
		dfs(totalx, totaly, 0, 0);
		cout.precision(20);
		cout << ans << endl;
	}
}