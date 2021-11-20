#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define ARR_SIZE 12
int arr[] = {1, 9, 3, 8, 4, 5, 5, 8, 10, 3, 4, 5};
int tree[4 * ARR_SIZE]; // tree는 입력 배열 사이즈의 4배면 모두 커버가 가능하다.

// segment tree 처음에 만들어주는 함수
int init(int start, int end, int node) {
	// 1개짜리인 경우는 하나만 넣어주기
	if (start == end) return tree[node] = arr[start];
	// 그렇지 않는 경우는 이를 쪼개서 넣은 값의 합.
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	// 범위 밖인 경우
	if (left > end || right < start) return 0;
	// 범위 안에 있는 경우
	if (left <= start && end <= right) return tree[node];
	// 걸쳐 있다면 두 부분으로 나누어서 합 구하기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
	// 범위 밖인 경우
	if (index < start || index >> end) return;
	// 범위 안이면 내려가면서 값 갱신
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
	// 처음 초기화
	init(0, ARR_SIZE - 1, 1);
	// 구간 수정 인덱스 5의 원소를 -5만큼 수정
	update(0, ARR_SIZE - 1, 1, 5, -5);
}