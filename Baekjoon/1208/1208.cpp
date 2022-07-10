#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, S, tmp;
long long arr[8'000'001];


int main() {
	fastio;
	cin >> N >> S;
	int count = 0;
	while (N--) {
		cin >> tmp;
		if (tmp < 0) {
			for (int i=4'000'000 - count; i <= 4'000'000 + count; ++i) arr[i + tmp] += arr[i];
		} else {
			for (int i=4'000'000 + count; i >= 4'000'000 - count; --i) arr[i + tmp] += arr[i];
		}
		arr[4'000'000 + tmp]++;
		count += abs(tmp);
	}
	cout << arr[4'000'000 + S] << endl;
}