#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int H, W;
int answer;

int block[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

void solving(int pos, vector<vector<int> > board) {
	int x = pos / W;
	int y = pos % W;
	if (pos == H * W - 1) {
		if (board[x][y]) answer++;
		return ;
	}
	if (board[x][y] == 1) solving(pos + 1, board);
	else {
		board[x][y] = 1;
		for (int i=0; i < 4; i++) {
			if (x + block[i][1][0] >=0 && x + block[i][1][0] < H &&
				x + block[i][2][0] >=0 && x + block[i][2][0] < H &&
				y + block[i][1][1] >=0 && y + block[i][1][1] < W &&
				y + block[i][2][1] >=0 && y + block[i][2][1] < W &&
				board[x + block[i][1][0]][y + block[i][1][1]] == 0 &&
				board[x + block[i][2][0]][y + block[i][2][1]] == 0) {
					board[x + block[i][1][0]][y + block[i][1][1]] = 1;
					board[x + block[i][2][0]][y + block[i][2][1]] = 1;
					solving(pos + 1, board);
					board[x + block[i][1][0]][y + block[i][1][1]] = 0;
					board[x + block[i][2][0]][y + block[i][2][1]] = 0;
			}
		}
		board[x][y] = 0;
	}
}

int main() {
	fastio;
	int C; cin >> C;

	while (C--) {
		cin >> H >> W;
		vector<vector<int> > board(H,vector<int>(W,0));
		string tmp;
		answer = 0;
		for (int i=0; i < H; i++) {
			cin >> tmp;
			for(int j=0;j<tmp.size();j++){
				if(tmp[j] == '#') board[i][j] = 1;
				else board[i][j] = 0;
			}
		}
		solving(0, board);
		cout << answer << endl;
	}
}