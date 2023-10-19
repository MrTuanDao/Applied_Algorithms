#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 10;
int n, a[N] = {1};
int cur = 0;
int res = 0;

void TRY(int k){
    for(int i = a[k-1]; i <= n - cur; i++){
        cur += i;
        a[k] = i;
        if(cur == n) res++;
        else TRY(k + 1);
        cur -= i;
    }    
}

int main(){
    cin >> n;
    TRY(1);
    cout << res;
    return 0;
}
