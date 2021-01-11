#include <iostream>
#include <algorithm> 
#include <string> 
#include <vector> 

using namespace std ; 

bool visited[15];
int L, C ; 

bool check(string &output) { 
    int mo = 0 , ja = 0; 
    for(int i = 0 ; i < L; i++) {
        if( output[i] == 'a' || output[i] == 'e' || output[i] == 'i' || output[i] == 'o' || output[i] == 'u') {
            mo++;
        }else{
            ja++;  
        }
        if(mo >= 1 && ja >= 2) break;
    }
    return (mo >= 1 && ja >= 2) ;
}

void func(int k, string output, vector<char>& arr) {
    if( output.length() == L && check(output)) { 
        cout << output << "\n";
        return ;
    }
    if( k >= arr.size()) return;
    func(k + 1, output + arr[k], arr); 
    func(k + 1, output, arr);
}
int main(void){
    ios::sync_with_stdio(0) ;
    cin.tie(0); cout.tie(0) ;
    
    cin >> L >> C ;
    vector<char> arr(C); 
    
    for(int i = 0 ; i < C ; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()) ;
    string output = "";
    func(0, output, arr) ;
    return 0;
}