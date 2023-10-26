// Dao Quoc Tuan 20210891
#include <bits/stdc++.h>
using namespace std;

/* Thuật toán Kruskal là một thuật toán trong lý thuyết đồ thị 
để tìm cây bao trùm nhỏ nhất của một đồ thị liên thông vô hướng có trọng số.
Nói cách khác, nó tìm một tập hợp các cạnh tạo thành một cây 
chứa tất cả các đỉnh của đồ thị và có tổng trọng số các cạnh là nhỏ nhất.
Thuật toán Kruskal là một ví dụ của thuật toán tham lam. */

/* Mã giả:
Bước 1: Sắp xếp các cạnh của đồ thị theo thứ tự trọng số tăng dần.
Bước 2: Khởi tạo T:= Ø
Bước 3: Lần lượt lấy từng cạnh thuộc danh sách đã sắp xếp. 
        Nếu T+{e} không chứa chu trình thì gán T:=T+{e}.
Bước 4: Nếu T đủ n-1 phần tử thì dừng, ngược lại làm tiếp bước 3. */

/* Lưu ý cho bạn nào tham khảo, bạn nên để ý ở chỗ xác định T+{e} có tạo thành 
chu trình không, tôi đã nhầm ở đoạn đấy và không có test_case nào đủ nhỏ để thử.
Bạn có thể so sánh với https://www.programiz.com/dsa/kruskal-algorithm, để xem từng bước 
in ra có giống không. 
Chúc may mắn! */

const int N = 1e5 + 10;
int n, m;
// Lưu trữ các cặp cạnh có w ở index thứ w
map< int, vector< pair<int, int> > > w_and_pair; 
int parent[N];

void input() {
    cin >> n >> m;
    while (m--) {
        int w, u, v; cin >> u >> v >> w; parent[u] = u, parent[v] = v;
        w_and_pair[w].push_back( make_pair(u, v) );
    }
    
    // In ra toàn bộ thông tin đã nhập trong w_and_pair
    // for (auto it = w_and_pair.begin(); it != w_and_pair.end(); it++) {
    //     cout << it->first << " | ";
    //     vector< pair<int, int> > tempVector = it->second;
    //     for(auto it1 = tempVector.begin(); it1 != tempVector.end(); it1++){
    //         pair<int, int> tempPair = *it1;
    //         cout << tempPair.first << ' ' << tempPair.second << " | ";
    //     }
    //     cout << endl;
    // }
}

// Pre: 1 <= k <= n
// Hàm tìm ra giá trị nút cha của đỉnh k
int find_parent(int k){
    int res = parent[k];
    while (res != parent[res]){
        res = parent[res];
    }
    return parent[k] = res;
}

void solve() {
    int res = 0;
    // cout << "Egde : Weight\n";
    for (auto it = w_and_pair.begin(); it != w_and_pair.end(); it++) {

        int w = it->first; 
        
        vector< pair<int ,int> > tempVector = it->second;
        for(auto it1 = tempVector.begin(); it1 != tempVector.end(); it1++){
            pair<int, int> curPair = *it1;
            int parent1 = find_parent( curPair.first );
            int parent2 = find_parent( curPair.second );
            
            if ( parent1 == parent2 ) continue;
            
            // cập nhật lại parent
            parent[parent2] = parent1;
            
            res += w;
            // cout << curPair.first << " - " << curPair.second << " : " << w << endl;
        }
    }
    
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
