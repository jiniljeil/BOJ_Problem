#include <iostream> 
#include <vector> 
#define MAX 105
using namespace std ; 

typedef struct robot { 
    int r, c, d ; 
    robot (int r, int c, int d) {
        this->r = r ; this->c = c ; this->d = d ; 
    }
} Robot ; 

typedef struct command { 
    int robot, loop; 
    char c ; 
    command(int robot, char c, int loop) {
        this->robot = robot ; this->c = c ; this->loop = loop ; 
    }
} Cmd ; 
int A, B; 
int N, M; 
int MAP[MAX][MAX]; 

vector<Robot> V ; 
vector<Cmd> C ;  

int dx[4] = { 0, 1, 0,-1} ;
int dy[4] = {-1, 0, 1, 0} ; 
int direction_to_int(char c) { 
    if ( c == 'N' ) return 1;  
    else if ( c == 'E') return 2 ; 
    else if ( c == 'S') return 3 ; 
    else return 0; 
}

void Input() { 
    cin >> A >> B ; 

    cin >> N >> M ; 

    V.push_back(Robot(0, 0, 0)) ; 
    for (int i = 1; i <= N ; i++) { 
        int r, c ; char d ;   
        cin >> r >> c >> d ; 

        int direction = direction_to_int(d) ;
        V.push_back(Robot(r, c, direction)) ; 
        MAP[r][c] = i; 
    }

    for (int i = 0 ; i < M; i++) { 
        int robot, loop ; char command ; 
        cin >> robot >> command >> loop ; 
        C.push_back(Cmd(robot, command, loop)) ; 
    }
}

int main(void)  {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    Input(); 

    for (int i = 0 ; i < C.size(); i++) { 
        Cmd cmd = C[i] ; 

        int row = V[cmd.robot].r ; 
        int col = V[cmd.robot].c ; 
        int dir = V[cmd.robot].d ; 

        while (cmd.loop--) { 
            if ( cmd.c == 'L') { dir = (dir + 3) % 4 ; V[cmd.robot].d = dir ; }
            else if ( cmd.c == 'R') { dir = (dir + 1) % 4 ; V[cmd.robot].d = dir ;} 
            else if ( cmd.c == 'F') { 
                MAP[row][col] = 0 ; 

                row = row + dy[dir] ; 
                col = col + dx[dir] ; 

                if ( row < 1 || row > A || col < 1 || col > B ) { 
                    cout << "Robot " << cmd.robot << " crashes into the wall" << '\n'; 
                    return 0 ; 
                } 
                else if ( MAP[row][col] != 0 ) { 
                    cout << "Robot " << cmd.robot << " crashes into robot " << MAP[row][col] << '\n' ;
                    return 0 ;
                } 
                else { V[cmd.robot].r = row ; V[cmd.robot].c = col; MAP[row][col] = cmd.robot ; } 
            }
        }
    }

    cout << "OK" << '\n'; 
    return 0 ;
}