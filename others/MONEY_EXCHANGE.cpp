#include <bits/stdc++.h>
using namespace std;

const int N = 10, X = 1e3 + 10;
int n, x, D[N], mem[N][X]; // mem lưu trữ giá trị 

int minCoin(int i, int target){
    // cout << "Dang thu " << D[i] << " voi " << target << endl;
    if(target == 0) return mem[i][target] = 0;
    if (i == 0) return mem[i][target] = 1e6; 
    if(target <= 0) return 1e6;
    
    if (mem[i][target] != -1) return mem[i][target];
    int res = 1e6; 
    res = min(res, 1 + minCoin(i, target - D[i]));
    res = min(res, minCoin(i - 1, target));
    return mem[i][target] = res;
}

void trace(int i, int target){
    if(target <= 0 || i == 0) return;
    
    if(mem[i][target] == 1 + mem[i][target - D[i]]){
        cout << D[i] << ' ';
        trace(i, target - D[i]);
    } else {
        trace(i - 1, target);
    }
}

int main(){
    cin >> n >> x; for(int i = 1; i <= n; i++) cin >> D[i];
    for(int i = 1; i <= n; i++) cout << D[i] << ' '; cout << x << endl;
    memset(mem, -1, sizeof(mem));
    cout << minCoin(n, x) << endl;
    trace(n, x);
    return 0;
}
