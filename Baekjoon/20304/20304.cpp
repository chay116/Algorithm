#include <vector>
#include <iostream>

#include <queue>
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int arr[100001];
int N, M, min0, min1, x_time;
unsigned int answer;
struct s_txy {
	int time;
	int x;
	int ans;
	s_txy(int _t, int _x) : time(_t), x(_x) {};
};
struct cmp {
	bool operator()(const s_txy &u, const s_txy &v) {
		return u.time > v.time;
	}
};
priority_queue<s_txy, vector<s_txy>, cmp> pq;

int Bitdiff(int v, int w){
	int cnt = x_time;
	int ans = 0;
	while (cnt--) {
		if ((v & 1) != (w & 1)) ans++;
		v >>= 1;
		w >>= 1;
	}
	return ans;
}

int main() {
	fastio;
	cin >> N >> M;
	for (int i=0; i < M; i++) {
		cin >> arr[i];
	}
	int min_value = 1;
	int answer = 0;
	while (min_value <= N) {
		min_value <<= 1;
		x_time++;
	}

	pq.push({1, 0});
	pq.push({1, 1});
	while (!pq.empty()) {
		int x = pq.top().x;
		int s_time = pq.top().time;
		pq.pop();
		if (s_time >= x_time) {
			int local_answer = x_time;
			for (int i=0; i < M; i++) {
				local_answer = min(local_answer, Bitdiff(x, arr[i]));
			}
			answer = max(answer, local_answer);
			continue ;
		}
		min0 = 0;
		min1 = 0;
		int plus1 = x + (1 << s_time);
		// cout << "time : " << s_time << " x : " << x << " " << plus1 << endl;
		for (int i=0; i < M; i++) {
			min0 = min(min0, Bitdiff(x, arr[i]));
			min1 = min(min1, Bitdiff(plus1, arr[i]));
		}
		if (min0 > min1) pq.push({s_time + 1, x});
		else if (min0 < min1) pq.push({s_time + 1, plus1});
		else {
			pq.push({s_time + 1, x});
			pq.push({s_time + 1, plus1});
		}
	}
	cout << answer << endl;
}
