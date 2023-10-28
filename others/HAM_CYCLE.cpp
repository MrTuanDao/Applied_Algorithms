#include <bits/stdc++.h>
using namespace std;

/* Hamilton Cycle là đồ thị có đường đi mà mỗi đỉnh đúng một lần 
và quay trở về nơi xuất phát.
Thuật toán hiệu quả, xác định xem một đồ thị Hamilton hay không 
vẫn đang là một thách thức lớn đối với các nhà toán học và tin học. */

// Tôi sẽ sử dụng brute force

const int N = 15;
int n, m, visited[N], travel[N];
bool haved = 0;
vector<int> dinhKe[N];

// Hàm lặp đệ quy
// Tìm đỉnh thứ k trong 1 đường đi khả dụng
// Cuối cùng trở về nơi xuất phát, cụ thể: đỉnh 1
// Pre: 1 <= k <= n
void TRY(int k){
    if (k == n) {
        for (const int& dinhTiep : dinhKe[ travel[k] ]) {
            if (dinhTiep == 1) {
                haved = 1; break;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << travel[i] << ' ';
        // }
        // cout << endl;
        return;
    }
    if (!haved){
        for (const int& dinhTiep : dinhKe[ travel[k] ]){
            if(visited[dinhTiep]) continue;
            visited[dinhTiep] = 1;
            travel[k + 1] = dinhTiep; TRY(k + 1);
            visited[dinhTiep] = 0;
        }
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) dinhKe[i].clear();
        while(m--){
            int dinh1, dinh2; cin >> dinh1 >> dinh2;
            dinhKe[dinh1].push_back(dinh2);
            dinhKe[dinh2].push_back(dinh1);
        }
        
        haved = 0; visited[1] = 1, travel[1] = 1; TRY(1);
        cout << haved << endl;
    }
}
