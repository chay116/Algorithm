#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
string quadmap;

int quad(int start) {
	cout << quadmap[start];
	if (quadmap[start] != 'x') return 1;

	int i = 1;
	int front = 2;
	while (front--) {
		if (quadmap[start + i] == 'x') front += 4;
		i++;
	}

	i += quad(start + i);
	i += quad(start + i);
	start++;
	start += quad(start);
	start += quad(start);
	return (i);
}

int main() {
	fastio;
	int C; cin >> C;

	while (C--) {
		string answer;
		cin >> quadmap;
		quad(0);
		cout << endl;
	}
}