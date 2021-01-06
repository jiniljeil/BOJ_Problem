#include <iostream>
#include <vector> 
#include <queue> 
#include <cstring>
#define MAX 1001
using namespace std;

int T, N, K, W ; // 테스트 케이스 수, 건물 개수, 건설 순서 규칙, 건설해야할 건물 번호

int Entry[MAX];
int Time[MAX]; 
int MinTime[MAX]; 
vector<int> v[MAX]; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> T ;
    for(int i = 0 ; i < T ; i++){
        cin >> N >> K ; 
        int a,b,t ;
        queue<int> q ;
        // Input 
        for(int j = 1 ; j <= N ; j++) cin >> Time[j] ; 
        for(int j = 0 ; j < K ; j++){
            cin >> a >> b ;
            v[a].push_back(b);
            Entry[b]++;
        }
        cin >> W ; // 건설해야할 건물 번호 

        for(int j = 1; j <= N; j++) {
            if( Entry[j] == 0 ) {
                MinTime[j] = Time[j]; 
                q.push(j);
            }
        }
        while(!q.empty()){
            int curr_v= q.front(); 
            q.pop() ;

            for(int k = 0 ; k < v[curr_v].size(); k++){
                int next_v = v[curr_v][k]; 
                MinTime[next_v] = (MinTime[next_v] > MinTime[curr_v] + Time[next_v] ) ? MinTime[next_v] : MinTime[curr_v] + Time[next_v];
                Entry[next_v]-- ;
                if(Entry[next_v] == 0) q.push(next_v);
            }
        }
        cout << MinTime[W] << "\n";
        // Clear
        memset(Time, 0 , sizeof(Time)) ;
        memset(MinTime, 0 , sizeof(MinTime));
        memset(Entry, 0 , sizeof(Entry));
        for(int j = 1 ; j <= N; j++) v[j].clear();
    }
    return 0;
}