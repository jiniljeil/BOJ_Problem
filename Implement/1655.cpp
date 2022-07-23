#include <iostream> 
#include <queue> 
using namespace std ;

int N; 
priority_queue<int> maxheap ; 
priority_queue<int, vector<int>, greater<int> > minheap ; 

void max_to_min(int tmp) { 
    minheap.push(maxheap.top()) ; 
    maxheap.pop() ; 
    maxheap.push(tmp) ; 
}

void min_to_max(int tmp) { 
    maxheap.push(minheap.top()) ; 
    minheap.pop() ; 
    minheap.push(tmp) ; 
}

int main(void) { 
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; 

    int tmp ;

    cin >> N ; 

    for (int i = 0 ; i < N; i++) { 
        cin >> tmp ; 
        
        if ( maxheap.size() == 0 ) { 
            maxheap.push(tmp) ; 
        } else if ( minheap.size() == 0 ) { 
            if ( maxheap.top() > tmp ) max_to_min(tmp) ; 
            else minheap.push(tmp) ; 
        } else if ( maxheap.size() > minheap.size() ) { 
            if ( maxheap.top() > tmp ) max_to_min(tmp) ; 
            else minheap.push(tmp) ;
        } else if ( maxheap.size() < minheap.size() ) { 
            if ( minheap.top() > tmp ) maxheap.push(tmp) ;
            else min_to_max(tmp);  
        } else { 
            if ( minheap.top() > tmp ) maxheap.push(tmp) ; 
            else min_to_max(tmp); 
        }

        cout << maxheap.top() << '\n' ; 
    }

    return 0; 
}