def solution(board, aloc, bloc):
	dxys = [[1, 0], [-1, 0], [0, 1], [0, -1]]

	def move_b(step):
		results = []
		if board[bloc[0]][bloc[1]] == 0:
			return step
		possible = False
		board[bloc[0]][bloc[1]] = 0
		for dx, dy in dxys:
			if 0 <= bloc[0] + dx < len(board) and 0 <= bloc[1] + dy < len(board[0]) and board[bloc[0] + dx][bloc[1] + dy] != 0:
				possible = True
				bloc[0] += dx
				bloc[1] += dy
				results.append(move_a(step + 1))
				bloc[0] -= dx
				bloc[1] -= dy
		board[bloc[0]][bloc[1]] = 1
		if not possible:
			return step
		else:
			result = []
			for i in results:
				if i % 2 == 0:
					result.append(i)
			if result:
				return min(result)
			else:
				return max(results)

	def move_a(step):
		results = []
		if board[aloc[0]][aloc[1]] == 0:
			return step
		possible = False
		board[aloc[0]][aloc[1]] = 0
		for dx, dy in dxys:
			if 0 <= aloc[0] + dx < len(board) and 0 <= aloc[1] + dy < len(board[0]) and board[aloc[0] + dx][aloc[1] + dy] != 0:
				possible = True
				aloc[0] += dx
				aloc[1] += dy
				results.append(move_b(step + 1))
				aloc[0] -= dx
				aloc[1] -= dy
		board[aloc[0]][aloc[1]] = 1
		if not possible:
			return step
		else:
			result = []
			for i in results:
				if i % 2 == 1:
					result.append(i)
			if result:
				return min(result)
			else:
				return max(results)
	answer = move_a(0)
	return answer

board = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
aloc = [1, 0]
bloc = [1, 2]
print(solution(board, aloc, bloc))