#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    set<int> s ;
    
    for(int i = 0 ; i < n; i++){
        int t = 0 ;
        scanf("%d", &t);
        s.insert(t);
    }
    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        printf("%d ",*iter);
    }
    
    return 0;
}
