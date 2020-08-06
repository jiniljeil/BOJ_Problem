#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    int n = 0 ;
    scanf("%d",&n);
    vector<int> count ;
    vector<string> str_arr ;
    for(int i = 0; i < n; i++){
        int t = 0 ;
        string str ;
        scanf("%d",&t);
        cin >> str;
        count.push_back(t);
        str_arr.push_back(str);
    }
    
    for(int i = 0 ; i < count.size(); i++){
        int k = count[i];
        
        for(int z = 0 ; z < str_arr[i].size(); z++ ){
            for(int p = 0 ; p < k ; p++){
                printf("%c",str_arr[i][z]);
            }
        }
        printf("\n");
    }
    
    
    return 0;
}
