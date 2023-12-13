// độ phức tạp O(n)
#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

void input() {
    while(!q.empty()) q.pop();
    cin >> n; int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        q.push(x);
    }
}

int solve() {
    int res = 0;
    
    int curmax;
    
    while (true) {
        curmax = 0;
        int qsize = q.size();
        if (q.size() == 1) break;
        
        int a, b;
        for (int i = 1; i <= qsize / 2; i++) {
            a = q.front(); q.pop();
            b = q.front(); q.pop();
            curmax = max(curmax, a + b);
            q.push(a + b);
        }
        
        if (qsize % 2 == 1) {
            a = q.front(); q.pop();
            q.push(a);
        }
        res += curmax;
    }
    
    return res;
}

int main() {
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        input();
        cout << solve() << endl;
    }
    
    return 0;
    
}
