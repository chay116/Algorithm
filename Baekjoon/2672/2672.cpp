#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct t{
	long long value;
	long long index;
	int type;

	bool operator<(const t &rhs) const {
		return value < rhs.value;
	}
} ver[60], hor[60];
bool ver_check[30];
bool hor_check[30];

long long ftoi(string str) {
	long long start = 0;
	long long dot = 0;
	for (long long i=0; i < str.size(); i++) {
		if (str[i] != '.') start = start * 10 + str[i] - '0';
		else dot = 1;
	}
	if (dot == 0) start = start * 10;
	return start;
}

int main() {
	fastio;
	long long N; cin >>N;
	string sx, sy, sw, sh;
	long long x, y, w, h;
	for (long long i=0; i < N; i++) {
		cin >> sx >> sy >> sw >> sh;
		x = ftoi(sx); y = ftoi(sy); w = ftoi(sw); h = ftoi(sh);
		ver[2 * i] = {x, i, 0};
		ver[2 * i + 1] = {x + w, i, 1};
		hor[2 * i] = {y, i, 0};
		hor[2 * i + 1] = {y + h, i, 1};
	}
	sort(ver, ver + 2 * N);
	sort(hor, hor + 2 * N);

	long long nx, ny, cnt;
	long long total = 0;
	ver_check[ver[0].index] = 1;
	for (long long i=1; i<2*N; i++) {
		nx = ver[i].value - ver[i-1].value;
		if (ver_check[hor[0].index] == 1) {
			hor_check[hor[0].index] = 1;
			cnt = 1;
		} else cnt = 0;
		for (long long j=1; j<2*N; j++) {
			ny = hor[j].value - hor[j-1].value;
			if (cnt) total += nx * ny;
			if (ver_check[hor[j].index] == 1) {
				if (hor[j].type) {
					hor_check[hor[j].index] = 0;
					cnt--;
				} else {
					hor_check[hor[j].index] = 1;
					cnt++;
				}
			}
		}
		ver_check[ver[i].index] = ver[i].type ? 0 : 1;
	}

	cout << total/100;
	if (total%100) {
		cout << ".";
		if (total%100 < 10) cout << "0";
		cout << total%100 << endl;
	} else cout << endl;
}
