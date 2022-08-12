#include <iostream> 
#include <queue> 
typedef long long ll; 

using namespace std; 

int N, K; 
priority_queue<ll> p_pq ; 
priority_queue<ll, vector<ll>, greater<ll> > m_pq ; 

int main(void) { 
    ios::sync_with_stdio(false) ; cin.tie(0) ; 

    cin >> N ; 

    for (int i = 0 ; i < N; i++) {
        cin >> K ; 
        if ( K > 0 ) p_pq.push(K) ;
        else m_pq.push(K) ; 
    }
    long long answer = 0 ; 
    
    // Positive
    while (p_pq.size() > 1) { 
        int one = p_pq.top(); p_pq.pop() ; 
        int two = p_pq.top(); p_pq.pop() ; 

        if ( one == 1 || two == 1) { 
            answer += (one + two) ; 
        } else { 
            answer += (one * two) ; 
        }
    }

    if ( !p_pq.empty() ) { 
        answer += p_pq.top() ; p_pq.pop() ;
    }

    // Negative 

    while (m_pq.size() > 1) { 
        int one = m_pq.top(); m_pq.pop() ; 
        int two = m_pq.top(); m_pq.pop() ; 

        answer += (one * two) ; 
    }

    if ( !m_pq.empty() ) { 
        answer += m_pq.top() ; m_pq.pop() ;
    }

    cout << answer << '\n'; 
    return 0; 
}