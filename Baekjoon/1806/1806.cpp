#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, S;
int main() {
	fastio;
	cin >> N >> S;
	vector<int> arr(N, 0);

	int ans = N + 1;
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 1;
	int total = arr[start];
	while (1) {
		if (total >= S) {
			ans = min(ans, end - start);
			total -= arr[start];
			start++;
		} else {
			if (end == N) break;
			total += arr[end];
			end++;
		}
	}
	if (ans == N + 1 ) cout << 0 << endl;
	else cout << ans << endl;
}