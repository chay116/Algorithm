#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

#define ll long long

ll total = 0;
ll dict[55];

int check_bit(ll tmp) {
	int result = 0;
	while (tmp) {
		if (tmp & 1) result++;
		tmp >>= 1;
	}
	return result;
}

void dfs(ll A, ll B, ll bitB, int step) {
	if (A == B) {
		total += bitB;
		return ;
	}
	if (A & (1LL << step)) {
		ll bitA = check_bit(A);
		total += dict[step] + (1LL << step) * bitA;
		A += (1LL << step);
	}
	if (B & (1LL << step)) {
		total += bitB;
		bitB--;
		total += dict[step] + ((1LL << step) - 1LL) * bitB;
		B -= (1LL << step);
	}
	dfs(A, B, bitB, step + 1);
}

int main() {
	fastio;
	ll A, B;
	cin >> A >> B;
	dict[1] = 1;
	for (int i=2; i<55; i++) {
		dict[i] = dict[i-1] * 2 + (1LL << (i-1));
	}
	dfs(A, B, check_bit(B), 0);
	cout << total << endl;
}