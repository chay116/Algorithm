#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, tmp;
int ans[1'000'001];

int main() {
	fastio;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++)
		cin >> ans[i];
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= ans[i])
			s.pop();
		if (s.empty()) tmp = -1;
		else tmp = s.top();
		s.push(ans[i]);
		ans[i] = tmp;
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}
