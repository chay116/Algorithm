#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
vector<int> fence;

int solving(int start, int end) {
	if (end - start == 2) return max(max(fence[start], fence[start + 1]), min(fence[start], fence[start + 1]) * 2);
	else if (end - start == 1) return fence[start];
	int divide = (end - start) / 2;
	int answer = max(solving(start, start + divide), solving(start + divide, end));
	int j=1, k=1;
	for (int i=min(fence[start + divide - 1], fence[start + divide]); i > 0; i--) {
		for (; j <= divide - 1; j++) if (fence[start + divide - 1 - j] < i) break;
		for (; k <= (end - start - 1) / 2; k++) if (fence[start + divide + k] < i) break;
		answer = max(answer, (j + k) * i);
		if (j + k > end - start) break;
	}
	return answer;
}

int main() {
	fastio;
	int C; cin >> C;

	while (C--) {
		int tmp, N; cin >> N;
		for (int i=0; i < N; i++) {
			cin >> tmp;
			fence.push_back(tmp);
		}
		cout << solving(0, fence.size()) << endl;
		fence.clear();
	}
}