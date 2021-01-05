#include <iostream>
#include <vector> 
using namespace std;

int person, limit ;
vector<int> v[7]; 
int gender, grade ; // 0 : 여자, 1: 남자 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> person >> limit; 

    for(int i = 0 ; i< person; i++) {
        cin >> gender >> grade ; 
        v[grade].push_back(gender); 
    }
    int result = 0 ;
    for(int i = 1 ; i <= 6; i++){
        int zeroC = 0 , oneC = 0 ; 
        for(int j = 0 ; j < v[i].size(); j++){
            if(v[i][j] == 0){
                zeroC++;
            }else if(v[i][j] == 1){
                oneC++; 
            }
        }
        if( zeroC != 0 ){
            result += zeroC/limit; 
            if(zeroC % limit > 0) {
                result++;
            }
        }
        if( oneC != 0 ){
            result += oneC/limit; 
            if(oneC % limit > 0) {
                result++;
            }
        }
    }
    cout << result << "\n";
    return 0;
}