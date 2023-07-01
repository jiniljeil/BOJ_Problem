#include <bits/stdc++.h>
#define SIZE 1001
using namespace std ;

int N, M ; 
int A[SIZE][SIZE], B[SIZE][SIZE] ;
pair<int,int> min_col = {-1e9, 0}, max_col = {1e9, 0} ; 
pair<int,int> min_row = {-1e9, 0}, max_row = {1e9, 0} ; 

int main() { 
    ios::sync_with_stdio(0) ;cin.tie(0); 

    cin >> N >> M ; 

    for (int i = 0 ; i < N ;i++) { 
        for (int j = 0 ; j < M ; j++) { 
            cin >> A[i][j] ; 
        }
    }

    
    return 0 ;
}