#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 

using namespace std; 

vector<pair<int, int> > v ; // S, T 
priority_queue<int, vector<int>, greater<int> > pq ; // T, class_num ; 
int n, class_num = 1; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;
    int S,T;
    cin >> n ; 
     
    for (int i = 0 ; i < n ; i++) {
        cin >> S >> T ; 
        v.push_back(make_pair(S, T)); 
    }

    sort(v.begin(), v.end()); 

    pq.push(v[0].second); 
    for(int i = 1 ; i < v.size(); i++) { 
        int End = pq.top(); 
        
        if (v[i].first < End) {
            class_num++; 
        }else{
            pq.pop(); 
        }
        pq.push(v[i].second); 
    }

    cout << class_num << '\n' ; 

    return 0 ;
}