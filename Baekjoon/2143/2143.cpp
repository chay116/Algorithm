#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

long long T, N, M;
long long num1[1'001];
long long num2[1'001];
map<long long, long long> map1;

int main() {
	fastio;
	cin >> T;
	cin >> N;
	for (long long i=0; i < N; i++) {
		cin >> num1[i];
		long long total = 0;
		for (long long j = i; j >= 0; j--) {
			total += num1[j];
			if (map1[total]) map1[total] = map1[total] + 1;
			else {
				map1[total] = 1;
				// pq1.push(total);
			}
		}
	};
	cin >> M;
	long long ans = 0;
	for (long long i=0; i < M; i++) {
		cin >> num2[i];
		long long total = 0;
		for (long long j = i; j >= 0; j--) {
			total += num2[j];
			ans += map1[T - total];
		}
	};

	cout << ans << endl;
}

