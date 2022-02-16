#include <iostream>
#define MAX 100001

using namespace std; 

int N ; 
int inorder[MAX] ; 
int postorder[MAX] ; 
int inorder_idx[MAX] ; 

void Preorder(int post_start, int post_end, int in_start, int in_end) { 
    
    if ( post_start > post_end || in_start > in_end ) return ;

    int idx = inorder_idx[postorder[post_end]] ;
    cout << postorder[post_end] << ' ' ; 
    
    Preorder(post_start, post_start + idx - 1 - in_start, in_start, idx - 1) ; 
    Preorder(post_end - in_end + idx, post_end - 1, idx + 1, in_end) ; 
}

void Input() { 
    cin >> N ; 

    // Inorder Input
    for (int i = 0 ; i < N; i++) {
        cin >> inorder[i] ; 
        inorder_idx[inorder[i]] = i ; 
    }

    // Postorder Input
    for (int i = 0 ; i < N; i++) {
        cin >> postorder[i] ; 
    }
}

int main(void) { 
    ios::sync_with_stdio(false); 
    cin.tie(0) ; 

    Input() ; 
    Preorder(0, N - 1, 0, N - 1) ;
    return 0 ;
}