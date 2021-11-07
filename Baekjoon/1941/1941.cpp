#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int answer = 0;
vector<string> board;
vector<int> pool;
vector<vector<int> > connect(25, vector<int>(25, 0));

void make_connect(void)
{
	for (int i = 0; i < 25; i++)
	{
		if (i%5 != 4) {
			connect[i][i+1] = 1;
			connect[i+1][i] = 1;
		}
		if (i < 20) {
			connect[i][i+5] = 1;
			connect[i+5][i] = 1;
		}
	}
}

void is_connect()
{
	int cnt = 0;
	int done[7] = {0, };
	queue<int> q;

	q.push(pool[0]);
	done[0] = 1;
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		cnt++;
		for (int i = 1; i < pool.size(); i++)
		{
			if (done[i] == 0 && connect[now][pool[i]] == 1)
			{
				q.push(pool[i]);
				done[i] = 1;
			}
		}
	}
	if (cnt == 7) answer++;
}

void DFS(int pos, int num) {
	if (pool.size() == 7) {
		if (num >= 4) is_connect();
		return ;
	}
	if (pos >= 25) return;
	pool.push_back(pos);
	if (board[pos / 5][pos % 5] == 'Y') DFS(pos + 1, num);
	else DFS(pos + 1, num + 1);
	pool.pop_back();
	DFS(pos + 1, num);
}

int main() {
	fastio;
	string tmp;
	make_connect();
	for (int j=0; j < 5; j++) {
		cin >> tmp; board.push_back(tmp);
	}
	DFS(0, 0); cout << answer << endl;
}

//// 빠르게 bitmask로 푸는 방법.

// #include <iostream>
// #include <algorithm>
// #include <map>
// using namespace std;

// char arr[5][5];
// int ans, a[10];
// int dr[4] = { -1, 0, 1, 0 };
// int dc[4] = { 0, 1, 0, -1 };
// map<int, int> mp;

// bool isRange(int r, int c) {
// 	if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
// 	return true;
// }

// void sol(int tCnt, int sCnt, int bmsk) {
// 	if (mp.count(bmsk) > 0) return;
// 	mp[bmsk] = 1;

// 	if (7 - tCnt + sCnt < 4) return;

// 	if (tCnt == 7) {
// 		ans++;
// 		return;
// 	}

// 	for (int i = 0; i < tCnt; i++) {
// 		int r = a[i] / 5;
// 		int c = a[i] % 5;
// 		for (int k = 0; k < 4; k++) {
// 			int nr = r + dr[k];
// 			int nc = c + dc[k];
// 			if (!isRange(nr, nc)) continue;
// 			int next = nr * 5 + nc;
// 			a[tCnt] = next;
// 			if (arr[nr][nc] == 'S') sol(tCnt + 1, sCnt + 1, bmsk | 1 << next);
// 			else sol(tCnt + 1, sCnt, bmsk | 1 << next);
// 		}
// 	}
// }


// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	for (int i = 0; i < 5; i++) {
// 		for (int j = 0; j < 5; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}

// 	for (int i = 0; i < 25; i++) {
// 		a[0] = i;
// 		if(arr[i / 5][i % 5] == 'S') sol(1, 1, 1 << i);
// 		else sol(1, 0, 1 << i);
// 	}

// 	cout << ans << '\n';

// 	return 0;
// }