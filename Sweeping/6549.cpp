#include <iostream>
#include <stack> 
#include <vector> 
using namespace std; 

vector<long long> V ;

void solve() { 
    stack<long long> remain ;
    V.push_back(0); // 맨 오른쪽 높이 0 추가 
    unsigned long long ret = 0; 
    for(int i = 0 ; i < V.size(); i++) {
        while(!remain.empty() && V[remain.top()] >= V[i]) {
            int j = remain.top(); 
            remain.pop(); 
            int width = -1; 

            if(remain.empty()) {
                width = i ; 
            }else{
                width = (i - remain.top() - 1); 
            }
            if(ret < V[j] * width) {
                ret = V[j] * width; 
            }
        }
        remain.push(i); 
    }

    cout << ret << '\n'; 
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    int num, t; 

    do{
        cin >> num; 
        if(num != 0) {
            for(int i = 0; i < num; i++) {
                cin >> t ;
                V.push_back(t); 
            }
            solve(); 
            V.clear();
        }
    }while(num != 0);

    
    return 0; 
}