#include <iostream> 

using namespace std; 

int origin[5][5], cal[5][5], curr[5][5], n ; 

void func(unsigned long long x) { 
	if ( x != 1 ) { 
		func( x / 2) ; 

		for (int i = 0 ; i < n ; i++) { 
			for(int j = 0 ; j < n ; j++) { 
				cal[i][j] = 0 ; 

				for(int k = 0 ; k < n; k++) { 
					cal[i][j] += (curr[i][k] * curr[k][j]) ;
				}

				cal[i][j] %= 1000; 
			}
		}
		
		for (int i = 0; i < n; i++) { 
			for (int j = 0 ;j < n ; j++) { 
				curr[i][j] = cal[i][j]; 
			}
		}

		if ( x % 2 != 0 ) {
			for (int i = 0 ; i < n ; i++) { 
				for(int j = 0 ; j < n ; j++) { 
					cal[i][j] = 0 ; 

					for(int k = 0 ; k < n; k++) { 
						cal[i][j] += (curr[i][k] * origin[k][j]) ;
					}

					cal[i][j] %= 1000; 
				}
			}
			
			for (int i = 0; i < n; i++) { 
				for (int j = 0 ;j < n ; j++) { 
					curr[i][j] = cal[i][j]; 
				}
			}
		}
	}else { 
		for (int i = 0 ; i < n ; i++) { 
			for (int j = 0 ; j < n ; j++) { 
				curr[i][j] = origin[i][j] % 1000 ; 
			}	
		}
	}
}

void Input() { 
	for(int i = 0 ; i < n ; i++) { 
		for(int j = 0 ; j < n; j++) { 
			cin >> origin[i][j]; 
		}
	}
}

void Result() { 
	for(int i = 0 ; i < n ; i++) { 
		for(int j = 0 ; j < n; j++) { 
			cout << curr[i][j] << ' ' ; 
		}
		cout << '\n';  
	}
}

int main(void)  {
	ios::sync_with_stdio(false) ;
	cin.tie(0);  cout.tie(0) ; 

	unsigned long long b ;
	cin >> n >> b;  

	Input();  	
	func(b) ; 
	Result(); 

	return 0; 
}	
