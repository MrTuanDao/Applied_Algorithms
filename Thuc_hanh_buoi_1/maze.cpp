#include <bits/stdc++.h>
using namespace std;
//Time: O(n*m), trường hợp tệ nhất ta phải check từng ô một trong maze
//Storage: 
//sử dụng bfs, với 1 hàng queue để chứa các tọa độ sau mỗi bước đi 

int maze[1000][1000];
int len[1000][1000];
int iterative_bfs(int n, int m,int r,int c){
    queue<int> toado_x;
    queue<int> toado_y;
    toado_x.push(r);
    toado_y.push(c);
    
    int action[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int size = 1;
    int move = 0;
    maze[r][c] = 1;
    while(!toado_x.empty()){
        move ++;
        int step = toado_x.size();
        for(int i = 0; i < step ; i++){
            int old_x = toado_x.front(); toado_x.pop();
            int old_y = toado_y.front(); toado_y.pop();

            for(int j = 0; j<4; j++){
                int new_x = old_x + action[j][0];
                int new_y = old_y + action[j][1];

                if(maze[new_x][new_y] == 0){
                    if(new_x <= 1 || new_x >= n || new_y <= 1 || new_y >= m){
                        return move + 1;
                    }
                    toado_x.push(new_x);
                    toado_y.push(new_y);
                    maze[new_x][new_y] = 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    // ios_base::sync_with_stdio(0); 
    // cin.tie(0);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int temp;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1; j <= m ; j ++){
            scanf("%d", &temp);
            maze[i][j] = temp;
            // cin >> maze[i][j];
        }
    }

    cout << iterative_bfs(n, m, r, c);
    return 0;
}
