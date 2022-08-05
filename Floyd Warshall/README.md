## 운동 (BOJ 1956) - (Floyd Warshall, Cycle) 

사이클이 발생할 경우 사이클의 최소 시간을 구하는 문제

사이클인지 확인하는 방법

```C++ 
long long answer = INF ; 
for (int i = 0 ; i < V ; i++) { 
    for (int j = i + 1 ; j < V ; j++ ) {
        if ( DIST[i][j] != INF && DIST[j][i] != INF ) { 
            answer = min(answer, DIST[i][j] + DIST[j][i]) ; 
        }
    }
}
```