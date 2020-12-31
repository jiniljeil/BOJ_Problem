#include <iostream>
#include <string> 
using namespace std;

int arr[64][64]; 
string result; 

void func(int a, int b, int N){
    bool check = true; 
    int value = arr[a][b]; 
    for(int i = a ; i < a+N; i++){
        for(int j = b; j < b+N ; j++){
            if( arr[i][j] != value){
                check = false ;
                result += "("; 
                func(a, b, N/2);
                func(a, b + N/2, N/2);  
                func(a + N/2, b, N/2);
                func(a + N/2, b + N/2, N/2); 
                result += ")"; 
                break; 
            }
        }
        if( !check ) break; 
    }
    if( check ){
        result += to_string(value);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; 
    cin >> N; 

    for(int i = 0 ; i < N; i++){
        string str; 
        cin >> str; 
        for(int j = 0 ; j < N; j++){
            arr[i][j] =str[j] - '0';
        }
    }
    
    func(0,0, N); 
    cout << result << "\n";
    return 0; 
}