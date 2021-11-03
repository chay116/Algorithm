import requests
import json

def get_score(url, headers):
	path = 'score'
	req = requests.get('/'.join([url, path]), headers = headers)
	j = req.json()
	try:
		print(j["efficiency_score"])
		print(j["accuracy_score1"])
		print(j["accuracy_score2"])
		print(j["score"])
	except KeyError:
		print(j['message'])

def get_api(url, headers, path):
	req = requests.get('/'.join([url, path]), headers = headers)
	j = req.json()
	try:
		list = j[path]
	except KeyError:
		list = []
	return list

def match(url, headers, data):
	path = 'match'
	pairs = { 'pairs' : data }
	req = requests.put('/'.join([url, path]), headers = headers, data=json.dumps(pairs))
	return req.json()

def change_grade(url, headers, data):
	path = 'change_grade'
	commands = { 'commands' : data }
	req = requests.put('/'.join([url, path]), headers = headers, data=json.dumps(commands))
	return req.json()

def diff_from_time(time):
	diff = abs((40 - time) * 99000 / 35)
	return diff

def problem(number):
	url = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
	path = 'start'
	param = {'problem': number}
	key = 'afc26586cf89636496318f1f518d0dbd'
	headers = {'X-Auth-Token':key, 'Content-Type': 'application/json'}
	req = requests.post('/'.join([url, path]), headers = headers, data=json.dumps(param))
	j = req.json()
	auth_key = j['auth_key']
	headers = {'Authorization':auth_key, 'Content-Type': 'application/json'}
	user_info = get_api(url, headers, 'user_info')
	id_list = [40000 for _ in range(len(user_info) + 1)]
	turn = 0
	while turn < 596:
		game_results = get_api(url, headers, 'game_result')
		for result in game_results:
			diff = diff_from_time(result['taken'])
			winner = id_list[result['win']]
			loser = id_list[result['lose']]
			expected_win = winner / (winner + loser)
			change_in_elo = 1000 * (1 - expected_win)
			id_list[result['win']] += change_in_elo
			id_list[result['lose']] -= change_in_elo
			if id_list[result['win']] >= 100000:
				id_list[result['win']] = 100000
			if id_list[result['lose']] <= 1000:
				id_list[result['lose']] = 1000

		waiting = get_api(url, headers, 'waiting_line')
		for i in range(len(waiting)):
			waiting[i]['grade'] = id_list[waiting[i]['id']]
			waiting[i]['available'] = True
		match_pairs = []
		for i in range(len(waiting)):
			if waiting[i]['available']:
				for j in range(i + 1, len(waiting)):
					if waiting[j]['available']:
						if (abs(waiting[i]['grade'] - waiting[j]['grade']) <= 20000) or \
							(abs(waiting[i]['grade'] - waiting[j]['grade']) <= 40000 and \
								(waiting[i]['from'] >= 3 or waiting[j]['from'] >= 3)) or \
							(abs(waiting[i]['grade'] - waiting[j]['grade']) <= 80000 and \
								(waiting[i]['from'] >= 5 or waiting[j]['from'] >= 5)) or \
								(waiting[i]['from'] >= 8 or waiting[j]['from'] >= 8):
							waiting[i]['available'] = False
							waiting[j]['available'] = False
							match_pairs.append([waiting[i]['id'], waiting[j]['id']])
		match(url, headers, match_pairs)
		turn += 1
		print(" now : {0}, waiting_list : {1}".format(turn, len(waiting)))

	command = []
	for i in range(1, len(id_list)):
		command.append({'id' : i, 'grade' : id_list[i]})
	change_grade(url, headers, command)
	get_score(url, headers)
	print(number)

problem(1)
problem(2)
