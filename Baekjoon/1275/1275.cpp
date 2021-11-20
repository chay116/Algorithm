#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define ll long long
#define ARR_SIZE 100001
ll arr[ARR_SIZE];
ll tree[4 * ARR_SIZE];

ll init(ll start, ll end, ll node) {
	if (start == end) return tree[node] = arr[start];
	ll mid = (start + end) >> 1;
	return tree[node] = init(start, mid, (node << 1)) + init(mid + 1, end, (node << 1) + 1);
}

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
	fastio;
	ll N, M, tmp1, tmp2, tmp3, tmp4, diff;
	cin >> N >> M;

	for (ll i=0; i < N; i++) {
		cin >> tmp1; arr[i] = tmp1;
	}
	init(0, N-1, 1);
	for (ll i=0; i < M; i++) {
		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
		tmp1--; tmp2--; tmp3--;
		if (tmp1 > tmp2) cout << sum(0, N - 1, 1, tmp2, tmp1) << "\n";
		else cout << sum(0, N - 1, 1, tmp1, tmp2) << "\n";
		diff = tmp4 - arr[tmp3];
		arr[tmp3] = tmp4;
		update(0, N - 1, 1, tmp3, diff);
	}
}