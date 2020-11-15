#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<bool> visit;
bool check = false;

void BFS(int start, int friend_count ,int n){
    if( friend_count == 4 ) {
        check = true;
        return ;
    }
    visit[start] = true;
    
    for(int i = 0 ; i < map[start].size() ; i++){
        if( check ) return ;
        if( !visit[map[start][i]]){
            BFS(map[start][i], friend_count+1,  n);
        }
    }
    visit[start] = false;
}

int main(){
    int n , m;
    scanf("%d %d",&n,&m);
    map.resize(n);
    visit.resize(n);
    for(int i = 0 ; i < m ; i++){
        int t1, t2;
        scanf("%d %d",&t1,&t2);
        map[t1].push_back(t2);
        map[t2].push_back(t1);
    }
    
    for(int i = 0; i < n; i++){
        fill(visit.begin(), visit.end(), false);
        BFS(i, 0, n);
        if( check ){
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
