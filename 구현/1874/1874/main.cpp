#include <iostream>
#include <stack>

using namespace std;

int arr[100001];

int main(void) {
    int n;
    stack<int> s;
    string str = "";
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ;i++){
        int t = 0;
        scanf("%d",&t);
        arr[i] = t ;
    }
    int plus = 0;
    int j = 0 ;
    bool check = false;
    
    while( j < n ){
        int k = arr[j];
        if( !s.empty() && (s.top() == k)){
            j++;
            s.pop();
            str += "-";
        }else{
            if( plus > k){
                check = true;
                break;
            }else{
                s.push(++plus);
                str += "+";
            }
        }
    }
    
    if(plus != n || check ){
        printf("NO\n");
    }else{
        for(int i = 0 ; i < str.length(); i++){
            printf("%c\n",str[i]);
        }
    }
    
    return 0;
}
