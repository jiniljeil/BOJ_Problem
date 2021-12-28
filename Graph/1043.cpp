/*
Algorithm : Union Find 
Counter Example: 
4 5
1 1
1 1
1 2
1 3
2 4 2
2 4 1
Result: 1
*/ 

#include <iostream> 
#include <vector> 
#define MAX 51 
using namespace std; 

int N, M; 
int num_of_true_persons; 
int num_of_persons; 
int num_of_conn_party ; 
int id[MAX] ; 
vector<int> true_id ; 
vector<vector<int> > party ; 
int root(int i) {
    while (i != id[i] ) i = id[i] ; 
    return i ; 
}

bool find_id(int p, int q)  {
    return root(p) == root(q) ; 
}

void union_find(int p, int q) { 
    int a = root(p) ; 
    int b = root(q) ; 
    if (a < b) id[b] = a ; 
    else id[a] = b; 
}


void InitandInput() { 
    cin >> N >> M ; 

    // Initialization 
    for(int i = 1 ; i < MAX ; i++) {
        if ( i >= 1 && i <= N) { 
            id[i] = i ; 
        } else { 
            id[i] = -1 ; 
        }
    }

    cin >> num_of_true_persons ; 
    
    for(int i = 0 ; i < num_of_true_persons; i++) {
        int k ; cin >> k ; 
        true_id.push_back(k) ;
    }

    for (int i = 1 ; i <= M ; i++) {
        cin >> num_of_persons ; 
        vector<int> echo_party ; 
        for(int j = 0 ; j < num_of_persons; j++) { 
            int person_id ; cin >> person_id ; 
            echo_party.push_back(person_id) ; 
        }
        party.push_back(echo_party) ;
    }
}

void Each_Connection() { 
    for (int i = 0 ; i < party.size(); i++) {
        for(int j = 0 ; j < party[i].size() - 1; j++) {
            union_find(party[i][j], party[i][j + 1]) ; 
        }
    }
}

void Num_of_Connected_Party() {
    for (int i = 0 ; i < party.size(); i++ ) {
        bool connection = false; 
        for(int j = 0; j < party[i].size(); j++) {
            for(int k = 0 ; k < true_id.size(); k++) {
                if (root(true_id[k]) == root(party[i][j])) { 
                    connection = true ; 
                    break; 
                }
            }
            if (connection) break; 
        }
        if (connection) num_of_conn_party++; 
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    
    InitandInput(); 
    Each_Connection(); 
    Num_of_Connected_Party(); 
    
    cout << M - num_of_conn_party << '\n';

    return 0;
}