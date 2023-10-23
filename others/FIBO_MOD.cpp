/*
TÍnh số dư của số fibo thứ n cho 10^9 + 7.
(1 <= n <= 2^63 - 1)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll n;

void mat_mult(ll F[2][2], ll M[2][2]){
    ll temp[2][2];
    temp[0][0] = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    temp[0][1] = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    temp[1][0] = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    temp[1][1] = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            F[i][j] = temp[i][j] % MOD;
}

void power(ll F[2][2], int n){
    ll M[2][2] = {{1, 1}, {1, 0}};
    if (n < 2) return;
    power(F, n / 2);
    mat_mult(F, F);
    if (n % 2) mat_mult(F, M);
}

ll fibo_exp(int n){
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 1;
    power(F, n - 1);
    return F[0][0] + F[0][1];
}

ll fibo(ll n){
    if (n < 2) return 1;
    else return fibo(n - 1) % MOD + fibo(n - 2) % MOD; 
}

int main(){
    cin >> n;
    cout << fibo_exp(pow(2,60)) << ' ' << fibo(10) << endl;

    return 0;
}
