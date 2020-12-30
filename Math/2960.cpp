#include <iostream>
#include <vector>

using namespace std;

bool sosu(int value){
    
    if(value == 2) return true;
    
    for(int i = 2; i < value; i++){
        if(value%i == 0) return false;
    }
    
    return true;
}

int main(void){
    int num, k ;
    vector<int> box;
    vector<int> result ;
    
    scanf("%d %d",&num,&k);
    
    for(int i = 0 ; i <= num; i++){
        box.push_back(i);
    }
    
    for(int i = 2; i < box.size(); i++){
        if(box[i] > 0 && sosu(box[i])){
            int t = box[i];
            for(int j = t; j < box.size(); j += t){
                if(box[j] > 0){
                    result.push_back(box[j]);
                    box[j] = 0;
                }
            }
        }
    }
    cout << result[k-1] << endl;
    return 0;
}
