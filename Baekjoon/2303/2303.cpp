#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int m, result;
int answer = 0;
int max_num = -1;
int check = 0;
int check2 = 0;

void max_from_cards(int pos, vector<int> cards, vector<int> used) {
	if (pos == 5) {
		if (check == 3 && max_num <= result % 10) {
			max_num = result % 10;
			check2 = 1;
		}
		return ;
	}

	max_from_cards(pos + 1, cards, used);
	used[pos] = 1;
	result += cards[pos];
	check++;
	max_from_cards(pos + 1, cards, used);
	used[pos] = 0;
	result -= cards[pos];
	check--;
	return ;
}


int main() {
	fastio;
	int N; cin >> N;
	result = 0;
	vector<int> used(5, 0);
	vector<int> cards(5, 0);
	for (int j=1; j < N + 1; j++) {
		for (int i=0; i < 5; i++) {
			cin >> m;
			cards[i] = m;
		}
		max_from_cards(0, cards, used);
		if (check2) {
			answer = j;
			check2 = 0;
		}
	}
	cout << answer << endl;
}