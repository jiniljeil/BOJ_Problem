#include <iostream>
#include <queue> 
#include <vector> 
#include <ctype.h>
#include <string.h> 
#define MAX 702 
#define INF 1e8 
using namespace std ;

int capacity[MAX][MAX], flow[MAX][MAX] ; 
char Start, End; 
int capacity_pipe, n; 

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

    cin >> n ; 
    
    for (int i = 0 ; i < n; i++) {
        cin >> Start >> End >> capacity_pipe ; 

        capacity[Start - 'A'][End - 'A'] += capacity_pipe; 
        capacity[End - 'A'][Start - 'A'] += capacity_pipe; 
    }
    
    cout << networkFlow(0, 25) << '\n'; 
    return 0; 
}