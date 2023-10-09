/* check TSP with Precedence Constraint
Dao Quoc Tuan 20210891
Tại đầu mỗi lặp kiểm tra phần tử, ta kiểm tra xem tất cả những precedence của nó đã đi qua chưa, nếu rồi
Cập nhật quãng đường và gán đã đi qua nó
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10, MAXM = 1e6 + 10;
int n, m;
int totalMove = 0;
int dis_matrix[MAXN][MAXN];
int predict[MAXN], visited[MAXN];
vector <int> precedence[MAXN];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> predict[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> dis_matrix[i][j];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        // cout << endl;
        precedence[y].push_back(x);
    }
}

bool goodToGo(int i){ 
    for(auto it = precedence[i].begin(); it != precedence[i].end(); it++){
        if (visited[*it] == 0) return false;
    }
    return true;
}

int main(){
    input();
    int lastmove = 0;
    for(int i = 1; i <= n; i++){
        int curmove = predict[i];
        if(!goodToGo(curmove)){
            cout << "-1";
            return 0;
        }
        if (lastmove != 0)
            totalMove += dis_matrix[lastmove][curmove];
        lastmove = curmove;
        visited[curmove] = 1;
    }
    cout << totalMove + dis_matrix[lastmove][predict[1]];
    return 0;
}
