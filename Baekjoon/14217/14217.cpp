#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
vector<int> cities[502];
queue<int> next_cities;
int dist[502];

int main() {
	fastio;
	int n, m, q;
	int a, tmp1, tmp2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		cities[tmp1].push_back(tmp2);
		cities[tmp2].push_back(tmp1);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> tmp1 >> tmp2;
		if (a == 1) {
			cities[tmp1].push_back(tmp2);
			cities[tmp2].push_back(tmp1);
		} else {
			auto iter1 = find(cities[tmp1].begin(), cities[tmp1].end(), tmp2);
			auto iter2 = find(cities[tmp2].begin(), cities[tmp2].end(), tmp1);
			cities[tmp1].erase(iter1);
			cities[tmp2].erase(iter2);
		}
		fill(dist, dist + 502, 0);
		next_cities.push(1);
		while (!next_cities.empty()) {
			int city_num = next_cities.front();
			next_cities.pop();
			for (auto city : cities[city_num]) {
				if (dist[city] != 0 || city == 1) continue;
				dist[city] = dist[city_num] + 1;
				next_cities.push(city);
			}
		}
		cout << "0";
		for (int i = 2; i <= n; i++) {
			if (dist[i]) cout << " " << dist[i];
			else cout << " -1";
		}
		cout << endl;
	}
	return 0;
}
