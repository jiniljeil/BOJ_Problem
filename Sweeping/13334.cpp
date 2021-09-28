#include <iostream>
#include <algorithm> 
#include <queue> 
#include <vector> 
#define INF 1e9

using namespace std; 

int N, L, h, o; 
vector<pair<int,int> > v ; 
priority_queue<int, vector<int>, greater<int> > pq; 
bool compare(pair<int,int> a, pair<int,int> b) {
    if ( a.second != b.second ) {
        return a.second < b.second ; 
    }else{ 
        return a.first < b.first ;
    }
}
int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    cin >> N ; 

    for(int i = 0 ; i < N ;i++) {
        cin >> h >> o ; 
        if ( h > o ) swap(h, o);  
        v.push_back(make_pair(h, o)); 
    }    
    cin >> L ; 
    
    // 끝점을 기준으로 오름차순 정렬, 끝점의 위치가 같을 경우 시작점의 위치가 낮은게 앞으로 가도록
    sort(v.begin(), v.end(), compare ); 

    int result = 0 ; 

    for (int i = 0 ; i < v.size() ; i++) { 
        int start = v[i].first; 
        int end = v[i].second ; 

        // 집->사무실 거리가 철로의 길이보다 긴 경우
        if ( end - start > L ) continue; 

        pq.push(start); 

        while (!pq.empty()) {
            // (집, 집 + 철로의 길이) 범위 안에 End가 존재할 경우
            if ( pq.top() + L >= end ) {
                result = max(result, (int)pq.size()); 
                break; 
            // (집, 집 + 철로의 길이) 범위 밖에 End가 존재할 경우 
            }else { 
                pq.pop(); 
            }
        }
    }

    cout << result << '\n' ; 
     
    return 0 ;
}