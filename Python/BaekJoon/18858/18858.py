N, M = map(int, input().split())
# dp로 문제를 풀어나가기. 공간 복잡도는 dp에 사용할 O(N * M)으로 해결 가능하다.
# 시간 복잡도는 공간을 다 돌면서 한번 수행할 때마다 M번 또 돌기 때문에 O(N * M^2)이다.
# 3차원 배열을 구성하여, 앞에 것이 큰 경우 0번에 나머지 경우는 1번에 넣어, 다음과 같이 더해주면 모든 경우의 수를 고려 가능하다.
# python 으로는 시간 초과가 뜨는데, 이거 맞는 방법인지 잘 모르겠다.
# 먼저 첫번째에서는, 맨 끝에서 2번째까지는 손쉽게 풀 수 있기에 기본으로 넣어놓고, 뒤에는 dp로 풀자.
# 맞긴 맞았는데, 엄청 비효율적이다... 개념은 틀리지 않았으나 앞에서 뒤로 가는게 하기 편하고, itertools의 accumulation을 사용해서
# 앞의 합을 쉽게 표현가능하기 때문에, 더 효율적으로 할 수 있다.
if N == 1:
    print(M%998244353)
else:
    board = [[[0, 0] for _ in range(M)] for _ in range(N-1)]
    for i in range(M):
        board[N - 2][i][0] = M
        board[N - 2][i][1] = M - i
    pos = N - 3
    while pos >= 0:
        for i in range(M):
            for j in range(M):
                if i >= j:
                    board[pos][i][0] += board[pos + 1][j][0]
                    if i == j:
                        board[pos][i][1] += board[pos + 1][j][0]
                else:
                    board[pos][i][0] += board[pos + 1][j][1]
                    board[pos][i][1] += board[pos + 1][j][1]
        pos -= 1
    total = 0
    for i in range(M):
        total += board[0][i][0]
    print(total%998244353)
