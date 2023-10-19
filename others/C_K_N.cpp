#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1000 + 5, MAXN = 1000 + 5;
const long long MOD = 1e9 + 7;
int k, n;
long long store_C[MAXK][MAXN] = {}; 

long int C(int k, int n){
    // base_case
    if(k == 0 || k == n) return 1;
    // if find in memory
    if ( store_C[k][n] != 0 ) return store_C[k][n];
    if ( store_C[n-k][n] != 0 ) return store_C[n-k][n];
    // combine result VD C(3 ,5) = C( 2, 4) + C( 3, 4),
    // C( 3, 4) = C( 2, 3) + C( 3, 3), C( 2, 4) = C( 1, 3) + C( 2, 3)
    // store in memory
    store_C[k][n] = ( C( k - 1, n - 1) % MOD + C( k, n - 1) % MOD ) % MOD;
    return store_C[k][n];
}

int main(){
    cin >> k >> n;
    cout << C( k, n);
}
