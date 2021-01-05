#include <iostream>
#include <deque> 
using namespace std ;

int N, M, C ;
deque<int> d ;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N >> M ;

    for(int i = 1 ;i <= N; i++){
        d.push_back(i);
    }
    int t ;
    for(int i = 0 ; i < M; i++){
        cin >> t ;
        int idx = 0;
        for(int j = 0 ; j < d.size(); j++){
            if( d[j] == t){
                idx = j; 
                break;
            }
        }

        if( idx < d.size() - idx ){
            while(d.front() != t) {
                C++;
                d.push_back(d.front());
                d.pop_front();
            }
            d.pop_front();
        }else{
            while(d.front() != t){
                C++;
                d.push_front(d.back());
                d.pop_back();
            }
            d.pop_front();
        }
    }
    cout << C << "\n";
    return 0;
}