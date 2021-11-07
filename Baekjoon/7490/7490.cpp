#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void check(int pos, int previous, int result, vector<int> cards, char *sentence) {
	if (pos == cards.size() - 1) {
		if (result == 0) cout << sentence << "\n";
		return ;
	}

	sentence[2*pos + 1] = ' ';
	if (previous < 0) check(pos + 1, previous * 10 - cards[pos + 1], result + previous * 9 - cards[pos + 1], cards, sentence);
	else check(pos + 1, previous * 10 + cards[pos + 1], result + previous * 9 + cards[pos + 1], cards, sentence);
	sentence[2*pos + 1] = '+';
	check(pos + 1, cards[pos + 1], result + cards[pos + 1], cards, sentence);
	sentence[2*pos + 1] = '-';
	check(pos + 1, -cards[pos + 1], result - cards[pos + 1], cards, sentence);
	return ;
}


int main() {
	fastio;
	int N, C; cin >> C;
	while (C--) {
		cin >> N;
		vector<int> nums;
		char sentence[2*N];
		sentence[2*N - 1] = 0;
		for (int i=1; i <= N; i++) {
			nums.push_back(i);
			sentence[2*(i - 1)] = 48 + i;
		}
		check(0, nums[0], nums[0], nums, sentence);
		if (C) cout << endl;
	}
}