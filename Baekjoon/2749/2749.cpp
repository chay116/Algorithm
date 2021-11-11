#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long answer = 0;
struct matrix {
	long long x1;
	long long x2;
	long long x3;
	long long x4;
};

matrix multiply(matrix A, matrix B) {
	matrix C;
	C.x1 = ((A.x1 * B.x1) % 1000000 + (A.x2 * B.x3 % 1000000)) % 1000000;
	C.x2 = ((A.x1 * B.x2) % 1000000 + (A.x2 * B.x4 % 1000000)) % 1000000;
	C.x3 = ((A.x3 * B.x1) % 1000000 + (A.x4 * B.x3 % 1000000)) % 1000000;
	C.x4 = ((A.x3 * B.x2) % 1000000 + (A.x4 * B.x4 % 1000000)) % 1000000;
	return C;
}

matrix fibo(unsigned long long N) {
	matrix result, tmp;
	if (N == 0) {
		result.x1 = 0; result.x2 = 0; result.x3 = 0; result.x4 = 0;
		return result;
	}
	if (N == 1) {
		result.x1 = 1; result.x2 = 1; result.x3 = 1; result.x4 = 0;
		return result;
	} else if (N == 2) {
		result.x1 = 1; result.x2 = 1; result.x3 = 1; result.x4 = 0;
		tmp.x1 = 1; tmp.x2 = 1; tmp.x3 = 1; tmp.x4 = 0;
		return multiply(result, tmp);
	}
	tmp = fibo(N/2);
	result = multiply(tmp, tmp);
	// cout << result.x1 << result.x2 << result.x3 << result.x4 << endl;
	if (N%2 == 1) {
		tmp.x1 = 1; tmp.x2 = 1; tmp.x3 = 1; tmp.x4 = 0;
		result = multiply(result, tmp);
	}
	// cout << result.x1 << result.x2 << result.x3 << result.x4 << endl;
	return result;
}

int main() {
	fastio;
	unsigned long long N; cin >>N;
	matrix result;
	result = fibo(N);
	answer = result.x3;
	cout << answer << endl;
}
