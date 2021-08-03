#include <iostream>
#include <stdlib.h>
using namespace std; 

struct Node {
    char data; 
    Node *left; 
    Node *right; 
    Node(const char& _data) : data(_data), left(NULL), right(NULL) {}
};

typedef struct Node NODE; 

NODE* finder(NODE* node, char data) {
    if (node == NULL) return NULL ;
    if (node->data == data) {
        return node; 
    }else{
        Node* tmp = finder(node->left, data) ;
        if(tmp != NULL) return tmp; 
        return finder(node->right, data); 
    }
    return NULL; 
}

void preorder(NODE* root) {
    if(root == NULL) return ; 
    cout << root->data ; 
    if( root->left != NULL) preorder(root->left); 
    if( root->right != NULL) preorder(root->right); 
}

void inorder(NODE* root) {
    if(root == NULL) return ; 
    if( root->left != NULL) inorder(root->left); 
    cout << root->data ; 
    if( root->right != NULL) inorder(root->right); 
}

void postorder(NODE* root) {
    if(root == NULL) return ; 
    if( root->left != NULL) postorder(root->left); 
    if( root->right != NULL) postorder(root->right); 
    cout << root->data ; 
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    NODE* node = NULL; 
    NODE* tmp = NULL; 
    int N ; 
    char a, b, c; 
    cin >> N ; 
    for(int i = 0 ; i < N ; i++) {
        cin >> a >> b >> c ; 
        tmp = finder(node, a); 
        if( tmp == NULL) {
            node = new Node(a); 
            if (b != '.') {
                node->left = new Node(b) ; 
            }
            if (c != '.') {
                node->right = new Node(c) ;
            }
        }else{
            tmp->data = a; 
            if (b != '.') {
                tmp->left = new Node(b) ; 
            }
            if (c != '.') {
                tmp->right = new Node(c) ;
            }
        }
    }  
    preorder(node); cout << '\n'; 
    inorder(node); cout << '\n';
    postorder(node); cout << '\n';
    
    return 0; 
}