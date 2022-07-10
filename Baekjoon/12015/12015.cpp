#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
	int N, tmp;
	cin >> N;
	vector<int> line;
	for (int i=0; i < N; i++) {
		cin >> tmp;
		auto iter = lower_bound(line.begin(), line.end(), tmp);
		if (iter == line.end()) line.push_back(tmp);
		else *iter = tmp;
	}
	cout << line.size() << endl;
}