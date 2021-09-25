#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm> 
#define MAX 300010
using namespace std; 

int N, K, idx; 
pair<int,int> items[MAX] ; 
int bag[MAX]; 
priority_queue<int> pq ; 
unsigned long long sum = 0 ;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    cin >> N >> K ;  

    for (int i = 0 ; i < N ; i++) {
        cin >> items[i].first >> items[i].second ; 
    }   
    for (int i = 0 ; i < K ; i++) {
        cin >> bag[i] ;
    } 

    sort(items, items + N) ;
    sort(bag, bag + K) ;

    for (int i = 0; i < K ; i++) {
        while(idx < N && bag[i] >= items[idx].first ) {
            pq.push(items[idx++].second) ; 
        }

        if (!pq.empty()) {
            sum += pq.top() ; pq.pop();
        }
    }

    cout << sum << '\n';
    return 0;
}