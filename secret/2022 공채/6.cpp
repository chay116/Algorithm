#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int solution(vvi board, vvi skill) {
   int n = board.size(), m = board[0].size(), ret = 0;
   vvi v(n + 1, vi(m + 1)); // v[0][0] + ... + v[i][j] == board[i][j]

   // 1. board 배열 -> v 배열 구축
   for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) v[i][j] = board[i][j];
      else if (i == 0) v[i][j] = board[i][j] - board[i][j - 1];
      else if (j == 0) v[i][j] = board[i][j] - board[i - 1][j];
      else v[i][j] = board[i][j] - board[i - 1][j] - board[i][j - 1] + board[i - 1][j - 1];
   }

   // 2. query 처리
   for (const auto& w : skill) {
      int val = w[0] & 1 ? -w[5] : w[5];
      int x1 = w[1], y1 = w[2];
      int x2 = w[3], y2 = w[4]; ++x2, ++y2;
      v[x1][y1] += val; v[x1][y2] -= val;
      v[x2][y1] -= val; v[x2][y2] += val;
   }

   // 3. v 배열 -> board 배열 복원
   for (int i = 1; i < n; i++) for (int j = 0; j < m; j++) v[i][j] += v[i - 1][j];
   for (int j = 1; j < m; j++) for (int i = 0; i < n; i++) v[i][j] += v[i][j - 1];
   for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (v[i][j] > 0) ret++;
   return ret;
}