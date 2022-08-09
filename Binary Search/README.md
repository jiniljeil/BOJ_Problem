## 합이 0 (BOJ - Binary Search + 중복)

주어진 값들 중 세 값을 더했을 때 0이 되는 집합을 찾는 문제

단순 Binary Search로 풀었다가 동일한 값이 여러개 있는 경우를 생각하지 않고 풀어서 틀림

예를 들어, [-3,-2,5,5,5] 와 같은 경우 총 3 가지 조합이 나올 수 있다는 것

:star: binary_search() 함수로 풀면 안되고, lower_bound, upper_bound로 남은 값 찾아서 answer += (upper_bound - lower_bound)로 중복도 허용해줘야한다. 

