#include <iostream>

using namespace std;

bool column[16];
bool rdiagonal[32];
bool ldiagonal[32];
int c = 0 ;

void queen(int curr, int n_queen){
    if( curr == n_queen){
        c++;
        return ;
    }
    for(int i = 0 ; i < n_queen; i++){
        if(!(column[i] || rdiagonal[i+curr] || ldiagonal[curr-i+n_queen-1])){
            column[i] = true;
            rdiagonal[i+curr] = true;
            ldiagonal[curr-i+n_queen-1] = true;
            queen(curr+1,n_queen);
            column[i] = false;
            rdiagonal[i+curr] = false;
            ldiagonal[curr-i+n_queen-1] = false;
        }
    }
}



int main(int argc, const char * argv[]) {
    int n_queen;
    scanf("%d",&n_queen);
    queen(0,n_queen);
    
    printf("%d",c);
    return 0;
}
