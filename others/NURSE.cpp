#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, k1, k2;
int dp[N];

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


