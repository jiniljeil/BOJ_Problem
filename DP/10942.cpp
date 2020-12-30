#include <iostream>

using namespace std;

int arr[2001];
int answer[1000001];
int main(void) {
    int n,n2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> n2;
    for(int i = 0 ; i < n2; i++){
        int p1, p2;
        cin >> p1 >> p2;
        int size = (p1+p2)/2;
        bool check = true;
        for(int j = p1; j <= size; j++){
//            cout << arr[j] << " " << arr[p2-j];
            if( arr[j] != arr[p2-j+1]){
                check = false;
                break;
            }
        }
//        cout << endl;
        if(check){
            cout << "1" << "\n";
        }else{
            cout << "0" << "\n";
        }
    }
    
    
    return 0;
}
