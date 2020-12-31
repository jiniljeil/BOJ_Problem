#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm> 

using namespace std;
int N, K; 
vector<string> v ; 

bool compare(const string a, const string b){
    if (a + b > b + a ) return true ;
    else return false; 
}
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    
    string str, tmp ;
    cin >> K >> N; 
    for(int i = 0 ; i < K ; i++) { 
        cin >> tmp; 
        if( str.size() == tmp.size()){
            if( str < tmp ){ 
                str = tmp ; 
            }
        }else{
            if(str.size() < tmp.size()){
                str = tmp ; 
            }
        }
        v.push_back(tmp); 
    }

    int add = N - K ; 
    for(int i = 0 ; i < add; i++) v.push_back(str); 

    for(int i = 0 ; i < v.size(); i++){
        sort(v.begin(), v.end(), compare); 
    }

    for(int i = 0 ; i < v.size(); i++) cout << v[i] ;

    return 0;
}