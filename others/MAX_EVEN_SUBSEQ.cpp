#include <bits/stdc++.h>
using namespace std;


#define int long long

const int INF = 1e12;
const int N = 2e6;
int a[N];
int pre[N] = {0}, minLe = 1e17 + 1, minChan = 0;
int res = 0;

void solve () {
    int n; cin >> n; 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
        pre[i] = pre[i - 1] + a[i];
        
        if ( (pre[i] + INF) % 2 == 0 ) {
            res = max(res, pre[i] - minChan);
            minChan = min(minChan, pre[i]);
        }
        else {
            res = max(res, pre[i] - minLe);
            minLe = min(minLe, pre[i]);
        }
    }
    
    cout << res << endl;
    
    
}

signed main() {
    solve();
    return 0;
}
