#include <iostream> 
#include <vector> 
using namespace std ; 

int main(void){
    int n, num, count =0 ; 
    cin >> n ; 
    vector<int> v ;
    int t; 
    for(int i = 0 ; i < n; i++){
        cin >> t ; 
        v.push_back(t); 
    }
    cin >> num; 

    for(int i = 0 ; i < v.size(); i++) {
        if( v[i] == num) count++;
    }
    cout << count << "\n";
    return 0;
}