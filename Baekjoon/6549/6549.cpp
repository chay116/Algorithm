#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<long long> fence(100001);

long long solving(long long start, long long end) {
	if (end - start == 0) return 0;
	if (end - start == 2) return max(max(fence[start], fence[start + 1]), min(fence[start], fence[start + 1]) * 2);
	if (end - start == 1) return fence[start];
	long long mid = (end + start) / 2;
	long long answer = max(solving(start, mid), solving(mid, end));
	long long j = mid - 1, k = mid;
	long long min_value = min(fence[j], fence[k]);
	while (j > start && fence[j-1] >= min_value) j--;
	while (k < end - 1 && fence[k+1] >= min_value) k++;
	answer = max(answer, min_value * (k - j + 1));
	// cout << answer << " " << min_value << " " << j << " " << k << endl;
	while (j > start || k < end - 1) {
		if (j > start && (k == end - 1 || fence[j-1] > fence[k+1])) {
			j--; min_value = min(fence[j], min_value);
		} else {
			k++; min_value = min(fence[k], min_value);
		}
		while (j > start && fence[j-1] >= min_value) j--;
		while (k < end - 1 && fence[k+1] >= min_value) k++;
		answer = max(answer, min_value * (k - j + 1));
		// cout << answer << " " << min_value << " " << j << " " << k << endl;
	}
	// cout << "return" << endl;
	return answer;
}

int main() {
	// fastio;
	long long tmp, N; cin >> N;
	while (N) {
		for (long long i=0; i < N; i++) {
			cin >> tmp;
			fence[i] = tmp;
		}
		cout << solving(0, N) << endl;
		cin >> N;
	}
}