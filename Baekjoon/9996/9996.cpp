#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool check_head(string pattern, string file) {
	if (pattern.size() > file.size() + 1) return false;
	for (int i=0; i < pattern.size(); i++) {
		if (pattern[i] == '*') return true;
		if (pattern[i] != file[i]) return false;
	}
	return false;
}

bool check_back(string pattern, string file) {
	int m = pattern.size() - 1;
	int n = file.size() - 1;
	for (int i=0; i < pattern.size(); i++) {
		if (pattern[m - i] == '*') return true;
		if (pattern[m - i] != file[n - i]) return false;
	}
	return false;
}

int main() {
	fastio;
	int N; cin >> N;
	string pattern;
	string file;
	cin >> pattern;
	while (N--) {
		cin >> file;
		if (check_head(pattern, file) && check_back(pattern, file)) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
}