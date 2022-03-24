#include <queue>
#include <vector>
#include <iostream>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long N;
vector<long long> ans(10);
vector<long long> adding(10);

void calculate(long long x, long long pows, long long pow_num) {
	long long res = (pow_num / 10) * pows;
	for (long long i =0; i < 10; i++) {
		ans[i] += (res + adding[i] * pow_num) * (x % 10);
	}
	for (long long i = 0; i < (x % 10); i++) {
		ans[i] += pow_num;
	}
	adding[x % 10] += 1;
};

void first_one(long long x, long long pows, long long pow_num) {
	adding[x % 10] += 1;
	long long res = (pow_num / 10) * pows;
	for (long long i = 1; i < x; i++) {
		ans[i] += pow_num;
	}
	for (long long i = 0; i < 10; i++) {
		ans[i] += res * x;
	}
};

int main() {
	cin >> N;
	long long pow_num = 1;
	long long pows = 0;
	while (N / pow_num) {
		pow_num *= 10; pows++;
	}
	long long tmp = pow_num / 10;
	if (tmp/10 == 0) ans[0] -= 1;
	while (tmp > 0) {
		tmp /= 10;
		ans[0] -= tmp;
	}
	if (pows > 1) {
		pows -= 1;
		pow_num /= 10;
		first_one(N / pow_num, pows, pow_num);
		while (--pows) {
			pow_num /= 10;
			calculate(N / pow_num, pows, pow_num);
		}
	}
	for (long long i = 0; i < 10; i++)
		ans[i] += adding[i] * (N % 10 + 1);
	for (long long i = 0; i <= (N % 10); i++)
		ans[i] += 1;

	for (long long i =0; i <= 9; i++) {
		cout << ans[i];
		if (i < 9) cout << " ";
	}
	cout << endl;
	return 0;
}
