#include <bits/stdc++.h> 
#define SIZE 1001
using namespace std ;

typedef struct quest { 
    int STR, INT, PNT; 
} quest ;

int N ; 
bool psb[SIZE][SIZE] ;
int lp[SIZE][SIZE] ; 
int sol[SIZE][SIZE] ; 
vector<quest> V ;
int point, result; 

int main(void) { 
    ios::sync_with_stdio(0); cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N ; i++) {
        int a,b,c; cin >> a >> b >> c; 
        V.push_back({a, b, c}) ;
    }

    for (int STR = 1 ; STR < SIZE ; STR++) {
        for (int INT = 1; INT < SIZE ; INT++) { 
            int p = 0 ; 
            for (int k = 0 ; k < V.size(); k++) { 
                if ( STR >= V[k].STR || INT >= V[k].INT ) { 
                    p += V[k].PNT ; 
                    sol[STR][INT]++ ;
                }
            }
            lp[STR][INT] = p - (STR - 1) - (INT - 1) ;
            if ( (STR == 1 && INT == 1) || 
                 (STR - 1 > 0 && psb[STR - 1][INT] && lp[STR - 1][INT] > 0) ||
                 (INT - 1 > 0 && psb[STR][INT - 1] && lp[STR][INT - 1] > 0)
                ) { psb[STR][INT] = true ; }
        } 
    }
    
    for (int i = 1; i < SIZE ; i++ ) { 
        for (int j = 1 ; j < SIZE ; j++) { 
            if ( psb[i][j] ) result = max(result, sol[i][j]) ;
        }
    }

    cout << result << '\n';
    return 0;
}