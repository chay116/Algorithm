#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<long long> arr;
long long answer = -1;
int best_j = 1, best_k = 1;

void DQ(int start, int end) {
	if (end - start == 1) {
		long long result = (arr[start + 1] - arr[start]) * (arr[start + 1] - arr[start]);
		if (result > answer) {
			answer = result; best_j = start + 1; best_k = start + 1;
		}
		return ;
	}
	int mid = (start + end)/2;
	DQ(start, mid); DQ(mid, end);
	int j = mid - 1; int k = mid; long long min_value = min((arr[j + 1] - arr[j]), (arr[k + 1] - arr[k]));
	while (j > start && (arr[j] - arr[j-1]) >= min_value) j--;
	while (k < end - 1 && (arr[k+2] - arr[k+1]) >= min_value) k++;
	if (answer < min_value * (arr[k+1] - arr[j])) {
		answer = min_value * (arr[k+1] - arr[j]); best_j = j + 1; best_k = k + 1;
	}
	while (j > start || k < end - 1) {
		if (j > start && (k == end - 1 || (arr[j] - arr[j-1]) > (arr[k+2] - arr[k+1]))) {
			j--; min_value = (arr[j + 1] - arr[j]);
			while (j > start && (arr[j] - arr[j-1]) >= min_value) j--;
		} else {
			k++; min_value = (arr[k + 1] - arr[k]);
			while (k < end - 1 && (arr[k+2] - arr[k+1]) >= min_value) k++;
		}
		if (answer < min_value * (arr[k+1] - arr[j])) {
			answer = min_value * (arr[k+1] - arr[j]); best_j = j + 1; best_k = k + 1;
		}
	}
}

int main() {
	fastio;
	long long a = 0;
	long long tmp, N; cin >> N;
	arr.reserve(N + 1);
	arr.push_back(0);
	for (int i=0; i < N; i++) {
		cin >> tmp;
		a += tmp;
		arr.push_back(a);
	}
	DQ(0, N);
	cout << answer << endl;
	cout << best_j << " " << best_k << endl;
}

