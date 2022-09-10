#include <iostream> 
#include <vector> 
#include <queue> 
#include <cstring> 
#define MAX 1001 
using namespace std ;

int N, M ; 
vector<pair<int,int> > V[MAX] ; 
int a, b, c; 
bool visited[MAX] ; 

void BFS(int s, int d) { 
    queue<pair<int, int> > Q ; 
    Q.push(make_pair(s, 0)) ; 
    visited[s] = true ; 
    while (!Q.empty()) { 
        int curr = Q.front().first ; 
        int curr_d = Q.front().second ; 

        Q.pop() ; 

        if ( curr == d ) { 
            cout << curr_d << '\n' ; 
            break ; 
        }

        for (int i = 0 ; i < V[curr].size(); i++) { 
            int next = V[curr][i].first ; 
            int next_d = V[curr][i].second ; 

            if ( !visited[next] ) { 
                visited[next] = true ; 
                Q.push(make_pair(next, curr_d + next_d)) ; 
            }
        }
    }

}
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> M ; 

    for (int i = 0 ; i < N - 1 ; i++ ){ 
        cin >> a >> b >> c ; 
        V[a].push_back(make_pair(b, c)) ; 
        V[b].push_back(make_pair(a, c)) ; 
    }

    for (int i = 0 ; i < M ; i++) { 
        memset(visited, false, sizeof(visited)) ; 
        cin >> a >> b ; 
        BFS(a, b) ; 
    }
    return 0 ; 
}