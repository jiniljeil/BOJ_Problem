#include <iostream>

using namespace std;

void power(int *arr, int s, int k, int num, int sum, int &count){
    if(k == num){
        return;
    }
    s += arr[k];
    if( s == sum){
        count = count + 1;
    }
    
    power(arr,s - arr[k],k+1,num,sum,count);
    power(arr,s,k+1,num,sum,count);
}

int main(){
    int num, sum;
    int count = 0 ;
    cin >> num >> sum;
    int *arr = new int[num];
    
    for(int i = 0 ; i < num; i++){
        int t = 0 ; scanf("%d",&t);
        arr[i] = t;
    }
    
    power(arr,0,0,num,sum,count);
    cout << count << endl;
    return 0;
}
