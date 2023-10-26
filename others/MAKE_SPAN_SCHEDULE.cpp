#include <bits/stdc++.h>
using namespace std;

// Pre: 1 <= n <= 1e4 
// Sử dụng dfs, kết hợp nhánh cận 
const int N = 1e4 + 5;
int n, m, d[N], travel[N], cur_time = 0, max_ans = 0, notRoot[N];
vector<int> after[N];
int range[N][N]; 
int batDau;

// Pre: 1 <= k <= n
// Tìm kiếm đỉnh cho vị trí thứ k trong chuỗi duyệt
void TRY(int k) {
    for (const int& i : after[ travel[k - 1] ]) {
            // "Nếu khoảng cách từ điểm bắt đầu tới i" nhỏ hơn kỉ lục thì bỏ qua đường đi hiện tại
            if (cur_time < range[batDau][i]) continue;
            range[batDau][i] = cur_time;
            
            travel[k] = i;
            cur_time += d[i];
            
            if ( after[i].empty() ) {
                max_ans = max(max_ans, cur_time);
            }
            else {TRY(k + 1);}
            
            cur_time -= d[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(range, 0, sizeof(range));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        int nut1, nut2; cin >> nut1 >> nut2;
        notRoot[nut2] = 1; after[nut1].push_back(nut2);
    }
    
    for(int i = 1; i <= n; i++){
        if( notRoot[i] == 0 ) {
            travel[1] = i; cur_time += d[i]; batDau = i;
            
            TRY(2);
            
            cur_time -= d[i];
        }
    }
    
    cout << max_ans;
    return 0;
}
