def solution(n, info):
	answer = [0 for _ in range(11)]
	real_answer = [0 for _ in range(11)]
	result = [0]

	def scoring(score):
		if score <= 0:
			return
		if result[0] == score:
			for i in range(11):
				if real_answer[10 - i] > answer[10 - i]:
					return
				if real_answer[10 - i] < answer[10 - i]:
					break
			for i in range(11):
				real_answer[i] = answer[i]
			result[0] = score
		if result[0] < score:
			for i in range(11):
				real_answer[i] = answer[i]
			result[0] = score


	def dfs(i, j, score, max_try):
		if j == 11:
			answer[10] = max_try - i
			scoring(score)
			answer[10] = 0
			return
		if max_try - i > info[j]:
			answer[j] = info[j] + 1
			dfs(i + info[j] + 1, j + 1, score + 10 - j, max_try)
			answer[j] = 0
		if info[j] == 0:
			dfs(i, j + 1, score, max_try)
		else:
			dfs(i, j + 1, score - 10 + j, max_try)

	dfs(0, 0, 0, n)
	if result[0] == 0:
		return [-1]
	return real_answer


n = 9
info = [0,0,1,2,0,1,1,1,1,1,1]
print(solution(n, info))