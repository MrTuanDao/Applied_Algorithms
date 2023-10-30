#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 20;

int n;
int mem[N][1<<N], C[N][N];

// Pre: 0 <= i < n; 1 <= S <= (1 << n) - 1
// dp(i, S) là cách sử dụng ít chi phí nhất để đi qua toàn bộ các
đỉnh và quay trở lại đỉnh 0, nếu như hiện tại hành trình đang ở tại
đỉnh i và người du lịch đã thăm tất cả các đỉnh trong tập S
Bước cơ sở: dp(i,tập mọi đỉnh) = Ci,0
Bước chuyển qui nạp: dp(i, S) = min_{j không thuộc S} { C_{i,j} + tsp(j, S ∪ {j}) } */
int dp(int i, int S) {
    if ( S == ((1 << n) - 1) ) {
        return mem[i][S] = C[i][0];
    }
    if (mem[i][S] != -1) return mem[i][S];
    
    int res = INF;
    for (int j = 0; j < n; ++j) {
        if (S & (1 << j)) continue;
        
        res = min(res, C[i][j] + dp(j, S | (1 << j)));
    }
    return mem[i][S] = res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> C[i][j];
        }
    }
}

void trace(int i, int S) {
    cout << i << "->";
    if (S == (1 << n) - 1) {
        cout << 0 << endl;
        return;
    }
    
    for (int j = 0; j < n; ++j) {
        if (S & (1 << j)) continue;
        if (mem[i][S] == C[i][j] + mem[j][S | (1 << j)]){
            trace(j, S | (1 << j));
        }
    }
}

int main() {
    memset(mem, -1, sizeof(mem));
    input();
    
    cout << dp(0, 1 << 0) << endl;
    
    trace(0, 1<<0);
    return 0;
}
