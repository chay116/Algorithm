#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long arr[1000001];
int pos[1000001];
vector<long long > value;
vector<long long> answer;

int main() {
	fastio;
	size_t index;
	int tmp, N, cnt = 0; cin >> N; cin >> tmp;
	arr[0] = tmp; value.push_back(tmp);
	for (int k = 1; k < N; k++) {
		cin >> tmp; arr[k] = tmp;
		if (value[cnt] < tmp) {
			value.push_back(tmp); cnt++;
			pos[k] = cnt;
		} else {
			index = lower_bound(value.begin(), value.end(), tmp) - value.begin();
			value[index] = arr[k];
			pos[k] = index;
		}
	}
	cout << cnt + 1 << endl;
	for (int i=N-1; i >= 0 && cnt >=0; i--) {
		if (pos[i] == cnt) {
			answer.push_back(arr[i]);
			cnt--;
		}
	}
	for (int i=answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	cout << endl;
}
