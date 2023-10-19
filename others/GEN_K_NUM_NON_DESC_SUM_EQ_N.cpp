#include<bits/stdc++.h>
using namespace std;

const int N = 40 + 10;
int k, n, cur;
int a[N] = {1};

void dfs(int j){
    if(j == k){
        for(int i = 1; i <= k - 1; i++){
            cout << a[i] << ' ';
        }
        cout << n - cur  << " \n";
    }
    else for(int i = a[j-1]; i <= (n - cur) / (k - j + 1); i++){
        a[j] = i;
        cur += a[j];
        dfs(j + 1);
        cur -= a[j];
    }
}

int main(){
    cin >> k >> n;
    dfs(1);
    return 0;
}
