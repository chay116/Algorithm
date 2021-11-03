def solution(id_list, report, k):
	len = 0
	name_dict = {}
	for id in id_list:
		name_dict[id] = len
		len += 1
	sue = [0 for _ in range(len)]
	checkboard = [[False for _ in range(len)] for _ in range(len)]
	print(name_dict)
	for line in report:
		accuser, accused = line.split()
		if not checkboard[name_dict[accuser]][name_dict[accused]]:
			checkboard[name_dict[accuser]][name_dict[accused]] = True
			sue[name_dict[accused]] += 1
	answer = [0 for _ in range(len)]
	checkboard = [[False for _ in range(len)] for _ in range(len)]
	for line in report:
		accuser, accused = line.split()
		if not checkboard[name_dict[accuser]][name_dict[accused]] and sue[name_dict[accused]] >= k:
			checkboard[name_dict[accuser]][name_dict[accused]] = True
			answer[name_dict[accuser]] += 1
	return answer
a = ["muzi", "frodo", "apeach", "neo"]
b = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2
print(solution(a, b, k))