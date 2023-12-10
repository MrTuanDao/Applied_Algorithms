#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int n, k;
int pre_cal[MAX_N];


void input() {
    cin >> n >> k;
    pre_cal[0] = 0;
    cin >> pre_cal[1];
    int x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        pre_cal[i] = pre_cal[i - 1] + x;
    }
}

double TRY(int j) { //tim trung binh cong lon nhat cua day con co j phan tu
    double max_tb = 0;
    
    for (int m = 1; m <= n - j + 1; m++) {
        max_tb = max(max_tb, (pre_cal[m + j - 1] - pre_cal[m - 1]) * 1.0 / j);
    }
    
    return max_tb;
    
}

double solve() {
    double ketqua = 0;
    for (int i = k; i <= n; i++) {
        ketqua = max(ketqua, TRY(i));
    }
    return ketqua;
}

int main() {
    input();
    double ketqua = solve();
    
    printf("%.5lf", ketqua);
    
}
