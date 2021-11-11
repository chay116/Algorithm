#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long answer = 0;

vector<long long> merge_sort(vector<long long> &arr, long long start, long long end) {
	vector<long long> result;
	if (end - start == 1) {
		result.push_back(arr[start]);
		return result;
	}
	else if (end - start == 2) {
		if (arr[start] > arr[start + 1]) answer += 2;
		result.push_back(min(arr[start], arr[start + 1]));
		result.push_back(max(arr[start], arr[start + 1]));
		return result;
	}
	long long mid = (end + start) / 2;
	vector<long long> front = merge_sort(arr, start, mid);
	vector<long long> back = merge_sort(arr, mid, end);
	long long i = 0; long long j = 0; result.reserve(end - start);
	// cout << answer << endl;
	while (result.size() != end - start) {
		if (i != front.size() && (j == back.size() || front[i] <= back[j])) {
			answer += j; result.push_back(front[i]); i++;
		} else {
			answer += front.size() - i; result.push_back(back[j]); j++;
		}
		// cout << i << j << endl;
	}
	return result;
}

int main() {
	// fastio;
	long long tmp;
	long long N; cin >> N;
	vector<long long> arr(N, 0);
	for (long long j=0; j < N; j++) {
		cin >> tmp; arr[j] = tmp;
	}
	merge_sort(arr, 0, N);
	cout << answer/2 << endl;
}
