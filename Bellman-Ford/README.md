## 타임머신 (BOJ 11657) - (Bellman-Ford)

벨만-포드 알고리즘을 적용하고 음수 사이클 여부를 확인하는 문제 
시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력하도록 되어있다.
음수 사이클이 존재할 경우를 의미한 것이지만, DIST 값에 음수가 포함되는 경우로 잘못 생각하여 틀렸었다.
:star: Bellman-Ford 알고리즘 적용, 사이클 여부 