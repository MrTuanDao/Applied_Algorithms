#include <bits/stdc++.h>
using namespace std;

long long w, c;
long long coban[4] = {5000, 3000, 2000, 1000};
long long solan;

void input() {
    cin >> w >> c;
    c = min((long long)log10(w/1000), c);
}

long long mu(long long k, long long so) {
    long long res = 1;
    for (long long i = 1; i <= k; i++) res *= so;
    return res;
}


int visited[4] = {0, 0, 0, 0};
long long solve() {
    solan = 1;
    long long res = 0;
    if (w % 1000 != 0) return 0;
    while (c >= 0) {
        int solanobacnay = 1;
        memset(visited, 0, sizeof(visited));
        long long muoday = mu(c, 10);
        for (long long i = 0; i < 4; i++) {
            long long giatri = coban[i] * muoday;
            if(giatri <= w) {
                res += (long long) (w / giatri);
                w %= giatri;
                visited[i] = 1;
            }
        }
        solanobacnay = 1 + (visited[1] && visited[3]) + (visited[0] && visited[3]);
        solan *= solanobacnay;
        c--;
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        input();
        
        long long res = solve();
        if (res != 0) cout << res << ' ' << solan << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}
