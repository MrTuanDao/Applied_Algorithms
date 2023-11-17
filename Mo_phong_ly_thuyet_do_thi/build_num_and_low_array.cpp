/*
- Đầu tiên, đánh số các đỉnh theo thứ tự duyệt của thuật toán DFS trong mảng num
- Với mỗi đỉnh u, cần tính Low[u] là chỉ số của đỉnh nhỏ nhất mà u có thể chạm được (bởi một cạnh ngược) 
  khi tiếp tục duyệt theo cây con có gốc tại u
- Khởi tạo thì Low[u] = Num[u], Low[u] sẽ thay đổi khi có một cạnh ngược.

:3 Mảng num và mảng low đem lại rất nhiều thông tin cho đồ thị vô hướng, nó có thể dùng để tìm cầu (brigde),
tìm khuỷa (artipleplepoint - không nhớ tên tiếng anh)
*/
#define MAX_N 30
#include <bits/stdc++.h>
using namespace std;

int soDinh, soCanh;
int num[MAX_N], low[MAX_N];
vector<int> dinhKe[MAX_N];
int curNum = 0;

void input() {
    cin >> soDinh >> soCanh;
    
    int u, v;
    for (int i = 0; i < soCanh; i++) {
        cin >> u >> v;
        dinhKe[u].push_back(v);
        dinhKe[v].push_back(u);
    }
    
    for (int i = 1; i <= soDinh; i++) 
        sort(dinhKe[i].begin(), dinhKe[i].end());
    
}

// ham giup xay dung mang num, low
void DFS(int u, int p) {
    low[u] = num[u] = ++curNum;
    
    for(const int &v : dinhKe[u]) {
        if (v == p) continue;
        if (num[v] == -1) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
}

// build num array, low array
void build_num_and_low_array() {
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(num));
    
    for (int i = 1; i <= soDinh; i++) {
        if (num[i] == -1) DFS(i, -1);
    }
    
    cout << "NUM: ";
    for (int i = 1; i <= soDinh; i++) {
        cout << num[i] << ' ';
    }
    cout << endl;
    
    cout << "LOW: ";
    for (int i = 1; i <= soDinh; i++) {
        cout << low[i] << ' ';
    }
    cout << endl;
}

int main() {
    input();
    build_num_and_low_array();
    
    return 0;
}
