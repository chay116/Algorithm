#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int n, k, tmp, adding;

int main() {
	fastio;
	cin >> n >> k;
	vector<int> arr1(10001, 0);
	vector<int> arr2(10001, 0);
	arr1[0] = 1;
	for (int i=0; i < n; i++) {
		cin >> tmp;
		arr2 = arr1;
		adding = tmp;
		while (adding <= k) {
			for (int j=0; j <= k - adding; j++)
				arr2[j + adding] += arr1[j];
			adding += tmp;
		}
		swap(arr1, arr2);
	}
	cout << arr1[k] << endl;
}

