#include <iostream>

using namespace std ;
int N, M ;
int arr[1030][1030]; 
int sum[1030][1030]; 
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    cin >> N >> M ; 

    for(int i = 1 ; i <= N ; i++) { 
        for(int j = 1 ; j <= N ;j++) {
            cin >> arr[i][j]; 
            sum[i][j+1] = sum[i][j] + arr[i][j];
        }
    }

    int result = 0; 
    pair< pair<int,int>, pair<int, int> > range;  
    for(int i = 0 ; i < M ;i++ ){
        result = 0 ;
        cin >> range.first.first >> range.first.second >> range.second.first >> range.second.second; 
        
        for(int j = range.first.first; j <= range.second.first ; j++) {
            result += (sum[j][range.second.second + 1] - sum[j][range.first.second]);
        }
        cout << result << '\n';
    }
    return 0;
}