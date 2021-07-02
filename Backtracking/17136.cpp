#include <iostream>

using namespace std; 

int result = 1e8 ;
int copy_map[10][10]; 

bool set_check(int y, int x, int map[10][10], int type) { 
    if( map[y][x] == 0) return false;
    if( y < 0 || y + type > 10 || x < 0 || x + type > 10) return false; 
    bool flag = true; 
    for(int i = y ; i < y + type ; i++) {
        for(int j = x; j < x + type; j++) {
            if (map[i][j] == 0) {
                flag = false; 
                break; 
            }
        }
        if( flag == false) break; 
    }
    return flag ; 
}

void find_paper(int map[10][10], int cnt, int num_of_papers[5]) { 
    int y = -1, x = -1; 
    for(int i = 0 ; i < 10; i++) {
        for(int j = 0 ;j < 10; j++) {
            if( map[i][j] == 1) { 
                y = i; x = j; 
                break; 
            }
        }
        if (y != -1) break; 
    }
    if( y == -1 ) { 
        result = min(result, cnt); 
    }

    for(int type = 5 ; type >= 1; type--) {
        if (set_check(y,x, map, type) && num_of_papers[type-1] > 0) {
            for(int i = y; i < y + type; i++) {
                for(int j = x; j < x + type; j++) {
                    map[i][j] = 0; 
                }
            }
            num_of_papers[type-1]--; 
            find_paper(map, cnt + 1, num_of_papers); 
            for(int i = y; i < y + type; i++) {
                for(int j = x; j < x + type; j++) {
                    map[i][j] = copy_map[i][j]; 
                }
            }
            num_of_papers[type-1]++;
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0) ;

    int map[10][10] ;
    int num_of_papers[5] = {5,5,5,5,5}; 

    for(int i = 0 ; i < 10; i++) {
        for(int j = 0 ; j < 10; j++) {
            cin >> map[i][j] ; 
            copy_map[i][j] = map[i][j]; 
        }
    }

    find_paper(map, 0, num_of_papers);
    
    if( result == 1e8 ) { 
        cout << "-1" << '\n'; 
    }else{
        cout << result << '\n';
    }
    
    return 0;
}