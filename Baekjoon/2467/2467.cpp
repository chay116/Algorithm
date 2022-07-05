#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long N, low, high;
long long answer;
long long ans[2];
int main() {
	fastio;
	cin >> N;
	vector<long long> arr(N, 0);
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}
	answer = INT_MAX;
	low = 0;
	high = N - 1;
	ans[0] = arr[low];
	ans[1] = arr[high];
	while (low != high) {
		long long tmp = arr[high] + arr[low];
		if (answer >= abs(tmp)) {
			ans[0] = arr[low];
			ans[1] = arr[high];
			answer = abs(tmp);
			// cout << ans[0] << " " << ans[1] << endl;
		}
		if (tmp > 0) high--;
		else if (tmp < 0) low++;
		else break;
	}
	cout << ans[0] << " " << ans[1] << endl;
}


