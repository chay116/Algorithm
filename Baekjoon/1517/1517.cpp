#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
#define int int64_t

int answer = 0;

int *merge_sort(int *arr, int start, int end) {
	int *result;
	if (end - start == 1) {
		result = new int[1];
		*result = *arr;
		return result;
	}
	else if (end - start == 2) {
		result = new int[2];
		*result = *arr;
		return result;
	}
}

int main() {
	// fastio;
	int N, tmp; cin >> N;
	int arr[N];
	for (int j=0; j < N; j++) {
		cin >> tmp; arr[j] = tmp;
	}
	merge_sort(arr, 0, N);
	cout << answer << endl;
}
