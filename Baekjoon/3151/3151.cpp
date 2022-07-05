#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, low, high;
long long answer;
int main() {
	fastio;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int tmp = 0;
	answer = 0;
	while (tmp < N - 2) {
		low = tmp + 1;
		high = N - 1;
		while (low < high) {
			int now = arr[high] + arr[low];
			if (now + arr[tmp] > 0) high--;
			else if (now + arr[tmp] < 0) low++;
			else {
				if (arr[low] == arr[high]) {
					answer += ((high - low + 1) * (high - low)) / 2;
					break ;
				}
				int tmp1 = low + 1;
				int tmp2 = high - 1;
				while (arr[tmp1] == arr[low])
					tmp1++;
				while (arr[tmp2] == arr[high])
					tmp2--;
				answer += (tmp1 - low) * (high - tmp2);
				low = tmp1;
				high = tmp2;
			}
		}
		tmp++;
	}
	std::cout << answer << endl;
}
