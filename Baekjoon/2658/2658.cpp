#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<string> board;
vector<int> is_ver_line(10, 0);
vector<int> is_hor_line(10, 0);
vector<pair<int, int>> ver_line;
vector<pair<int, int>> hor_line;
vector<pair<int, int>> pos;

bool check_vertical(void) {
	int i=0;
	int j=9;
	int tmp;
	int max_line, diff;
	while (i < 10 && is_ver_line[i] == 0) i++;
	if (i == 10) return false;
	while (j >= 0 && is_ver_line[j] == 0) j--;
	cout << i << j << endl;
	if (i == j) return false;
	if (ver_line[j].second - ver_line[j].first == 0) {
		cout << i << endl;
		if ((max_line = ver_line[i].second - ver_line[i].first)%2 == 1) return false;
		if ((diff = max_line / (j - i))%2 == 1) return false;
		tmp = i;
		if (diff != 2 && diff != 1) return false;
		while (i != j) {
			i++;
			if ((ver_line[i-1].second - ver_line[i-1].first) - (ver_line[i].second - ver_line[i].first) != diff) return false;
		}
	} else if (ver_line[i].second - ver_line[i].first == 0){
		cout << i << endl;
		if ((max_line = ver_line[i].second - ver_line[i].first)%2 == 1) return false;
		if ((diff = max_line / (j - i))%2 == 1) return false;
		tmp = j;
		if (diff != 2 && diff != 1) return false;
		while (i != j) {
			j--;
			if ((ver_line[j+1].second - ver_line[j+1].first) - (ver_line[j].second - ver_line[j].first) != diff) return false;
		}
	} else return false;
	cout << "hello" << endl;
	pos.push_back(make_pair(ver_line[tmp].first, tmp));
	pos.push_back(make_pair(ver_line[tmp].second, tmp));
	pos.push_back(make_pair(ver_line[j].first, j));
	return true;
}

bool check_horizontal(void) {
	int i=0;
	int j=9;
	int tmp;
	int max_line, diff;
	while (i < 10 && is_hor_line[i] == 0) i++;
	if (i == 10) return false;
	while (j >= 0 && is_hor_line[j] == 0) j--;
	if (i == j) return false;
	if (hor_line[j].second - hor_line[j].first == 0) {
		if ((max_line = hor_line[i].second - hor_line[i].first)%2 == 1) return false;
		if ((diff = max_line / (j - i))%2 == 1) return false;
		tmp = i;
		if (diff != 2 && diff != 1) return false;
		while (i != j) {
			i++;
			if ((hor_line[i-1].second - hor_line[i-1].first) - (hor_line[i].second - hor_line[i].first) != diff) return false;
		}
	} else if (hor_line[i].second - hor_line[i].first == 0){
		if ((max_line = hor_line[i].second - hor_line[i].first)%2 == 1) return false;
		if ((diff = max_line / (j - i))%2 == 1) return false;
		tmp = j;
		if (diff != 2 && diff != 1) return false;
		while (i != j) {
			j--;
			if ((hor_line[j+1].second - hor_line[j+1].first) - (hor_line[j].second - hor_line[j].first) != diff) return false;
		}
	} else return false;
	pos.push_back(make_pair(hor_line[tmp].first, tmp));
	pos.push_back(make_pair(hor_line[tmp].second, tmp));
	pos.push_back(make_pair(hor_line[j].first, j));
	return true;
}

int main() {
	string tmp; int start, end;
	fastio;
	for (int i=0; i < 10; i++) {
		cin >> tmp;
		board.push_back(tmp);
		int j=0;
		while (j < 10) {
			if (tmp[j] == '1') {
				if (is_hor_line[j] == 1) {
					cout << "0" << endl; return 0;
				}
				start = j; is_hor_line[j] = 1;
				while(j < 10 && tmp[j+1] == '1') j++;
				end = j; hor_line.push_back(make_pair(start, end));
			} else j++;
		}
		if (is_hor_line[j] == 0) hor_line.push_back(make_pair(-1, -1));
	}
	for (int i=0; i < 10; i++) {
		int j=0;
		while (j < 10) {
			if (board[j][i] == '1') {
				if (is_ver_line[j] == 1) {
					cout << "0" << endl; return 0;
				}
				start = j; is_ver_line[j] = 1;
				while(j < 10 && board[j+1][i] == '1) j++;
				end = j; ver_line.push_back(make_pair(start, end));
			} else j++;
		}
		if (is_ver_line[j] == 0) ver_line.push_back(make_pair(-1, -1));
	}
	if (check_vertical() || check_horizontal()) {
		sort(pos.begin(), pos.end());
		cout << pos[0].first << " " << pos[0].second << endl;
		cout << pos[1].first << " " << pos[1].second << endl;
		cout << pos[2].first << " " << pos[2].second << endl;
	} else cout << "0" << endl;
}
