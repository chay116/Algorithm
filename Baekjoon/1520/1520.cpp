#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
int board[501][501];
int visited[501][501];
struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {};
	bool operator<(const Point& ref) const { return board[x][y] < board[ref.x][ref.y]; };
};

int main() {
	cin >> N >> M;
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) cin >> board[i][j];
	priority_queue<Point> pq;
	pq.push({0, 0});
	visited[0][0] = 1;
	while(!pq.empty()) {
		Point now = pq.top(); pq.pop();
		for (auto [dx, dy] : dxy) {
			int nx = dx + now.x; int ny = dy + now.y;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] >= board[now.x][now.y]) continue;
			if (!visited[nx][ny]) pq.push({nx, ny});
			visited[nx][ny] += visited[now.x][now.y];
		}
	}
	cout << visited[N-1][M-1] << endl;
}

