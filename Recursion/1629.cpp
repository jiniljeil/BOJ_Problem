#include <iostream>

using namespace std; 

// 2^8 = 2^4 * 2^4 = 2^2 * 2^2 * 2^2 * 2^2
// 2^7 = 2^3 * 2^3 * 2^1
long long func(int num, int exponent, int c) {
    if( exponent == 0 ) return 1; 
    long long n = func(num, exponent/2, c);
    if( exponent % 2 == 0) { // 지수 짝수 
        return n * n % c; 
    }else{ // 지수 홀수
        return num * (n * n % c) % c;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,c; 
    cin >> a >> b >> c; 

    long long result = func(a,b,c);
    cout << result << '\n';
    return 0;
}