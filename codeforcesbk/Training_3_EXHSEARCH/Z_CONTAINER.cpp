#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
const int MAX_H = 35;
int h, w, n;
vector<int> hcn[MAX_N];
int container[MAX_H][MAX_H];
int visited[MAX_N];

// Comparator function for sorting based on height
bool compareByHeight(const vector<int>& a, const vector<int>& b) {
    return (a[0] * a[1]) > (b[0] * b[1]);  // Assuming the height is stored at index 0
}

void input() {
    cin >> h >> w >> n; int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        hcn[i].push_back(x); hcn[i].push_back(y);
    }
    
    // Sort the vector based on height
    sort(hcn + 1, hcn + n + 1, compareByHeight);
    memset(visited, 0, sizeof(visited));
}

bool dien_vao_duoc(int hang, int cot, int dixuong, int dingang) {
    for (int i = hang; i < hang + dixuong; i++) {
        for (int j = cot; j < cot + dingang; j++) {
            if (container[i][j] == 1) return false;
        }
    }
    return true;
}

void dien_vao(int hang, int cot, int dixuong, int dingang, int so) {
    for (int i = hang; i < hang + dixuong; i++) {
        for (int j = cot; j < cot + dingang; j++) {
            container[i][j] = so;
        }
    }
}

int chieusau, chieungang;
void de_quy_ma_ra_thi_moi_hay(int k) {
    // xep item thu     
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        chieusau = hcn[i][0], chieungang = hcn[i][1];
        for (int hang = 1; hang <= h + 1 - chieusau; hang++) {
            for (int cot = 1; cot <= w + 1 - chieungang; cot++) {
                if (dien_vao_duoc(hang, cot, chieusau, chieungang)) {
                    dien_vao(hang, cot, chieusau, chieungang, 1);
                    if (k == n) {
                        cout << 1; exit(0);
                    }
                    else {
                        de_quy_ma_ra_thi_moi_hay(k + 1);
                    }
                    dien_vao(hang, cot, chieusau, chieungang, 0);
                }
            }
        }   
        visited[i] = 0;
    }
    
}

int main() {
    input();
    de_quy_ma_ra_thi_moi_hay(1);
    cout << 0;
    return 0;
}
