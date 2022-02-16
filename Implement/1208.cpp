#include <iostream> 
#include <algorithm> 
#include <vector> 
#define MAX 41 
using namespace std; 

int N, S ; 
int arr[MAX] ; 
vector<int> A, B ; 
long long int result = 0; 

void num_of_subsetA(int sum, int k) { 
    if ( k >= N / 2) {
        return ; 
    }
    sum += arr[k] ; 
    if ( sum == S ) result++ ;

    A.push_back(sum) ; 
    num_of_subsetA(sum - arr[k], k + 1) ; 
    num_of_subsetA(sum, k + 1); 
}

void num_of_subsetB(int sum, int k) { 
    if ( k >= N ) {
        return ; 
    }
    sum += arr[k] ; 
    if ( sum == S ) result++ ;

    B.push_back(sum) ; 
    num_of_subsetB(sum - arr[k], k + 1) ; 
    num_of_subsetB(sum, k + 1); 
}

void subsetA_subsetB() { 
    sort(A.begin(), A.end()) ; 
    sort(B.begin(), B.end()) ; 

    // (S - 집합 A에서 나온 합)이 집합 B에 있는 경우 갯수 만큼 더해줌 
    for (int i = 0 ; i < A.size(); i++) { 
        int BS = S - A[i] ; 
        int low = lower_bound(B.begin(), B.end(), BS) - B.begin() ; 
        int high = upper_bound(B.begin(), B.end(), BS) - B.begin() ;  
        result += (high - low) ; 
    }
}

void Input() { 
    cin >> N >> S ; 
    
    for (int i = 0 ; i < N ; i++) { 
        cin >> arr[i] ;
    }
}


int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    Input(); 

    // 집합 A에서 S가 나올 경우 
    num_of_subsetA(0, 0) ; 
    // 집합 B에서 S가 나올 경우 
    num_of_subsetB(0, N/2) ;
    // 집합 A + 집합 B에서 S가 나올 경우 
    subsetA_subsetB() ; 
    
    cout << result << '\n';
    return 0 ;
}