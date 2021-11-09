#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int main() {
	fastio;
	int N; cin >> N;
	N /= 3;
	int k =0;
	while (N != 1) {
		N /= 2;
		k++;
	}

}

