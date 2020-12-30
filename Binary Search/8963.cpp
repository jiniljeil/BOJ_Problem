#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<int> gunSpot;

    int numGun, numAnimal, distance ;
    int result = 0 ;
    
    scanf("%d %d %d", &numGun, &numAnimal, &distance);
    
    for(int i = 0 ; i < numGun; i++){
        int t = 0 ;
        scanf("%d", &t);
        gunSpot.push_back(t);
    }
    sort(gunSpot.begin(), gunSpot.end());
    
    for(int i = 0 ; i < numAnimal; i++){
        int ax = 0,ay = 0;
        scanf("%d %d",&ax,&ay);
        
        if(ay > distance) continue ;
        int up = distance + ax -ay, down = ax + ay - distance ;
        int left = 0, right = gunSpot.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(down <= gunSpot[mid] && gunSpot[mid] <= up ){
                result++;
                break;
            }else if(gunSpot[mid] < down){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
