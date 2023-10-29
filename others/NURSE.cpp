#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, k1, k2;
int dp[N];

// Trả về Số lượng cách cho h ngày thoả mãn
// 1.bắt đầu bằng 1 chuỗi ngày
// 2.sau 1 chuỗi ngày luôn là 1 ngày nghỉ
int count(int h) {
    if (h == 0) return dp[h] = 1;
    if ( h < k1 + 1) return 0;
    if (dp[h]) return dp[h];
    
    int res = 0;
    for (int i = k1; i <= k2; i++) {
        res += count(h - (i + 1) );
    }
    return dp[h] = res;
}

// Trả về Số lượng cách cho k ngày thoả mãn bắt đầu bằng 1 chuỗi làm việc
int solve(int k) {
    int res = count(k);
    for (int i = k1; i <= k2; i++){
        res += count(k - i);
    }
    return res;
}

int main () {
    cin >> n >> k1 >> k2;
    
    cout << solve(n) + solve(n - 1) << endl; 
    
    return 0;
}


