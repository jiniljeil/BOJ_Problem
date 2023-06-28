#include <iostream> 
#include <vector> 
#include <stack> 
#include <algorithm>
#define SIZE 10010
using namespace std ;

// Time complexity: O(V + E) 
int V, E;
vector<int> arr[SIZE] ; 
int d[SIZE], finished[SIZE], SCCN[SIZE];
stack<int> S ;
vector<vector<int>> SCC; 
int id, num ; 
int dfs(int curr) { 
    d[curr] = ++id; 
    S.push(curr) ; 

    int result = d[curr] ; 
    for (int i = 0 ; i < arr[curr].size(); i++) { 
        int next = arr[curr][i]; 
        // non-visited the next node 
        if ( d[next] == 0 ) result = min(result, dfs(next)) ; 

        // visited the next node
        else if (!finished[next]) result = min(result, d[next]) ; 
    }

    // cycle
    if ( result == d[curr] ) { 
        vector<int> group ; 
        while(1) { 
            int t = S.top() ; S.pop() ;
            group.push_back(t) ; 
            finished[t] = true ;
            SCCN[t] = num ; 
            if ( t == curr ) break ;
        }
        sort(group.begin(), group.end()) ; 
        SCC.push_back(group) ; 
        num++; 
    }
    return result ;
}
int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0); 
    
    cin >> V >> E ; 
    for (int i = 0, a,b ; i < E ; i++) { 
        cin >> a >> b ; 
        arr[a].push_back(b) ; 
    }

    for (int i = 1 ; i <= V ; i++) { 
        if ( d[i] == 0 ) dfs(i) ; 
    }
    
    sort(SCC.begin(), SCC.end()); 

    cout << SCC.size() << '\n'; 
    for (int i = 0 ; i < SCC.size(); i++) { 
        for (int j = 0 ; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << ' ' ;
        }
        cout << -1 << '\n';
    }
    return 0;
}