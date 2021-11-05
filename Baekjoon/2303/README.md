# <span style="font-size:17pt; font-weight:bold">BOJ 2042번 구간 합 구하기 문제 자바(java)  풀이</span>
- 랭크 : 실버5
- [백준 2042번 구간 합 구하기](https://www.acmicpc.net/problem/2042)
<br><br>

# <span style="font-size:15pt">문제 정리</span>
1. N개의 수가 주어진다.
2. 중간에 수의 변경이 빈번히 일어난다. 그리고 어떤 부분의 부분합을 구하려 한다.
3. 쿼리가 주어진다.
4. 쿼리의 맨 앞이 1이면 값을 변경, 2이면 구간 합을 구한다.
<br><br>

# <span style="font-size:15pt">문제 풀이</span>
|알고리즘|자료구조|시간복잡도|공간복잡도|
|:---:|:---:|:---:|:---:|
| Brute force | Brute force | O(N)| O(N) |

<br>
수의 변경이 빈번하게 일어나고 계속 해서 구간합을 구해야 하기 때문에 세그먼트 트리를 이용하면 빠르게 구할 수 있습니다.
수를 변경하는데 O(logN), 구간합을 구하는데 O(logN) 이를 M번 하면 O(MlogN)정도면 구할 수 있을 것 같습니다.
