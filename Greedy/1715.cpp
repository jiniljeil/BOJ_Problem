#include <iostream> 
#include <queue> 
#include <algorithm>
using namespace std ; 
priority_queue<int, vector<int>, greater<int> > pq ; 
int N, num; 
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 
    cin >> N ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> num ; pq.push(num) ; 
    }

    long long result = 0 ; 
    while(pq.size() != 1)  {
        int first = pq.top(); pq.pop() ; 
        int second = pq.top(); pq.pop() ; 

        result += (first + second) ; 
        pq.push(first + second) ; 
    }

    cout << result << '\n'; 
    return 0 ;
}