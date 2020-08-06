#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

void removeNode(vector<int>& tree, int size, int remove){
    tree[remove] = -2;
    int remove1 = remove ;
    int remove2 = remove ;
    
    for(int i = 0 ; i< size;i++){
        cout<< tree[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        if(remove*2 +1 < size){
            tree[remove1*2+1] = -2;
            remove1 = remove1 * 2 + 1;
        }
        if(remove*2 + 2 < size){
            tree[remove2*2+2] = -2;
            remove2 = remove2 * 2 + 2;
        }
    }
    
    for(int i = 0 ; i< size;i++){
        cout<< tree[i] << " ";
    }
}

int leafNode(vector<int>& tree, int size, int remove){
    int count =0;
    removeNode(tree,size,remove);
    for(int i = size-1; i > 0; i--){
        if(tree[i] >= -1){
//            cout << i << endl;
            count++;
            if(i%2 != 0){
               tree[(i-1)/2] = -2;
            }else{
               tree[(i-2)/2] = -2;
            }
        }
    }
    if(count == 0){
        return 1;
    }
    return count;
}

int main(void){
    int n = 0 ;
    int size = 0 ;
    scanf("%d",&n);
    
    for(int i = 0 ;; i++){
        if(pow(2,i) >= n){
            size = pow(2,i);
            break;
        }
    }
    
    vector<int> tree (size, -2);
    
    for(int i = 0 ; i < n ;i++){
        int tmp = 0 ;
        scanf("%d", &tmp);
        if(tmp == -1){
            tree[0] = -1;
        }else{
            if(tree[2*tmp+1] != tmp){
                tree[2*tmp+1] = tmp;
            }else{
                tree[2*tmp+2] = tmp;
            }
        }
    }
    
//    for(int i = 0 ; i < size ; i++){
//        cout << tree[i] << " ";
//    }
    
    int remove = 0;
    scanf("%d", &remove);
    
    int count = leafNode(tree, size, remove);
    cout << count;
    return 0;
}
