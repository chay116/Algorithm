#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 각 정점의 부모 노드 번호를 저장하는 배열 (최종적으로는 루트 노드 번호)
int parent[10'000];

// 루트 노드를 찾는 Find 연산
int Find(int x) {
	// 배열의 인덱스와 값이 같다면 루트 노드 발견!
	if (x == parent[x]) return x;

	// 부모 노드의 번호를 전달하면서, 루트 노드를 찾을 때까지 재귀 호출 반복
	return parent[x] = Find(parent[x]);
}

// 두 노드를 같은 집합으로 합치는 Union 연산
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	// 루트 노드가 같다면 이미 연결되어 있는 것
	if (x == y) return;

	// 더 작은 값이 부모 노드가 될 수 있도록
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// 두 노드가 연결되어 있는지 판별하는 함수
bool isUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	// 루트 노드가 같은지 확인
	return (x == y);
}

// 하나의 간선 정보를 담는 클래스
class Edge {
public:
	int node[2];
	int weight;

	Edge(int x, int y, int w) {
		this->node[0] = x;
		this->node[1] = y;
		this->weight = w;
	}

	// 가중치가 작은 간선부터 MST에 추가하도록
	bool operator < (Edge& edge) {
		return this->weight < edge.weight;
	}
};

int main() {
	int V; // 정점 개수
	scanf("%d", &V);

	int E; // 간선 개수
	scanf("%d", &E);

	int x, y, w; // 하나의 간선을 이루는 두 정점의 번호와 가중치
	vector<Edge> v;

	for (int i = 0; i < E; i++){
		scanf("%d %d %d", &x, &y, &w);
		v.push_back(Edge(x, y, w)); // 객체 배열 생성
	}

	// 간선의 가중치를 기준으로 오름차순 정렬
	sort(v.begin(), v.end());

	// 각 정점의 번호 초기화
	for (int i = 0; i < V; i++){
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++){
		// 사이클이 발생하지 않을 때만 MST에 추가
		if (!isUnion(v[i].node[0], v[i].node[1])) {
			sum += v[i].weight;
			Union(v[i].node[0], v[i].node[1]);
		}
	}

	printf("%d\n", sum);

	return 0;
}