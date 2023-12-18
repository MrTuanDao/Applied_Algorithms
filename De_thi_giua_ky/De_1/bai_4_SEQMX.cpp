#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const double INF = 1e18;
const int MAX_N = 1e5 + 10;
int n, k;
long long pre_cal[MAX_N];


void input() {
    cin >> n >> k;
    pre_cal[0] = 0;
    cin >> pre_cal[1];
    long long x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        pre_cal[i] = pre_cal[i - 1] + x;
    }
}

double TRY(int j) { //tim trung binh cong lon nhat cua day con co j phan tu
    long long max_tb = - INF;

    for (int m = 1; m <= n - j + 1; m++) {
        max_tb = max(max_tb, (pre_cal[m + j - 1] - pre_cal[m - 1]));
        //if (max_tb == 0) cout << "aha" << endl;
    }
    return max_tb * 1.0 / j;

}

double solve() {
    double ketqua = -INF;
    for (int i = k; i <= n; i++) {
        long long max_tb = -INF;

        for (int m = 1; m <= n - i + 1; m++) {
            max_tb = max(max_tb, (pre_cal[m + i - 1] - pre_cal[m - 1]));
            //if (max_tb == 0) cout << "aha" << endl;
        }

        ketqua = max(ketqua, max_tb * 1.0 / i);
    }
    return ketqua;
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    input();
    double ketqua = solve();

    printf("%.5lf", ketqua);

}
