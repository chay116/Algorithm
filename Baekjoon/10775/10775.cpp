#include <vector>
#include <iostream>
#include <queue>

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int G, P;
int ending = false;
int parents[100'001];

int findParents(int num) {
	if (parents[num] == num) return num;
	else return parents[num] = findParents(parents[num]);
}

int main() {
	fastio;
	cin >> G >> P;
	int tmp, ans = P;
	for (int i=1; i <= G; i++) {
		parents[i] = i;
	}
	for (int i=0; i < P; i++) {
		cin >> tmp;
		if (ending) continue ;
		if (findParents(parents[tmp]) == 0) {
			ending = true;
			ans = i;
		}
		else {
			parents[findParents(parents[tmp])]--;
		};
	}
	cout << ans << endl;
}
