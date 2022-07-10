#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct Matrix {
	int a;
	int b;
	int value;
	Matrix() : a(0), b(0), value(0) {};
	Matrix(int a, int b, int value) : a(a), b(b), value(value) {};
	Matrix operator*(const Matrix& ref) { return {a, ref.b, a * b * ref.b + value + ref.value}; };
};

Matrix board[501][501];
int N, num1, num2;
int main() {
	fastio;
	cin >> N;

	for (int i=0; i < N; i++) {
		cin >> board[i][i].a >> board[i][i].b;
		for (int j=i-1; j >= 0; --j) {
			for (int k=i-1; k >= j; --k) {
				// cout << i << " " << j << " " << k << " " << board[k][j].a * board[k][j].b * board[i][k + 1].b + board[i][k + 1].value << endl;
				if (board[i][j].value == 0 || board[i][j].value > board[k][j].a * board[k][j].b * board[i][k + 1].b + board[k][j].value + board[i][k + 1].value)
					board[i][j] = board[k][j] * board[i][k + 1];
			}
		}
	}

	// for (int i=0; i < N; i++) {
	// 	for (int j=0; j <= i; ++j) {
	// 		cout << board[i][j].value << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << board[N-1][0].value << endl;
}