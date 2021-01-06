#include <iostream>
#include <vector> 
#define MAX 1001
using namespace std;

int T, N, K, W ; // 테스트 케이스 수, 건물 개수, 건설 순서 규칙, 건설해야할 건물 번호

int time[MAX];
vector<int> v[MAX]; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> T ;
    for(int i = 0 ; i < T ; i++){
        vector<int> time;
        cin >> N >> K ; 
        int a,b,t ;
        // Input 
        for(int j = 1 ; j <= N ; j++) cin >> time[j] ; 
        for(int j = 0 ; j < K ; j++){
            cin >> a >> b ;
            v[a].push_back(b);
        }
        cin >> W ; // 건설해야할 건물 번호 

        
        // Clear
        for(int j = 1 ; j <= N+1; j++) v[j].clear();
    }
    return 0;
}