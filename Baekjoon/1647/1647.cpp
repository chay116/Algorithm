#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int parents[100'001];
int num[100'001];
int N, M;
struct Path {
	int a;
	int b;
	int value;
	Path(int _a, int _b, int _value) : a(_a), b(_b), value(_value) {};
	bool operator<(const Path& ref) const {
		return value > ref.value;
	};
};

int FindParents(int a) {
	if (parents[a] == a) return a;
	return parents[a] = FindParents(parents[a]);
};

void isUnion(int a, int b) {
	a = FindParents(a);
	b = FindParents(b);

	if (a == b) return;

	// 더 작은 값이 부모 노드가 될 수 있도록
	num[b] += num[a];
	num[a] = num[b];
	if (a < b) {
		parents[b] = a;
	}
	else {
		parents[a] = b;
	}
}

bool UnionFind(int a, int b) {
	a = FindParents(a);
	b = FindParents(b);
	if (num[b] + num[a] >= N) return true;
	return (a == b);
}

int main() {
	fastio;
	int A, B, C;
	cin >> N >> M;
	priority_queue<Path> pq;

	for (int i=0; i <= N; i++) {
		parents[i] = i;
		num[i] = 1;
	}

	while (M--) {
		cin >> A >> B >> C;
		pq.emplace(A, B, C);
	}

	int ans = 0;

	while (!pq.empty()) {
		Path tmp = pq.top(); pq.pop();
		if (!UnionFind(tmp.a, tmp.b)) {
			ans += tmp.value;
			isUnion(tmp.a, tmp.b);
		}
	}

	cout << ans << endl;
}