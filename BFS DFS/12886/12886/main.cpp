#include <iostream>
#include <vector>
#include <algorithm>

// 10 15 35 (sum: 25, 60-(10+15) = 35)
// 12 24 33 (sum: 69, 69-(12+24) = 33)
using namespace std;
bool visit[1501][1501];
void checker(vector<int> box){
    if(visit[box[0]][box[1]]) return ;
    
    visit[box[0]][box[1]] = true;
    int sum = (box[0] + box[1] + box[2]);
    box[2] = sum - box[0] - box[1];
    
    for(int i = 0 ; i < 3; i++){
        for(int j = 0 ; j< 3; j++){
            if( box[i] < box[j]){
                box[i] = box[i] + box[i];
                box[j] = box[j] - box[i]/2;
                checker(box);
            }
        }
    }
}

int main(void){
    vector<int> box;
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    box.push_back(a);
    box.push_back(b);
    box.push_back(c);
    
    sort(box.begin(), box.end());
    
    if((a+b+c) % 3 == 0){
        checker(box);
        int sum = box[0] + box[1] + box[2];
        int result = visit[sum/3][sum/3] ? 1 : 0 ;
        cout << result << endl ;
    }else{
        cout << "0" << endl;
    }

    return 0;
}
