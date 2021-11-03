def solution(n, k):
	num_k = ""
	while n != 0:
		num_k = str(n % k) + num_k
		n = n // k
	answer = 0
	for num in num_k.split("0"):
		if num == '':
			pass
		else:
			i = 2
			num = int(num)
			while num % i != 0 and i * i < num:
				i += 1
			if (num % i != 0 and num != 1) or num == 2:
				answer += 1
	return answer

print(solution(437674, 3))