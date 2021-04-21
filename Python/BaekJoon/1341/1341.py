a, b = map(int, input().split())

# 밑은 무조건 2^n - 1 의 꼴이 되며 n 자리수의 행렬을 가지게 되기 때문에 먼저 n을 찾는 것이 중요하다
# b의 배수 꼴이 되어야하기 때문에, mod b에서 나머지 1인 2^n 을 찾았고, b의 몇 배수인지 찾은 후
# 모든 값이 2^m 꼴이기 때문에 비트 연산자로 쉽게 구할 수 있다.

n = 1
num = 2
while num - 1 < b:
    num *= 2
    n += 1
num %= b
while n <= 60 and num != 1 and b != 1:
    num *= 2
    n += 1
    num %= b
if n > 60:
    print(-1)
else:
    k = (2 ** n - 1) // b
    a *= k
    b *= k
    num = 1 << (n - 1)
    while num:
        if num & a:
            print('*', end='')
        else:
            print('-', end='')
        num //= 2