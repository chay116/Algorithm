#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;

// 노드 개수: n, 간선 개수: m, 시작 노드 번호: start
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
// (인접 노드 번호, 가중치)
vector<pair<int, int>> graph[100'001];

// 최단 거리 테이블 만들기
int d[100'001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    // 기본적으로 최대 힙이기 때문에
    // 거리가 가장 짧은 노드부터 먼저 꺼내는 '최소 힙'으로 구현하려면
    // 원소를 삽입, 삭제할 때 마이너스 부호를 붙여줘야 한다.

    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    // (거리, 노드 번호)
    pq.push({ 0, start });
    d[start] = 0;

    while (!pq.empty()) {
        // 최단 거리가 가장 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 시작 노드에서 현재 노드까지의 거리
        int now = pq.top().second; // 현재 노드 번호
        pq.pop();

        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (dist > d[now]) continue;

        // 현재 노드와 연결된 다른 인접 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second;

            // 현재 노드들을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }

}

int main(void) {
    // 노드 개수, 간선 개수, 시작 노드 번호
    cin >> n >> m >> start;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({ b, c });
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 100'001, INF);

    // 다익스트라 알고리즘을 수행
    dijkstra(start);

    // 시작 노드에서 다른 모든 노드로 가는 최단 거리 출력
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) // 도달할 수 없는 경우
            cout << "INF" << '\n';
        else // 도달할 수 있는 경우 거리 출력
            cout << d[i] << '\n';
    }

    return 0;
}