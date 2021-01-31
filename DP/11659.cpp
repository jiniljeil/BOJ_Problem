#include <iostream>

using namespace std; 

int N, M ; 
int arr[100001];
int sum[100001];
pair<int,int> range[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    for(int i = 0; i < N ;i++) {
        cin >> arr[i]; 
        sum[i+1] = sum[i] + arr[i];
    }

    for(int i = 0 ; i < M ; i++) {
        cin >> range[i].first >> range[i].second; 
        cout << sum[range[i].second] - sum[range[i].first - 1] << '\n';
    }

    return 0;
}