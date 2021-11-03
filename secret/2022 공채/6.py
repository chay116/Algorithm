import numpy as np

def solution(board, skill):
    map = np.array(board)
    for status, sx, sy, ex, ey, amount in skill:
        if status == 1:
            map[sx : ex + 1, sy : ey + 1] -= amount
        else:
            map[sx : ex + 1, sy : ey + 1] += amount
    answer = int(np.sum(np.sum(map > 0, axis=0)))
    return answer