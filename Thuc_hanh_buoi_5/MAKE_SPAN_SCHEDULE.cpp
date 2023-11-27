#define MAX_N 100000
#include <bits/stdc++.h>
using namespace std;

int soDinh, soCanh;
int d[MAX_N];
vector<int> dinhKe[MAX_N];
vector<int> order;
bool visited[MAX_N];
int earlest_time[MAX_N];

void input() {
    cin >> soDinh >> soCanh;
    
    for (int i = 1; i <= soDinh; i++) cin >> d[i];
    
    int u, v;
    for (int i = 0; i < soCanh; i++) {
        cin >> u >> v;
        dinhKe[u].push_back(v);
    }
    
    for (int i = 1; i <= soDinh; i++) 
        dinhKe[i].push_back(0);
        
    d[0] = 0;
    
}

// thực hiện duyệt ngược từ dưới lên, sau đó ta đảo lại mảng order sẽ lấy được thứ tự toposort
void topo_sort(int u) {
    visited[u] = true;
    
    for (const int &v : dinhKe[u]) {
        if (visited[v]) continue;
        topo_sort(v);
    }
    
    order.push_back(u);
}

void solve() {
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= soDinh; i++) {
        if (!visited[i]) topo_sort(i);
    }
    reverse(order.begin(), order.end());
    
    // for (const int &u : order) cout << u << ' ';
    // cout << endl;
    
    // thuat toan bat dau
    int makespan = 0;
    memset(earlest_time, 0, sizeof(earlest_time));
    
    for (const int &u : order) {
        for (const int &v : dinhKe[u]) {
            makespan = max(makespan, earlest_time[u] + d[u]);
            earlest_time[v] = max(earlest_time[v], earlest_time[u] + d[u]);
        }
    }
    
    cout << makespan << endl;
}

int main() {
    input();
    solve();
    
    
    return 0;
}
