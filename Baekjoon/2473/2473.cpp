#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long N, ans1, ans2, ans3;
long long ans0 = __LONG_LONG_MAX__;

long long abss(long long num) {
	if (num < 0) return -num;
	else return num;
}

int main() {
	fastio;
	cin >> N;
	vector<long long> arr(N, 0);
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i=0; i < N-2; i++) {
		int start = i + 1;
		int end = N - 1;
		while (start != end) {
			long long sums = arr[i] + arr[start] + arr[end];
			if (abss(sums) < ans0) {
				ans1 = arr[i]; ans2 = arr[start]; ans3 = arr[end];
				ans0 = abss(sums);
			}
			if (sums >= 0) end--;
			else start++;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
}