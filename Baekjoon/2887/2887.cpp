#include <vector>
#include <iostream>
#include <queue>

// #include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
struct Point {
	long long idx1;
	long long idx2;
	long long value;
	Point() : idx1(0), idx2(0), value(0) {};
	Point(long long _idx1, long long _value) : idx1(_idx1), idx2(0), value(_value) {};
	Point(long long _idx1, long long _idx2, long long _value) : idx1(_idx1), idx2(_idx2), value(_value) {};
	long long operator-(const Point& ref) {
		return abs(ref.value - value);
	}
	long long operator<(const Point& ref) const {
		return value > ref.value;
	}
};

priority_queue<Point> pointXs;
priority_queue<Point> pointYs;
priority_queue<Point> pointZs;
priority_queue<Point> pointTotals;
long long parents[100'001];
long long num[100'001];
long long N;
long long total;

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
	long long tmp1, tmp2, tmp3;
	cin >> N;

	for (long long i=0; i < N; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		pointXs.emplace(i, tmp1);
		pointYs.emplace(i, tmp2);
		pointZs.emplace(i, tmp3);
		num[i] = 1;
		parents[i] = i;
	}
	Point prev, cur;
	prev = pointXs.top(); pointXs.pop();
	while (!pointXs.empty()) {
		cur = pointXs.top(); pointXs.pop();
		pointTotals.emplace(prev.idx1, cur.idx1, cur.value - prev.value);
		prev = cur;
	}
	prev = pointYs.top(); pointYs.pop();
	while (!pointYs.empty()) {
		cur = pointYs.top(); pointYs.pop();
		pointTotals.emplace(prev.idx1, cur.idx1, cur.value - prev.value);
		prev = cur;
	}
	prev = pointZs.top(); pointZs.pop();
	while (!pointZs.empty()) {
		cur = pointZs.top(); pointZs.pop();
		pointTotals.emplace(prev.idx1, cur.idx1, cur.value - prev.value);
		prev = cur;
	}

	while (!pointTotals.empty()) {
		cur = pointTotals.top(); pointTotals.pop();
		if (!UnionFind(cur.idx1, cur.idx2)) {
			isUnion(cur.idx1, cur.idx2); total += cur.value;
		}
	}
	cout << total << endl;
}