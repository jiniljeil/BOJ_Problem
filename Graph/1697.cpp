#include <iostream>
#include <queue>

using namespace std;

int dx[3] = { -1, 1};
int map[100001];
bool visit[100001];

int main(void) {
    int n, k;
    queue<int> q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    map[n] = 1;
    visit[n] = true;
    q.push(n);
    
    while(!q.empty()){
        int x = q.front();
        dx[2] = x;
        q.pop();
        for(int i = 0 ; i < 3; i++){
            int dir_x = x + dx[i];
            if(dir_x >= 0 && dir_x <= 100000 && !visit[dir_x] && map[dir_x] == 0){
                visit[dir_x] = true;
                map[dir_x] = map[x] + 1;
                q.push(dir_x);
            }
        }
        
        if( x == k){
            break;
        }
    }

    cout << map[k]-1 << endl;
    return 0;
}
