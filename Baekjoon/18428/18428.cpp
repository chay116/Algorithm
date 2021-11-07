#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int dx[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int check = 0;
int N;
vector<int> teacher;

void checking(vector<vector<char> > &board) {
	int tx, ty, result;
	for (auto tpos : teacher) {
		for (int i =0; i < 4; i++) {
			tx = tpos % N + dx[i][0];
			ty = tpos / N + dx[i][1];
			while (tx  >= 0 && tx < N && ty >= 0 && ty < N) {
				if (board[ty][tx] == 'S') return ;
				if (board[ty][tx] == 'O') break;
				tx = tx + dx[i][0];
				ty = ty + dx[i][1];
			}
		}
	}
	check = 1;
}

void set_objects(int pos, int set, vector<vector<char> > &board) {
	if (check == 1) return ;
	if (set == 3 || pos == N*N) {
		checking(board);
		return ;
	}

	int x = pos % N;
	int y = pos / N;
	if (board[y][x] != 'X') {
		set_objects(pos + 1, set, board);
		return;
	}

	set_objects(pos + 1, set, board);
	board[y][x] = 'O';
	set_objects(pos + 1, set + 1, board);
	board[y][x] = 'X';
	return ;
}

int main() {
	fastio;
	char m; cin >> N;
	vector<vector<char> > board(N, vector<char> (N,0));
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			cin >> m;
			board[i][j] = m;
			if (m == 'T') teacher.push_back(i * N + j);
		}
	}
	set_objects(0, 0, board);
	if (check == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}
