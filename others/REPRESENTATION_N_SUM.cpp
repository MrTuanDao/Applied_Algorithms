#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, MOD = 1e9 + 7;
int n, table[N][N]; // table[i][j] chứa những số lượng tổng = i mà mỗi phần tử không vượt quá j

// Giải thích:
// Ví dụ có 1 lời giải được sắp xếp tăng dần, thì số lượng lời giải bằng
// tổng các số lượng lời giải ta bớt phần tử cuối cùng (aka phần tử lớn nhất)
// phần tử cuối cùng này chạy từ 1 đến n
int count(int i, int j) {
    // Base
    if (i <= 1) return table[i][j] = 1;
    if (i < j) return table[i][j] = count(i, i);
    if (j == 1) return table[i][j] = 1;
    if (table[i][j] != 0) return table[i][j];
    
    int soLuong = 0;
    for (int k = 1; k <= j; k++){
        soLuong = ( soLuong + count(i - k, k) ) % MOD;
    }
    return table[i][j] = soLuong % MOD;
}

int main() {
    cin >> n;
    cout << count(n, n) << endl;

    return 0;
}
