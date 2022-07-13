#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;
int parents[500'001];

int FindParents(int a) {
	if (parents[a] == a) return a;
	return parents[a] = FindParents(parents[a]);
};

void isUnion(int a, int b) {
	a = FindParents(a);
	b = FindParents(b);

	if (a == b) return;

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
	return (a == b);
}


pair<int, int> num1[101];
int main() {
	fastio;
	cin >> N >> M;
	for (int i=1; i <= N; i++) {
		parents[i] = i;
	};

	int ans = 0;
	int tmp1, tmp2;
	for (int i=1; i <= M; i++) {
		cin >> tmp1 >> tmp2;
		if (ans) continue;
		if (UnionFind(tmp1, tmp2)) ans = i;
		else isUnion(tmp1, tmp2);
	};
	cout << ans << endl;
}

