def solution(fees, records):
	std_time, std_fee, add_time, add_fee = fees
	answer = []
	order = 0
	car_dict = {}
	car_status = [] #[number, time, status, in_time]
	for str in records:
		time, number, status = str.split()
		hour, minute = time.split(":")
		time = int(hour) * 60 + int(minute)
		if status == "IN":
			try:
				num = car_dict[number]
				car_status[num][2] = True
				car_status[num][3] = time
			except KeyError:
				car_dict[number] = order
				order += 1
				car_status.append([number, 0, True, time])
		else:
			num = car_dict[number]
			car_status[num][2] = False
			car_status[num][1] += time - car_status[num][3]
			car_status[num][3] = 0
	car_status.sort()
	for status in car_status:
		if status[2]:
			status[1] += 23 * 60 + 59 - status[3]
		if status[1] <= std_time:
			answer.append(std_fee)
		else:
			answer.append(std_fee + ((status[1] - std_time - 1) // add_time  + 1)* add_fee)

	return answer



fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
print(solution(fees, records))