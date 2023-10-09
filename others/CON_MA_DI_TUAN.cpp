#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
pair <int, int> a[MAXN * MAXN];
bool visited[MAXN][MAXN];
int n, r, c;
bool is_found = false;
int dx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dy[] = {-2, -1,  1,  2, 2, 1, -1, -2};

void print_sol(){
    for(int j = 1; j <= n * n; j++){
        cout << a[j].first << ", " << a[j].second << endl;
    }
    cout << endl;
    is_found = true;
}

void TRY(int k){
    
        for(int i = 0; i<8; i++){
            int x = a[k-1].first + dx[i];
            int y = a[k-1].second + dy[i];
            if( !is_found && 1 <= x && x <= n && 1 <= y && y <= n && !visited[x][y]){
                a[k] = make_pair(x, y);
                visited[x][y] = true;
                
                if (k == n * n) print_sol();
                else TRY(k + 1);
                
                visited[x][y] = false;
            }
        }
    
}

int main(){
    cin >> n >> c >> r;
    a[1] = make_pair(r, c);
    visited[c][r] = true;
    TRY(2);
    return 0;
}
