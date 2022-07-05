#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
	int start;
	int end;
	int cost;
	Edge() : start(0), end(0), cost(0) {
	}
	Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {
	}
	bool operator < (const Edge &edge) const {
		return cost > edge.cost;
	}
};

vector<pair<int,int>> a[1001];
bool c[1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		a[start].push_back(make_pair(end,cost));
		a[end].push_back(make_pair(start,cost));
	}
	c[1] = true;
	priority_queue<Edge> q;
	// 시작 노드를 1로 하고 q 에 1 과 연결된 노드들을 넣어줌
	for (int i=0; i<a[1].size(); i++) {
		q.push(Edge(1, a[1][i].first, a[1][i].second));
	}
	int ans = 0;
	for (int i=0; i<n-1; i++) {
		Edge e;
		// 우선순위 큐이기 때문에 top 의 값은 가장 작은 값
		while (!q.empty()) {
			e = q.top();
			q.pop();
			if (c[e.end] == false) {
				break;
			}
		}
		c[e.end] = true;
		ans += e.cost;
		int x = e.end;
		for (int i=0; i<a[x].size(); i++) {
			q.push(Edge(x, a[x][i].first, a[x][i].second));
		}
	}
	cout << ans << "\n";
	return 0;
}
