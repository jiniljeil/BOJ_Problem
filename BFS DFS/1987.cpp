#include <iostream> 
#include <string> 
#include <set> 
#include <queue> 
#include <stdlib.h>
#include <string.h> 

#define MAX 21

using namespace std ; 

int R, C ; // 세로, 가로
char MAP[MAX][MAX] ; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, -1, 0, 1} ; 
int result = 0 ;  
void DFS(int alphabets[26], int sum, int y, int x) {
    if ( result < sum ) { 
        result = sum ; 
    } 
    
    for (int i = 0 ; i < 4 ; i++) { 
        int dir_x = x + dx[i] ; 
        int dir_y = y + dy[i] ; 
        
        if ( dir_y < 0 || dir_y >= R || dir_x < 0 || dir_x >= C) continue ; 

        if ( alphabets[ MAP[dir_y][dir_x] - 'A' ] == 0 ) { 
            alphabets[ MAP[dir_y][dir_x] - 'A']++; 
            DFS(alphabets, sum + 1, dir_y, dir_x) ;
            alphabets[ MAP[dir_y][dir_x] - 'A']--; 
        } 
    }
}

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0) ; 

    int alphabets[26] ; 

    for (int i = 0 ; i < 26; i++) {
        alphabets[i] = 0 ; 
    }

    string s ; 
    cin >> R >> C ; 

    for (int i = 0 ; i < R ; i++) {
        cin >> s; 

        for (int j = 0 ; j < C ;j++) { 
            MAP[i][j] = s[j] ;
        }
    } 

    alphabets[MAP[0][0] - 'A']++; 
    DFS(alphabets, 1, 0, 0) ; 

    cout << result << '\n' ; 
    return 0;
}