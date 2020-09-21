#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int num, th;
    queue<int> queue ;
    scanf("%d %d", &num, &th);
    
    for(int i = 1 ; i <= num; i++ ){
        queue.push(i);
    }
    
    cout << "<";
    
    while(num--){
        for(int i = 1; i < th; i++){
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front();
        queue.pop();
        if( num != 0){
            cout <<", ";
        }
    }
    cout << ">" ;
    return 0;
}
