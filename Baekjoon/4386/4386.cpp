#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;
int parents[101];
struct Point {
	float value;
	int i, j;
	Point(float v, int i, int j) : value(v), i(i), j(j) {};
	bool operator<(const Point& ref) const { return this->value > ref.value; };
};


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


pair<float, float> num1[101];
priority_queue<Point> pq;
int main() {
	fastio;
	cin >> N;
	for (int i=1; i <= N; i++) {
		parents[i] = i;
		cin >> num1[i].first >> num1[i].second;
		for (int j=1; j < i; j++) {
			float tmp = (num1[j].first - num1[i].first) * (num1[j].first - num1[i].first)
						+ (num1[j].second - num1[i].second) * (num1[j].second - num1[i].second);
			pq.push({tmp, i, j});
		}
	};

	float ans = 0;
	while (!pq.empty()) {
		Point tmp = pq.top(); pq.pop();
		if (!UnionFind(tmp.i, tmp.j)) {
			ans += sqrt(tmp.value);
			isUnion(tmp.i, tmp.j);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans << endl;
}

