#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count (vector<int> first, vector<int> second);

/*
 5
 1 1 1 6 0
 2 7 8 3 1
 */
int main(void){
    int num = 0 ;
    cin >> num;
    
    vector < int > first (num , 0);
    vector < int > second (num , 0);
    
    for(int i = 0 ; i < num; i++){
        cin >> first[i];
    }
    for(int i = 0 ; i < num; i++){
        cin >> second[i];
    }
    int value = count (first, second);
    cout << value << endl;
    return 0;
}

int count (vector<int> first, vector<int> second){
    int c = 0 ;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());

    for(int i = 0 ; i < first.size(); i++){
        c += first[i] * second[i];
    }
    return c ;
}
