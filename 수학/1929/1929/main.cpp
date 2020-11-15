#include <iostream>

using namespace std;

bool arr[1000001];

int main(void) {
    int f, s;
    scanf("%d %d",&f,&s);

    for(int i = 2; i <= s ;i++) arr[i] = true;

    for(int i = 2; i <= s; i++){
        if( !arr[i] ) continue;
        for(int j = 2 * i; j <= s; j += i){
            arr[j] = false;
        }
    }
    for(int i = f; i <= s; i++){
        if( arr[i] ) printf("%d\n",i);
    }
    return 0;
}
