#include <iostream> 

using namespace std ;
int arr[10];
int main(void) {
    long long n1,n2,n3; 
     
    cin >> n1 >> n2 >> n3; 

    long long r = n1 * n2 * n3; 
    string str = to_string(r); 
    
    for(int i = 0 ; i < str.length(); i++){
        arr[str[i] - 48] += 1;
    }
    for(int i = 0 ; i < 10; i++){
        cout << arr[i] << "\n";
    }

    return 0 ;
}