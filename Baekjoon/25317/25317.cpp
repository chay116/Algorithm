#include <vector>
#include <map>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	// fastio;
	int Q; cin >> Q;
	int N;
	vector<float> queries;
	int default_minus = 0;
	bool default_zero = 0;
	bool sorted = false;
	while (Q--) {
		cin >> N;
		if (N == 1) {
			float a, b;
			cin >> a >> b;
			if (a == 0) {
				if (b < 0) default_minus++;
				else if (b == 0) default_zero = true;
			} else if (a < 0) {
				a *= -1;
				b *= -1;
				default_minus++;
			}
			float ans = -(b / a);
			queries.push_back(ans);
			sorted = false;
		} else {
			float c; cin >> c;
			if (default_zero) {
				cout << 0 << endl;
			}
			else {
				if (!sorted) {
					sort(queries.begin(), queries.end());
					sorted = true;
				}
				auto lower = lower_bound(queries.begin(), queries.end(), c);
				if (lower != queries.end() && *lower == c) cout << 0 << endl;
				else {
					int idx = queries.end() - lower_bound(queries.begin(), queries.end(), c);
					(default_minus + idx) % 2 ? cout << '-' << endl : cout << '+' << endl;
				}
			}
		}
	}
}
