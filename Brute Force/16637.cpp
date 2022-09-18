#include <iostream> 
#include <vector> 
#include <string> 
#include <climits>

typedef long long ll ;
using namespace std; 

int N ; 
ll answer = INT_MIN ; 
int num_of_operations = 0 ; 
vector<int> numbers ; 
vector<char> operations ; 

ll calculate(char operation, ll n1, ll n2) { 
    if ( operation == '+' ) return n1 + n2 ; 
    else if ( operation == '-' ) return n1 - n2 ; 
    else if ( operation == '*' ) return n1 * n2 ; 
    return 0 ;
}   

void func(ll num, int idx) { 
    if ( idx == num_of_operations ) { 
        answer = max(answer, num) ; 
        return ; 
    }
    ll next_num = 0; 
    next_num = calculate(operations[idx], num, numbers[idx + 1]) ; 
    func(next_num, idx + 1) ; 

    if ( idx + 2 > num_of_operations ) return ; 
    next_num = calculate(operations[idx], num, calculate(operations[idx + 1], numbers[idx + 1], numbers[idx + 2])) ; 
    func(next_num, idx + 2) ; 
}

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ;
    cin >> N ; 

    char c ; 
    for (int i = 0 ; i < N ; i++) { 
        cin >> c ; 
        if ( i % 2 == 0 ) numbers.push_back(c - '0') ; 
        else operations.push_back(c) ; 
    }

    num_of_operations = operations.size() ; 

    func(numbers[0], 0) ;

    cout << answer << '\n'; 
    return 0 ;
}