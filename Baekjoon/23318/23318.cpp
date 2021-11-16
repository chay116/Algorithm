#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

unsigned int board[21][21];
unsigned int prefix[21][21];
int row[21];
int n, m, r, s, tmp;
bool ending = false;
unsigned int answer;

void get_col(unsigned int target) {
	int presum, row_start, row_end, col_start = 0, col_pos = 0, problem = 0;
	for (int j=1; j <= m; j++) {
		for (int i=0; i < r; i++) {
			row_start = row[i]; row_end = row[i+1];
			presum = prefix[row_end][j] - prefix[row_start][j] - prefix[row_end][col_start] + prefix[row_start][col_start];
			// cout << presum << " " << row_end << " " <<  row_start << " " <<  j << " " <<  col_start << endl;
			if (presum > target) {
				if (col_start == j - 1) return;
				problem = 1;
				break;
			}
		}
		if (problem) {
			j--;
			col_start = j;
			col_pos++;
			problem = 0;
		}
	}
	if (presum > target) col_pos++;
	if (col_pos >= s) return ;
	ending = true;
	return ;
}

void get_row(int pos, int division, unsigned int target) {
	if (ending) return ;
	if (division == r) {
		get_col(target);
		return ;
	}
	if (pos == n) return ;
	row[division] = pos;
	get_row(pos + 1, division + 1, target);
	get_row(pos + 1, division, target);
}


int main() {
	fastio;
	unsigned int target;
	unsigned int high;
	unsigned int low;
	cin >> n >> m >> r >> s; r++; s++; row[r] = n;
	for (int i=1; i <= n; i++)
		for (int j=1; j <= m; j++) {
			cin >> tmp; board[i][j] = tmp;
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + board[i][j];
		}
	high = prefix[n][m]; low = high / (r * s) - 1; int top = 0; answer = high;
	while (1) {
		ending = false;
		target = (high + low) / 2;
		get_row(1, 1, target);
		if (ending) {
			high = target;
			answer = min(answer, high);
			top = 1;
		}
		else {
			low = target;
			top = 0;
		}
		if (low + 1 == high) break;
	}
	ending = false;
	if (top) target = low;
	else target = high;
	get_row(1, 1, target);
	if (ending) answer = min(target, answer);
	cout << answer << endl;
}
