#include <iostream> 
#include <stack>
using namespace std; 
long long int N, V, C; 
long long int arr[80001]; 
stack<int> s ; 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int top = 0 ;
    cin >> N;
    for(int i= 0; i < N; i++){
        cin >> arr[i]; 
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        s.push(arr[i]); 
        C = C + s.size() - 1; // 자기 자신은 제외 
    }
    cout << C << "\n";
    return 0 ;
}