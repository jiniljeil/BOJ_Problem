#include <iostream> 
#include <string> 
#include <set> 
#include <stack> 
#include <cmath>
#define SIZE 129 
using namespace std ;

int R, C ; 
set<string> Set ; 
int map[SIZE][SIZE] ; 
void qtree(string &s, int y, int x, int size) { 

    bool white = false, black = false; 
    for (int i = y ; i < y + size ; i++) { 
        for (int j = x ; j < x + size ; j++) { 
            if ( map[i][j] == 0 ) white = true ;
            else if ( map[i][j] == 1 ) black = true ;
        }
    }

    if ( white && black ) { 
        s += "(";
        int half = size / 2 ;
        qtree(s, y, x, half); 
        qtree(s, y, x + half, half) ; 
        qtree(s, y + half, x, half) ; 
        qtree(s, y + half, x + half, half) ;
        
        s += ")";
    } else {
        s += (white) ? "w" : "b"; 
    }
}

int getSize() { 
    int size = 0;
    int large = (R > C) ? R : C ;
    int k = 1 ; 
    while ( 1 ) { 
        if ( large == pow(2, k)){
            size = pow(2, k) ;
            break; 
        }else if ( large > pow(2, k) && large < pow(2, k + 1)) { 
            size = pow(2, k + 1) ;
            break ;
        } else {
            k++; 
        }
    }
    return size ;
}
int main(void) { 
    scanf("%d %d", &R, &C) ; 

    for (int i = 0; i < R ; i++) { 
        for (int j = 0 ; j < C ; j++) { 
            scanf("%1d", &map[i][j]) ;
        }
    }

    int size = getSize() ; 
    
    string s = ""; 
    qtree(s, 0, 0, size) ; 

    cout << s << '\n' ;
    int origin = 0, extract = 0 ; 

    stack<string> S;
    string word = "";
    int cnt = 0 ;
    int cnt2 = 0 ; 

    for (int i = 0 ; i < s.size(); i++) { 
        if ( s[i] == '(') { 
            cnt++ ;  
            S.push("(");
            if ( word != "" ) { 
                origin += word.length() ;
                if ( Set.find(word) == Set.end() )
                    Set.insert(word) ;
                else
                    cnt2++; 
                word = ""; 
            } 
        }
        else if ( s[i] == ')') { 
            if ( Set.find(word) == Set.end() )
                Set.insert(word) ;
            else
                cnt2++; 
            origin += word.length() ; 
            S.pop() ; 
            word = ""; 
        } else { 
            word += s[i]; 
        }
    }

    set<string>::iterator it ; 
    for (it = Set.begin() ; it != Set.end() ; it++ ) {
        extract += (*it).length(); 
    } 

    cout << origin + cnt << ' ' << extract + cnt - cnt2 << '\n'; 
    return 0;
}

/*
4 6
101001
111000
000000
111111

(정답) 37 27

10100100
11100000
00000000
11111100
00000000
00000000
00000000
00000000

*/