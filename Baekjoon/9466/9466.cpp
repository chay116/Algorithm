#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int T, N;
int favor[100'001];
int parents[100'001];

int findParents(int i) {
	if (parents[i] == i) return i;
	else return parents[i] = findParents(parents[i]);
}

void UnionFind(int x, int y) {
	x = findParents(x); y = findParents(y);
	parents[x] = y;
}

bool isUnion(int x, int y) {
	x = findParents(x); y = findParents(y);
	return (x == y);
}

int main() {
	fastio;
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N;
		for (int i=1; i <= N; i++) {
			cin >> favor[i]; parents[i] = i;
		};
		for (int i=1; i <= N; i++) {
			if (parents[i] == -1) continue;
			int tmp = i;
			vector<int> q;
			q.push_back(tmp);
			while (parents[favor[tmp]] != -1 && !isUnion(tmp, favor[tmp])) {
				UnionFind(tmp, favor[tmp]);
				tmp = favor[tmp];
				q.push_back(tmp);
			}
			tmp = favor[tmp];
			int j = 0;
			while (j < q.size() && q[j] != tmp) {
				parents[q[j]] = -1;
				j++;
				ans++;
			};
			for (; j< q.size(); j++) {
				parents[q[j]] = -1;
			};
		};
		cout << ans << endl;
	}

}