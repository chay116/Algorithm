#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;

int main() {
	fastio;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> ans(N, 0);
	vector<int> up;
	for (int i=0; i < N; i++) {
		auto a = lower_bound(up.begin(), up.end(), arr[i]);
		ans[i] = a - up.begin();
		if (a == up.end()) up.push_back(arr[i]);
		else *a = arr[i];
	}

	vector<int> down;
	for (int i=N - 1; i >= 0; i--) {
		auto a = lower_bound(down.begin(), down.end(), arr[i]);
		ans[i] += a - down.begin();
		if (a == down.end()) down.push_back(arr[i]);
		else *a = arr[i];
	}

	// for (int i=0; i < N; i++) {
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
	cout << *max_element(ans.begin(), ans.end()) + 1 << endl;
}

