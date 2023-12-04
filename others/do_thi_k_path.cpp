#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;

int soKetQua = 0;
int n, k;
int batdau;
int travel[MAX_N], visited[MAX_N];
int C[MAX_N][MAX_N];

void input() {
    cin >> n >> k;
    int m; cin >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        C[u][v] = 1;
        C[v][u] = 1;
    }
}

void TRY(int lantry) {
    
    if (lantry == k + 2) {
            soKetQua++;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (C[ travel[lantry - 1] ][i] == 1) {
            if (visited[i] == 0) {
                visited[i] = 1;
                travel[lantry] = i;
                TRY(lantry + 1);
                visited[i] = 0;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        memset(travel, -1, sizeof(travel));
        travel[1] = i;
        visited[i] = 1;
        batdau = i;
        TRY(2);
    }
    cout << soKetQua / 2 << endl;
}

int main() {
    input();
    solve();
    
    return 0;
    
}
