#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
int nums[4'000'001];
vector<int> arr;

void getPrime(int num) {

	for(int i=2;i<=num;i++) {
		nums[i] = i;
	}

	for(int i=2;i<=num;i++) {
		if(nums[i] == 0) continue;
		if(nums[i]!=0) arr.push_back(i);
		for(int j=2 * i;j <= num; j += i) {
			nums[j] = 0;
		}
	}
}

int main() {
	fastio;
	cin >> N;
	getPrime(N);
	int start = 0;
	int end = 0;
	int ans = 0;
	int total = 0;
	while (1) {
		if (total < N) {
			if (end == arr.size()) break;
			total += arr[end];
			end++;
		} else {
			if (total == N) ans++;
			total -= arr[start];
			start++;
		}
	}
	cout << ans << endl;
}

