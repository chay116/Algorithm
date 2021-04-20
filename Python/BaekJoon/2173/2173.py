f = open("testcase.txt", "r")

N, onion = map(int, f.readline().split())
board = []
result = []
problem = 0
for i in range(N):
    board.append(f.readline().split())

while onion and not problem:

