#include <iostream> 
#include <vector>
#include <queue> 
#include <cmath>
using namespace std ;

int TC ; 
int num_of_store ; 
int main(void) {
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> TC ; 
    while ( TC-- ) { 
        pair<int, int> start, festival ; 
        vector<pair<int, int> > places ;  
        queue<pair<int, int> > Q ; 

        cin >> num_of_store ; 
        cin >> start.first >> start.second ; 
        for (int i = 0 ; i < num_of_store ; i++) { 
            pair<int, int> store ; 
            cin >> store.first >> store.second ;
            places.push_back(store) ; 
        }
        cin >> festival.first >> festival.second ; 
        places.push_back(festival) ; 

        Q.push(start) ; 

        bool flag = false; 
        while (!Q.empty()) { 
            pair<int, int> curr = Q.front() ;
            Q.pop() ; 

            if ( curr.first == festival.first && curr.second == festival.second ) { 
                cout << "happy" << '\n'; flag = true ; break ;
            }
            int size = places.size() ; 
            for (int i = 0 ; i < size ;) { 
                pair<int, int> p = places[i] ; 

                int nx = abs(curr.first - p.first) ; 
                int ny = abs(curr.second - p.second) ; 

                if ( (nx + ny) <= 1000 ) { 
                    Q.push(make_pair(p.first, p.second)) ; 
                    places.erase(places.begin() + i) ; 
                    size = places.size() ; 
                } else { 
                    i++; 
                }
            }
        }

        if ( !flag ) cout << "sad" << '\n'; 
    }   
    return 0 ;
}