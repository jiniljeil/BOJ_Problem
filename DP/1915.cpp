#include <iostream>
#define SIZE 1001
using namespace std;

typedef long long ll ; 
ll DP[SIZE][SIZE];
int R, C;
ll result;

int main(void) {
  scanf("%d %d", &R, &C);

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%1d", &DP[i][j]);
    }
  }

  for (int i = 1; i < R; i++) {
    for (int j = 1; j < C; j++) {
      if (DP[i][j] != 0) {
        DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      result = max(result, DP[i][j]);
    }
  }

  printf("%lld\n", result * result);
  return 0;
}
