#include <iostream> 
#include <vector> 
#include <climits>
#include <algorithm>
#define L long long int
using namespace std; 

vector<long long> v; 
L n, d; 
L min_long = LONG_LONG_MAX, max_long = LONG_LONG_MIN; 
L mid ;
vector <long double> tmparr;
long double f(){
    tmparr.resize(n);

    int k = 0 ; 
    for(int i = n/2 ; i >=0 ; i--) {
        tmparr[i] = (mid - k * d)-v[i] ;
        k++;
    }
    k=1;
    for(int i = n/2+1 ; i <n ; i++) {
        tmparr[i] = (mid + k * d)-v[i] ;
        k++;
    }
    long double max_d = LONG_MIN; 
    long double min_d = LONG_MAX; 

    for (int i = 0 ; i < n ; i++) {
        max_d = max(max_d, tmparr[i]) ;
        min_d = min(min_d, tmparr[i]) ; 
    }

    return abs((max_d - min_d)/2);
}

int main(void ) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> n >> d ; 
    L input ;
    for (int i = 0 ; i < n ; i++) {
        cin >> input ; 
        v.push_back(input) ;  
        max_long = max(max_long, input); 
        min_long = min(min_long, input); 
    }

    mid = (max_long + min_long) / 2 ;
    printf("%.1Lf\n", f()) ;

    return 0;
}