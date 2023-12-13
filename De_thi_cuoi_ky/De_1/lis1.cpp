// do phuc tap O(n logn)
#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> so_va_chuoi_so;
int res;

void solve() {
    res = 0;
    cin >> n; int x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        so_va_chuoi_so[x] = so_va_chuoi_so[x-1] + 1;
        res = max(res, so_va_chuoi_so[x]);
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        solve();
    }
    
    return 0;
}
