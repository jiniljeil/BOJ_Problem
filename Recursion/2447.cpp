#include <iostream> 

using namespace std ;

void func(int x, int y, int size) { 
  if( (x / size) % 3 == 1 && (y / size) % 3 == 1) {
    cout << ' ';
  }else{
    if( size/3 == 0 ) {
      cout << '*' ;
    }else{
      func(x , y , size/3);
    }
  }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0) ;

    int N ;
    cin >> N ; 
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
          func(i, j, N);
        }
        cout << '\n';
    }

    return 0;
    
}

