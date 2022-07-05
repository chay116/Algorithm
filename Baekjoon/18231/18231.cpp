#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
vector<int> cities[2001];
int onfire[2001];
int candidate[2001];
int sum;
int result[2001];

int main() {
	fastio;
	int n, m, k;
	int a, tmp1, tmp2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cities[i].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		cities[tmp1].push_back(tmp2);
		cities[tmp2].push_back(tmp1);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tmp1; onfire[tmp1] = 1;
	};

	for (int i = 1; i <= n; i++) {
		int success = 0;
		for (auto n : cities[i]) {
			if (!onfire[n]) {
				success = 1;
				break ;
			}
		}
		if (success) continue;
		candidate[i] = 1;
		for (auto n : cities[i]) {
			result[n] = 1;
		}
		sum++;
	};
	for (int i = 1; i <= n; i++) {
		if (result[i] != onfire[i]) {
			sum = 0;
			break ;
		}
	}
	if (sum != 0) {
		cout << sum << endl;

		for (int i = 1; i <= n; i++) {
			if (candidate[i]) cout << i << " ";
		};
		cout << endl;
	} else {
		cout << "-1" << endl;
	};

	return 0;
}
