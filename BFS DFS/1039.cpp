#include <iostream> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <set> 
using namespace std ; 

string N;  
int K, M;

void BFS() { 
    queue<string> Q ; 
    int curr_K = 0; 
    int max_v = 0 ; 
    Q.push(N) ; 
    
    while(!Q.empty() && curr_K < K )  {
        set<string> visited ; 
        int Qs = Q.size() ; 

        for (int q = 0 ; q < Qs; q++) { 
            string curr = Q.front() ; 
            Q.pop() ; 

            for (int i = 0 ; i < M - 1 ; i++ ) {
                for (int j = i + 1 ; j < M ; j++) {
                    // 맨 앞에 0이 오게 될 경우 continue  
                    if ( i == 0 && curr[j] == '0') continue ; 

                    swap(curr[i], curr[j]) ;
                    // S에 curr가 존재하지 않을 경우
                    if ( visited.find(curr) == visited.end() )  {
                        // MAX 값 찾기
                        if ( curr_K == K - 1 && max_v < stoi(curr)) { 
                            max_v = stoi(curr) ;
                        }
                        Q.push(curr) ; 
                        visited.insert(curr) ; 
                    }
                    swap(curr[i], curr[j]) ; 
                }
            }
        }
        curr_K++; 
    }
    if ( curr_K != K ) cout << "-1" << '\n' ; 
    else cout << max_v << '\n' ; 
}

int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    cin >> N >> K ;  

    M = N.length(); 

    // 한 자리수 또는 두 자리수이면서 맨 마지막 값이 0인 경우
    if ( M == 1 || (M == 2 && stoi(N) % 10 == 0) )  {
        cout << "-1" << '\n' ; 
        return 0 ; 
    }

    BFS() ; 
    return 0 ;
}