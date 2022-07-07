#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
struct Point {
	float x;
	float y;
	Point() : x(0), y(0) {};
	Point(float _x, float _y) : x(_x), y(_y) {};
	Point operator-(const Point& ref) {
		return Point(ref.x - x, ref.y - y);
	}
	float operator*(const Point& ref) {
		return ref.x * y - x * ref.y;
	}
};

float CrossProduct(Point x, Point y, Point z) {
    return (x - y) * (x - z);
};

bool CCW(Point x1, Point x2, Point y1, Point y2) {
	float result1 = CrossProduct(x1, x2, y1) * CrossProduct(x1, x2, y2);
	float result2 = CrossProduct(y1, y2, x1) * CrossProduct(y1, y2, x2);
	if (result1 == 0 && result2 == 0) {
		if (x1.x != x2.x) {
			float minx = min(x1.x, x2.x);
			float miny = min(y1.x, y2.x);
			if (minx <= miny) {
				if (minx <= miny && miny <=  max(x1.x, x2.x)) return true;
			} else {
				if (miny <= minx && minx <=  max(y1.x, y2.x)) return true;
			}
		} else {
			float minx = min(x1.y, x2.y);
			float miny = min(y1.y, y2.y);
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

int main() {
	fastio;
	float tmp1, tmp2, tmp3, tmp4;
	Point x1, x2, y1, y2;
	cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
	x1.x = tmp1; x1.y = tmp2; x2.x = tmp3; x2.y = tmp4;
	cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
	y1.x = tmp1; y1.y = tmp2; y2.x = tmp3; y2.y = tmp4;

	if (CCW(x1, x2, y1, y2)) cout << 1 << endl;
	else cout << 0 << endl;
}