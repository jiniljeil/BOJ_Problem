#include <iostream> 
#include <cstring> 
#include <vector> 
#define MAX 1001
using namespace std ;
int N, M, K;
vector<int> V[MAX] ; 
int matched[MAX] ; 
bool visited[MAX] ; 

bool dfs(int k) { 
    for (int i = 0 ; i < V[k].size(); i++) {
        int t = V[k][i] ; 
        if (visited[t]) continue ; 
        visited[t] = true ; 

        if ( matched[t] == 0 || dfs(matched[t])) { 
            matched[t] = k ; 
            return true; 
        }
    }
    return false;  
}

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 
    cin >> N >> M >> K ; 

    for (int i = 1, num_of_works = 0 ; i <= N; i++) { 
        cin >> num_of_works ; 

        for (int j = 0, num = 0 ; j < num_of_works; j++) { 
            cin >> num ; 
            V[i].push_back(num) ; 
        }
    }

    int answer = 0 ; 

    // 일단 일 하나씩 주고
    for (int i = 1 ; i <= N; i++) { 
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) answer++; 
    }

    int cnt = 0 ; 
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited)) ; 
        if (dfs(i)) { 
            cnt++; 
            answer++; 
            if ( cnt == K ) break ;
        }
    }
    cout << answer << '\n';

    return 0 ;
}