
- 2차원 배열 분리 집합 문제 : [BOJ 16724](https://www.acmicpc.net/problem/16724)

- 2차원 배열 초기화
    ```c++
    for (int i = 0 ; i < row ; i++) 
        memset(arr[i], 0, sizeof(int) * col);
    ```
- C++ lambda
    ```C++
    [&] = 람다 함수 앞에 선언된 모든 이부 변수를 Reference Type으로 잡아 사용
    [] = 외부 변수 사용 X
    [=] = 모든 외부 변수를 값을 복사하여 상수 변수로 사용
    [&a, =b] a는 참조값으로 b는 상수 값으로 사용   
    ```