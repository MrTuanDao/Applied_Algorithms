#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int T = 1e2 + 10;
int n, t, d;
int a[N], time_mattrix[N];
int dp[T][N];

void input() {
    cin >> n >> t >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> time_mattrix[i];
}  
  
// Tìm phần tử max trước đó phần tử thứ i hàng j
int max_in_prev(int i, int j) {
    int row = i - time_mattrix[j]; if (row < 1) return 0;
    int res = 0; 
    
    for (int k = j - d; k <= j - 1; k++) res = max(res, dp[row][k]);

    return res;
}
    
int solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            if(i >= time_mattrix[j]) dp[i][j] = a[j] + max_in_prev(i, j);
        }
    }
    
    int res = 0;
    for (int j = 1; j <= n; j++) res = max(res, dp[t][j]);
    return res;
}

int main () {
    input();
    cout << solve() << endl;
    
    return 0;   
}
