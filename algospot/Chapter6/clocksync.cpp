#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
int answer;
int touch;

vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

void solving(int pos, vector<int> clock) {
	if (answer != -1 && answer <= touch) return ;
	if (pos == 10) {
		for (int j = 0; j < 16; j++) {
			if (clock[j] % 4 != 0) return ;
		}
		if (answer == -1 || answer > touch) answer = touch;
		return ;
	}
	solving(pos + 1, clock);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < button[pos].size(); j++) clock[button[pos][j]] += 1;
		touch++;
		solving(pos + 1, clock);
	}
	for (int i = 0; i < button[pos].size(); i++) clock[button[pos][i]] -= 3;
	touch -= 3;
	return ;
}


int main() {
	fastio;
	int C; cin >> C;
	int m;

	while (C--) {
		answer = -1;
		touch = 0;
		vector<int> clock(16,0);
		for (int i=0; i < 16; i++) {
			cin >> m;
			clock[i] = m / 3;
		}
		solving(0, clock);
		cout << answer << endl;
	}
}