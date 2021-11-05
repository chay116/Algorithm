#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

int main() {
	fastio;
	int C; cin >> C;

	int H, W;
	while (C--) {
		cin >> H >> W;
		vector<vector<int> > board(H,vector<int>(W,0));
		string tmp;

		for(int i=0; i < H; i++) {
			cin >> tmp;
			for(int j=0;j<tmp.size();j++){
				if(tmp[j] == '#')
					board[i][j] = 1;
			}
		}
	}
}