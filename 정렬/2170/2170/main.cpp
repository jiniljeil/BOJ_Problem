#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) {
    pair<int,int> line[1000001];
    int num = 0;
    int length = 0;
    
    scanf("%d",&num);
    
    for(int i = 0 ; i < num; i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        line[i].first = t1;
        line[i].second = t2;
    }
    sort(line, line + num);
    
    int left = -1e9, right = -1e9;
    
    for(int i = 0 ; i < num; i++){
        if(line[i].first < right) {
            right = max(right, line[i].second);
        }else{
            length += (right - left);
            left = line[i].first;
            right = line[i].second;
        }
    }
    
    length += (right - left);
    cout << length << endl;
    return 0;
}
