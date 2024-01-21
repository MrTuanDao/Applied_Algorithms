#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_N = 1e6 + 10;
ll n;
ll hist[MAX_N];
ll L[MAX_N], R[MAX_N];
ll res = 0;

void input() {
    
    cin >> n; if (n == 0) exit(0);
    for (ll i = 1; i <= n; i++) {
        cin >> hist[i];
    }

    hist[0] = -1; hist[n+1] = -1; // dat linh canh
}

void find_first_smaller_left_and_right() {
    stack<ll> st;
    
    for (ll i = 1; i <= n + 1; i++) {
        while (!st.empty() && hist[st.top()] > hist[i]) {
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for (ll i = n; i >= 0; i--) {
        while (!st.empty() && hist[st.top()] > hist[i]) {
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void solve() {
    input();
    find_first_smaller_left_and_right();
    
    res = 0;
    for(ll i = 1; i <= n; i++) {
        res = max(res, hist[i] * (R[i] - L[i] - 1));
    }
    
    cout << res << '\n';
}

signed main() {
    while (true) solve();
    
    return 0;
}
