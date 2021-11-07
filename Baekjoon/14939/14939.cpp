#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int answer = -1;
vector<string> board;
int dxy[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void click(int y, int x) {
	int nx, ny;
	for (int i=0; i<5; i++) {
		ny = y + dxy[i][1]; nx = x + dxy[i][0];
		if (nx < 10 && nx >=0 && ny < 10 && ny >=0) {
			if (board[ny][nx] == '#') board[ny][nx] = 'O';
			else board[ny][nx] = '#';
		}
	}
}

void DFS(int pos, int num_click) {
	if (pos < 10) {
		DFS(pos + 1, num_click);
		click(pos / 10, pos%10);
		DFS(pos + 1, num_click + 1);
		click(pos / 10, pos%10);
	} else if (pos < 100) {
		if (board[(pos / 10) - 1][pos%10] == 'O') {
			click(pos / 10, pos % 10);
			DFS(pos + 1, num_click + 1);
			click(pos / 10, pos % 10);
		} else DFS(pos + 1, num_click);
	}
	else {
		for (int i=0; i < 10; i++) {
			if (board[9][i] == 'O') return;
		}
		if (answer == -1 || answer > num_click) answer = num_click;
	}
}

int main() {
	fastio;
	string tmp;
	for (int j=0; j < 10; j++) {
		cin >> tmp; board.push_back(tmp);
	}
	DFS(0, 0); cout << answer << endl;
}
