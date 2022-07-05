from collections import deque

N = int(input())
x_visited = [0] * N
x_y = [0] * (2*N - 1)
minus_x_y = [0] * (2*N - 1)
cnt = 0

def dfs(k):
	global cnt
	if k == N:
		cnt += 1
		return
	for i in range(N):
		if not x_visited[i] and not x_y[k+i] and not minus_x_y[k-i]:
			x_visited[i] = 1
			x_y[k+i] = 1
			minus_x_y[k-i] = 1
			dfs(k+1)
			x_visited[i] = 0
			x_y[k+i] = 0
			minus_x_y[k-i] = 0

dfs(0)
print(cnt)