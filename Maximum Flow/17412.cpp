#include <iostream>
#include <queue> 
#include <vector> 
#include <ctype.h>
#include <string.h> 
#define MAX 402 
#define INF 1e8 
using namespace std ;

int capacity[MAX][MAX], flow[MAX][MAX] ; 
int Start, End; 
int capacity_pipe, n, e; 

int networkFlow(int source, int destination) {
    memset(flow, 0, sizeof(flow)); 
    int totalFlow = 0 ; 
    int amount = INF ;
    while(1) { 
        vector<int> parent(MAX,-1); 
        queue<int> q; 
        parent[source] = source ; 
        q.push(source); 

        while(!q.empty() && parent[destination] == -1) {
            int here = q.front(); q.pop(); 
            for (int there = 0 ; there < MAX ; there++) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there); 
                    parent[there] = here; 
                }
            }
        }
        if (parent[destination] == -1) break; 
        amount = INF ; 
        for(int p = destination; p != source ; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]); 
        }

        for(int p = destination; p != source ; p = parent[p]) { 
            flow[parent[p]][p] += amount ; 
            flow[p][parent[p]] -= amount ; 
        }
        totalFlow += amount ; 
    }
    return totalFlow ; 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> n >> e; 
    
    for (int i = 0 ; i < e; i++) {
        cin >> Start >> End ; 

        capacity[Start][End] += 1; 
    }
    
    cout << networkFlow(1, 2) << '\n'; 
    return 0; 
}