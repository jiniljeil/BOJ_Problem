## 합이 0 (BOJ - Binary Search + 중복)

주어진 값들 중 세 값을 더했을 때 0이 되는 집합을 찾는 문제

단순 Binary Search로 풀었다가 동일한 값이 여러개 있는 경우를 생각하지 않고 풀어서 틀림

예를 들어, [-3,-2,5,5,5] 와 같은 경우 총 3 가지 조합이 나올 수 있다는 것

:star: binary_search() 함수로 풀면 안되고, lower_bound, upper_bound로 남은 값 찾아서 answer += (upper_bound - lower_bound)로 중복도 허용해줘야한다. 

## 세 용액 (BOJ 2473) - Binary Search 

세 합이 0에 가장 가깝게 나타나는 세 용액을 찾는 문제 

:star: 이분 탐색 기본 문제 

## 합이 0인 네 정수 (BOJ 7453) - Binary Search

네 합이 0이 되는 경우를 모두 찾는 문제

:star: 4개의 배열 중 2개 배열의 합을 담고 있는 배열을 생성한 후, 나머지 2개의 배열의 합을 이분 탐색으로 찾아주면 된다. 