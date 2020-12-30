#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int num ;
    scanf("%d",&num);
    vector<pair<int,int>> t;
    
    for(int i = 0 ; i < num; i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        
        t.push_back(make_pair(t1, t2));
    }
    
    int time = t[0].second;
    
    if(t.size() < 1){
        return 0;
    }
    int store = 0 ;
    for(int i = 1 ; i < t.size(); i++){
        if(t[i-1].first > t[i].second){
            store += t[i-1].first - t[i].second;
        }else{
            if( t[i].second - store >= t[i-1].first ){
                t[i].second -= store;
                store = 0 ;
                time += (t[i].second - t[i-1].first);
            }else if(t[i-1].first > t[i].second - store){
                if( store >= t[i].second){
                    store -= t[i].second;
                    store += t[i-1].first;
                }else{
                    int tmp = store;
                    t[i].second -= store;
                    store -= tmp;
                    store += (t[i-1].first - t[i].second);
                }
            }else{
                time += abs(t[i].second - t[i-1].first);
            }
        }
    }
    
    printf("%d",time);
    return 0;
}
