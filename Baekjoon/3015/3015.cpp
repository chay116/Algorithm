#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long N, tmp, total, num, pos;

int main() {
	fastio;
	cin >> N;
	total = 0;
	vector<pair<long long, int>> arr(500'000, {0, 1});
	int seeing;
	cin >> tmp;
	pos++;
	arr[0].first = tmp;
	while (--N) {
		cin >> tmp;
		seeing = 0;
		while (pos != 0 && (arr[pos - 1].first < tmp)) {
			seeing += arr[pos - 1].second;
			pos--;
		}
		if (pos != 0 && arr[pos - 1].first == tmp) {
			total += seeing + arr[pos - 1].second;
			arr[pos - 1].second++;
			if (pos != 1) total++;
			continue;
		}
		if (pos) seeing++;
		total += seeing;
		arr[pos].first = tmp;
		arr[pos].second = 1;
		pos++;
	}
	cout << total << endl;
}

