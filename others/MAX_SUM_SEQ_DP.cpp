// Bai toan day con co tong lon nhat

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, a[MAXN], pos = -1;
int mem[MAXN];
bool marked[MAXN];

int dp(int i){
    if (i == 1) return a[1];
    if (marked[i]) return mem[i];
    int res = max(a[i], a[i] + dp(i - 1));
    marked[i] = true;
    return mem[i] = res;
}

int solve(){
    int ans = a[1];
    for(int i = 1; i <= n; i++){
        if(ans < dp(i)){
            ans = dp(i);
            pos = i;
        }
    }
    return ans;
}

void trace(int i){
    cout << "pos la: " << pos << endl;
    if (i > 1 && mem[i] == a[i] + mem[i - 1]) trace(i - 1);
    cout << a[i] << ' ';
}

int main(){
    memset(mem, -1, sizeof(mem));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    cout << solve() << endl;
    trace(pos);
}
