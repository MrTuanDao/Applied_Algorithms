#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int x[N], y[N];
int table[N][N]; // table[i][j] lưu giá trị maxSub của xâu X từ đầu tới i và xâu Y từ đầu tới j

// Qui hoạch động khử đệ qui
void maxSub(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ( x[i] == y[j] ) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = max( table[i - 1][j], table[i][j - 1] );
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];
    
    maxSub(n, m);
    cout << table[n][m]  << endl;
    
    return 0;
}
