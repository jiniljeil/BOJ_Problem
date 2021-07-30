#include <iostream> 
#include <algorithm> 
#define MAX 1001
using namespace std; 

int preorder[MAX]; 
int inorder[MAX]; 
int N_NODE ; 

void postOrder(int start, int end, int root) {
    for(int i = start ; i < end; i++) {
        if(preorder[root] == inorder[i]) {
            postOrder(start, i, root + 1); // 왼쪽 서브 트리 
            postOrder(i + 1, end, root + 1 + i - start); // 오른쪽 서브 트리 
            cout << preorder[root] << ' '; 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0) ;

    int testcase ;   
    cin >> testcase; 
    for(int i = 0 ; i < testcase; i++) {
        cin >> N_NODE; 
        for(int j = 0 ; j < N_NODE; j++) {
            cin >> preorder[j]; 
        }
        for(int j = 0 ; j < N_NODE; j++) {
            cin >> inorder[j]; 
        }
        postOrder(0, N_NODE, 0);
        cout << '\n';
    }
    return 0; 
}
