#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
bitset<(1 << 25)> arr;
int main() {
	fastio;
	int tmp;
	while (scanf("%d", &tmp) != EOF) {
		if (!arr[tmp]) {
			cout << tmp << " ";
			arr[tmp] = 1;
		}
	}
	return 0;
}
