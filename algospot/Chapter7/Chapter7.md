# Chapter 6 divide&conquer(분할 정복)

## <span style="color:#959597">__1. 도입__<span>
주어진 문제를 둘 이상의 부분 문제로 나눈 뒤 각 문제에 대한 답을 계산해 냅니다. 이 방법이 재귀 호출과 가장 다른 점은 문제를 한조각과 나머지 전체로 나누는 대신, 분할 정복은 보통 동일한 크기의 문제로 n 분할 한다는 점입니다. 이는 보통 세가지 순서로 이루어지는데
1. Divide : 문제를 더 작은 문제로 분할하는 과정
2. Merge : 각 문제에 대해 구한 답을 원래 문제에 대한 답으로 병합하는 과정
3. Base Case : 더 이상 답을 분할하지 않고 곧장 풀 수 있는 매우 작은 문제


따라서 문제를 잘 나누고, 적당한 선에서 계산을 수행하여, 이를 잘 조합해야합니다. 재귀 분할의 가장 큰 장점은 시간 복잡도인데, 일반적인 재귀의 경우는 $O(n^2)$인 반면에 재귀 분할의 경우는 $O(n \log n)$입니다.
<hr/>

### - <span style="color:green">_quadtree_ (난이도 : 하)<span>

[문제 링크](https://algospot.com/judge/problem/read/QUADTREE) <br/>
x가 존재하지 않으면 그대로 출력하고, x가 존재하면 분할 정복을 4개로 한다. 이때 구역을 4개로 나눴을 때, 뒤의 두개를 먼저 출력하고 앞의 두개를 출력하는 방식으로 가야한다. 따라서 처음에 앞의 두개를 넘어가고, 뒤에 것에 대해서 quad함수를 돌리고, 앞에 부분에 대해서 quad를 돌리면 분할 정복이 완성된다.<br/>

### - <span style="color:orange">_fence_ (난이도 :중)<span>

[문제 링크](https://algospot.com/judge/problem/read/FENCE) <br/>
두 영역의 fence가 합쳐지는 경우, fence가 크게 왼쪽, 오른쪽 혹은 걸쳐서 있는 경우 3가지가 존재하는데, 왼쪽과 오른쪽은 그 이전의 fence의 최대값을 걸쳐져 있는 경우는 경계선이 지나는 두 판자 중 짧은 판자의 길이로 0까지 보내면서 넓이를 구하면 된다. <br/>

### - <span style="color:red">_FANMEETING_ (난이도 : 상)<span>

[문제 링크](https://algospot.com/judge/problem/read/FANMEETING) <br/>
분할 정복으로는 못 풀고, 비트 연산으로 풀었는데 어디서 잘 못 된건지 잘 모르겠다. 다른 사람 답을 돌려도 오답이 나온다... 음 일단 그래서 개념만 가져가고 포기...