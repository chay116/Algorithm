#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define ll long long
#define ARR_SIZE 1000001
ll arr[ARR_SIZE];
ll tree[4 * ARR_SIZE];

ll sum(ll start, ll end, ll node, ll left, ll right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	ll mid = (start + end) >> 1;
	return sum(start, mid, (node << 1), left, right) + sum(mid + 1, end, (node << 1) + 1, left, right);
}

void update(ll start, ll end, ll node, ll index, ll diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start == end) return;
	ll mid = (start + end) >> 1;
	update(start, mid, (node << 1), index, diff);
	update(mid + 1, end, (node << 1) + 1, index, diff);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M, tmp1, tmp2, tmp3, diff;
	cin >> N >> M;

	for (ll i=0; i < M; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		if (tmp1 == 1) {
			tmp2--;
			diff = tmp3 - arr[tmp2];
			arr[tmp2] = tmp3;
			update(0, N - 1, 1, tmp2, diff);
		} else {
			if (tmp2 > tmp3) cout << sum(0, N - 1, 1, tmp3 - 1, tmp2 - 1) << "\n";
			else cout << sum(0, N - 1, 1, tmp2 - 1, tmp3 - 1) << "\n";
		}
	}
}