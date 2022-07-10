#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int arr[2001];
int ans[2001][2001];
int main() {
	fastio;
	int N, M, tmp1, tmp2;
	cin >> N;
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i=0; i < N; i++) {
		int x = i;
		int y = i;
		while (x >= 0 && y < N) {
			if (arr[x] != arr[y]) break;
			ans[x][y] = 1;
			x--; y++;
		}
		x = i;
		y = i + 1;
		while (x >= 0 && y < N) {
			if (arr[x] != arr[y]) break;
			ans[x][y] = 1;
			x--; y++;
		}
	}

	cin >> M;
	while (M--) {
		cin >> tmp1 >> tmp2;
		if (ans[tmp1 - 1][tmp2 - 1]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}