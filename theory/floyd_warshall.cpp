#include <iostream>
using namespace std;

#define INF 1e9 // 무한을 의미하는 값으로 10억 설정
#define MAX 101 // 노드의 개수 최대 100개라고 가정

int n, m; // 노드 개수 n, 간선 개수 m

// 두 노드 사이의 비용을 저장하는 2차원 배열
int graph[MAX][MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    // 최단 거리 테이블 초기화
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    // A에서 B로 가는 비용은 C라고 설정
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        // 동일한 간선이 또 입력될 경우, 비용이 더 작은 값으로 초기화!!!
        if (graph[a][b] > c)
            graph[a][b] = c;
    }

    // 점화식에 따라 플로이드 워셜 알고리즘 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                // 자기 자신에서 자기 자신으로 가는 경로는 제외
                if (a == b) continue;
                // 경유하는 k번 노드는 출발, 도착 노드에서 제외
                if (k == a || k == b) continue;

                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    // 수행된 결과를 출력
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF)
                cout << 0 << ' '; // 도달할 수 없는 경우
            else
                cout << graph[a][b] << ' ';
        }
        cout << '\n';
    }
}