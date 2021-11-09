#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<long long> arr;
int best_j, best_k;

long long DQ(int start, int end) {
	if (end - start == 1) return (arr[start + 1] - arr[start]) * (arr[start + 1] - arr[start]);
	int mid = (start + end)/2;
	long long result = max(DQ(start, mid), DQ(mid, end));
	int j = mid - 1; int k = mid; long long min_value = min((arr[j + 1] - arr[j]), (arr[k + 1] - arr[k]));
	while (j > start && (arr[j] - arr[j-1]) >= min_value) j--;
	while (k < end - 1 && (arr[k+2] - arr[k+1]) >= min_value) k++;
	if (result < min_value * (arr[k+1] - arr[j])) {
		result = min_value * (arr[k+1] - arr[j]);
	}
	while (j > start || k < end - 1) {
		if (j > start && (k == end - 1 || (arr[j] - arr[j-1]) > (arr[k+2] - arr[k+1]))) {
			j--; min_value = (arr[j + 1] - arr[j]);
			while (j > start && (arr[j] - arr[j-1]) >= min_value) j--;
		} else {
			k++; min_value = (arr[k + 1] - arr[k]);
			while (k < end - 1 && (arr[k+2] - arr[k+1]) >= min_value) k++;
		}
		if (result < min_value * (arr[k+1] - arr[j])) {
			result = min_value * (arr[k+1] - arr[j]);
		}
	}
	return result;
}

int main() {
	fastio;
	long long a = 0;
	long long tmp, N; cin >> N;
	arr.reserve(N);
	arr.push_back(0);
	for (int i=0; i < N; i++) {
		cin >> tmp;
		a += tmp;
		arr.push_back(a);
	}
	long long answer = DQ(0, N);
	cout << answer << endl;
	// cout << best_j << " " << best_k << endl;
}


