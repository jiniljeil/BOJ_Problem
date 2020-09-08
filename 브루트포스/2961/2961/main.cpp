#include <iostream>
#include <vector>
using namespace std;

int num;
bool *visit;

void result (vector<int> t, vector<int> bitter, vector<int> sour,long long int &min){
    if( t.size() == 0 ){
        return ;
    }
    
//    cout << "index: " ;
//    for(int i = 0 ; i < t.size(); i++){
//        cout << t[i] << " ";
//    }
    
    int bs = 0 , ss = 1;
    for(int i = 0 ; i < t.size(); i++){
        bs += bitter[t[i]];
        ss *= sour[t[i]];
    }
    int res = abs(bs - ss);
//    cout << "RESULT: " << res << endl;
    if(res < min){
        min = res;
    }
}

void tmp(vector<int> bitter, vector<int> sour, long long int &min){
    vector<int> t ;
    for(int i = 0 ; i < bitter.size(); i++){
        if(visit[i]){
            t.push_back(i);
        }
    }
    
    result(t,bitter,sour,min);
}

void getSet(vector<int> bitter, vector<int> sour, int index, long long int &min){
    if(index == num){
        // 배열 전체
        tmp(bitter,sour, min);
        return;
    }
    visit[index] = false;
    getSet(bitter, sour, index+1, min);
    
    visit[index] = true;
    getSet(bitter, sour, index+1, min);
    
}
int main(void){
    vector<int> bitter, sour ; // 쓴맛, 신맛
    vector<int> result;
    scanf("%d",&num);
    visit = new bool[num];
    
    for(int i = 0 ; i < num; i++){
        int t1, t2;
        scanf("%d %d",&t1,&t2);
        sour.push_back(t1);
        bitter.push_back(t2);
    }
    
    long long int min = 99999999;
    getSet(bitter, sour, 0, min);
    
    cout << min << endl;
    return 0;
}
