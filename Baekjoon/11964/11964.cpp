#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int before[5000001];
int after[5000001];

int main() {
	fastio;
	int T, A, B;
	cin >> T >> A >> B;
	after[0] = 1; before[0] = 1;
	int answer = 0;
	for (int i=0; i <= T; i++) {
		if (before[i] == 0) continue;
		answer = max(i, answer);
		if (i + A <= T) before[i + A] = 1;
		if (i + B <= T) before[i + B] = 1;
		after[i/2] = 1;
	}

	for (int i=0; i <= T; i++) {
		if (after[i] == 0) continue;
		answer = max(i, answer);
		if (i + A <= T) after[i + A] = 1;
		if (i + B <= T) after[i + B] = 1;
	}
	cout << answer << endl;
}
