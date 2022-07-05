#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
struct Point {
	long long x;
	long long y;
	Point() : x(0), y(0) {};
	Point(long long _x, long long _y) : x(_x), y(_y) {};
	Point operator-(const Point& ref) {
		return Point(ref.x - x, ref.y - y);
	}
	long long operator*(const Point& ref) {
		return ref.x * y - x * ref.y;
	}
};
Point lines[3001][2];
long long parents[3001];
long long num[3001];
long long visited[3001];
long long N;

long long CrossProduct(Point x, Point y, Point z) {
	return (x - y) * (x - z);
};

bool CCW(Point x1, Point x2, Point y1, Point y2) {
	long long result1 = CrossProduct(x1, x2, y1) * CrossProduct(x1, x2, y2);
	long long result2 = CrossProduct(y1, y2, x1) * CrossProduct(y1, y2, x2);
	if (result1 == 0 && result2 == 0) {
		if (x1.x != x2.x) {
			long long minx = min(x1.x, x2.x);
			long long miny = min(y1.x, y2.x);
			if (minx <= miny) {
				if (minx <= miny && miny <=  max(x1.x, x2.x)) return true;
			} else {
				if (miny <= minx && minx <=  max(y1.x, y2.x)) return true;
			}
		} else {
			long long minx = min(x1.y, x2.y);
			long long miny = min(y1.y, y2.y);
			if (minx <= miny) {
				if (minx <= miny && miny <=  max(x1.y, x2.y)) return true;
			} else {
				if (miny <= minx && minx <=  max(y1.y, y2.y)) return true;
			}
		}
		return false;
	} else if (result1 <= 0 && result2 <= 0) {
		return true;
	}
	return false;
}

long long FindParents(long long a) {
	if (parents[a] == a) return a;
	return parents[a] = FindParents(parents[a]);
};

void isUnion(long long a, long long b) {
	a = FindParents(a);
	b = FindParents(b);

	if (a == b) return;

	num[b] += num[a];
	num[a] = num[b];
	// 더 작은 값이 부모 노드가 될 수 있도록
	if (a < b) {
		parents[b] = a;
	}
	else {
		parents[a] = b;
	}
}

bool UnionFind(long long a, long long b) {
	a = FindParents(a);
	b = FindParents(b);
	return (a == b);
}

int main() {
	fastio;
	long long tmp1, tmp2, tmp3, tmp4;
	cin >> N;

	for (long long i=0; i < N; i++) {
		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
		lines[i][0].x = tmp1;
		lines[i][0].y = tmp2;
		lines[i][1].x = tmp3;
		lines[i][1].y = tmp4;
		num[i] = 1;
		parents[i] = i;
	}

	for (long long i= 0; i < N - 1; i++) {
		for (long long j= i + 1; j < N; j++) {
			if (CCW(lines[i][0], lines[i][1], lines[j][0], lines[j][1])) {
				isUnion(i, j);
			}
		}
	}

	long long group_num = 0;
	for (long long i=0; i < N; i++) {
		long long tmp = FindParents(i);
		if (visited[tmp] == 0) {
			group_num++; visited[tmp]++;
		}
	}
	cout << group_num << endl;
	cout << *max_element(num, num + N) << endl;
}