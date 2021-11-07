#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M, nG, nR;
int answer = 0;
vector<int> available;
vector<int> RED;
vector<int> GREEN;
int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(vector<vector<int> > &board) {
	vector<vector<int> > map(board);
	vector<int> bfs_g = GREEN;
	vector<int> bfs_r = RED;
	vector<int> next_g;
	vector<int> next_r;
	int end = 0;
	int num_g = 5, num_r = 6;
	int x, y, nx, ny, i;
	int result = 0;
	while (!end) {
		end = 1;
		for (auto g : bfs_g) {
			x = g % M; y = g / M;
			if (map[y][x] != -1) {
				for (i=0; i<4; i++) {
					nx = x + dxy[i][0]; ny = y + dxy[i][1];
					if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
						(map[ny][nx] == 1 || map[ny][nx] == 2)) {
						map[ny][nx] = num_g;
						next_g.push_back(ny * M + nx);
						end = 0;
					}
				}
			}
		}
		for (auto r : bfs_r) {
			x = r % M; y = r / M;
			for (i=0; i<4; i++) {
				nx = x + dxy[i][0]; ny = y + dxy[i][1];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
					(map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == num_g)) {
					if (map[ny][nx] == num_g) {
						map[ny][nx] = -1;
						result++;
					} else {
						map[ny][nx] = num_r;
						next_r.push_back(ny * M + nx);
					}
					end = 0;
				}
			}
		}
		bfs_g = next_g;
		bfs_r = next_r;
		next_g.clear();
		next_r.clear();
		num_g += 2; num_r += 2;
	}
	if (answer < result) answer = result;
}

void DFS(int pos, int G, int R, vector<vector<int> > &board) {
	if (G == 0 && R == 0) {
		BFS(board);
		return ;
	}
	if (available.size() == pos) return;
	int x = available[pos] % M, y = available[pos] / M;
	// 3 == G, 4 == R
	if (G != 0) {
		board[y][x] = 3;
		GREEN.push_back(available[pos]);
		DFS(pos + 1, G - 1, R, board);
		GREEN.pop_back();
	}
	if (R != 0) {
		board[y][x] = 4;
		RED.push_back(available[pos]);
		DFS(pos + 1, G, R - 1, board);
		RED.pop_back();
	}
	board[y][x] = 2;
	DFS(pos + 1, G, R, board);
	return ;
}


int main() {
	fastio;
	int m;
	cin >> N >> M >> nG >> nR;
	vector<vector<int> > board(N, vector<int>(M, 0));
	for (int j=0; j < N ; j++) {
		for (int i=0; i < M; i++) {
			cin >> m;
			board[j][i] = m;
			if (m == 2) available.push_back(j * M + i);
		}
	}
	DFS(0, nG, nR, board);
	cout << answer << endl;
}