// B. 02. POSTMAN
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
    function<bool(pair<ll, ll>&, pair<ll, ll>&)>> myPQ_duong(
    [](pair<ll, ll>& a, pair<ll, ll>& b) {
        return abs(a.first) < abs(b.first);
    }
);

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
    function<bool(pair<ll, ll>&, pair<ll, ll>&)>> myPQ_am(
    [](pair<ll, ll>& a, pair<ll, ll>& b) {
        return abs(a.first) < abs(b.first);
    }
);

void input() {
    cin >> n >> k;
    ll x, m;
    for (ll i = 1; i <= n; i++) {
        cin >> x >> m; 
        if (x > 0) myPQ_duong.push({x, m});
        else myPQ_am.push({x, m});
    }
}

template <typename PriorityQueue>
ll solve(PriorityQueue& myPQ) {
    ll ship_long = 0;
    while (!myPQ.empty()) {
        pair<ll, ll> farest = myPQ.top(); myPQ.pop();
        // cout << farest.first << ' ' << farest.second << endl;
        if (farest.second > k) {
            ll so_lan_can_di = (farest.second-1) / k;
            ship_long += 2*abs(farest.first)*so_lan_can_di;
            farest.second -= so_lan_can_di*k;
        }
        ship_long += 2*abs(farest.first);
        // nếu farest vẫn còn hàng cần giao
        farest.second -= k;
        if (farest.second > 0) {
            myPQ.push({farest.first,farest.second});
            continue;
        }
        else{
        // nếu farest hết hàng cần giao, thừa một lượng là thua thi ship cho cai thu hai
            ll thua = -farest.second;
            while (!myPQ.empty() && thua >= 0) {
                farest = myPQ.top(); myPQ.pop();
                thua -= farest.second;
            }
            if (thua >=0 && myPQ.empty()) break;
            myPQ.push({farest.first, 0 - thua});
        }
    }
    
    return ship_long;
}

int main() {
    input();
    cout << solve(myPQ_duong) + solve(myPQ_am);
    return 0;
}
