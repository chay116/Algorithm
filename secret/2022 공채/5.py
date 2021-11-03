def solution(info, edges):
	sheep_check = [False for _ in range(len(info))]
	#sheepboard = [[-1 for _ in range(len(info))] for _ in range(len(info))]
	next = [[] for _ in range(len(info))]
	for input, output in edges:
		#sheepboard[input][output] = info[output]
		next[input].append(output)
	for i in next[0]:
		sheep_check[i] = True
	result = []
	def dfs(score, num_sheep):
		possible = True
		for candidate in range(len(info)):
			if sheep_check[candidate]:
				if info[candidate] and score <= 1:
					pass
				else:
					possible = False
					sheep_check[candidate] = False
					for next_ele in next[candidate]:
						sheep_check[next_ele] = True
					if not info[candidate]:
						#print(candidate, score + 1, sheep_check, num_sheep + 1)
						dfs(score + 1, num_sheep + 1)
					else:
						#print(candidate, score - 1, sheep_check, num_sheep - 1)
						dfs(score - 1, num_sheep)
					for next_ele in next[candidate]:
						sheep_check[next_ele] = False
					sheep_check[candidate] = True
		if possible:
			result.append(num_sheep)
	dfs(1, 1)
	return max(result)

info = [0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0]
edges = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6], [3, 7], [4, 8], [6, 9], [9, 10]]
print(solution(info, edges))