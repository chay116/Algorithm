#include <iostream>
#include <map>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
#define MAX_WEIGHT 1000001

vector<vector<int>> jewerly(MAX_WEIGHT + 1, vector<int>(1,0));
vector<int> cost(MAX_WEIGHT + 1, 0);
priority_queue<int, vector<int>, less<int>> values;
int N, K, M, V;
unsigned long long answer = 0;

int main() {
	fastio;
	cin >> N >> K;
	for (int i=0; i < N; i++) {
		cin >> M >> V;
		jewerly[M].push_back(V);
	}
	for (int i=0; i < K; i++) {
		cin >> M;
		if (M >= MAX_WEIGHT)
			M = MAX_WEIGHT - 1;
		cost.at(M) += 1;
	}
	for (int i=0; i < MAX_WEIGHT; i++) {
		for (int value : jewerly.at(i))
			values.push(value);
		for (int j=0; j < cost.at(i); j++) {
			if (!values.empty()) {
				answer += values.top();
				values.pop();
			}
		}
	}
	cout << answer << endl;
}
