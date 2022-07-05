#include <iostream>
#include <vector>
#define INF 1e9 // 무한을 의미하는 값으로 10억 설정
using namespace std;

// 노드 개수: n, 간선 개수: m, 시작 노드 번호: start
int n, m, start;

// 노드 개수는 최대 100,000개라고 가정
// pair: 인접 노드 번호, 가중치
vector<pair<int, int>> graph[100'001];

bool visited[100'001]; // 방문한 적이 있는지 체크
int d[100'001]; // 최단 거리 테이블

// 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드의 번호 리턴
int getSmallestNode() {
	int min = INF;
	int idx = 0;

	for (int i = 0; i <= n; i++){
		if ((d[i] < min) && !visited[i]) {
			min = d[i];
			idx = i;
		}
	}

	return idx;
}

// 다익스트라 알고리즘
void dijkstra(int start) {
	// 시작 노드에 대한 초기화
	d[start] = 0;
	visited[start] = true;

	// 시작 노드의 인접 노드들은
	// 시작 노드까지의 거리로 테이블 초기화
	for (int j = 0; j < graph[start].size(); j++){
		d[graph[start][j].first] = graph[start][j].second;
	}

	// 시작 노드를 제외한 전체 n-1 개의 노드에 대해 반복
	for (int i = 0; i < n - 1; i++){
		// 현재 최단 거리가 가장 짧은 노드를 선택해서 방문 처리
		int now = getSmallestNode();
		visited[now] = true;

		// 현재 노드와 연결된 다른 노드 확인
		for (int j = 0; j < graph[now].size(); j++){
			int cost = d[now] + graph[now][j].second;

			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main() {
	// 노드 개수, 간선 개수, 시작 노드의 번호
	cin >> n >> m >> start;

	// 모든 간선 정보 입력 받기
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;

		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b, c });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill_n(d, 100'001, INF);

	// 다익스트라 알고리즘 수행
	dijkstra(start);

	// 시작 노드에서 다른 모든 노드로 가는 최단 거리 출력
	for (int i = 1; i <= n; i++){
		if (d[i] == INF) // 도달할 수 없는 경우
			cout << "INF" << '\n';
		else // 도달할 수 있는 경우 거리 출력
			cout << d[i] << '\n';
	}

	return 0;
}