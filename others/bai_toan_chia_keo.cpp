#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
int n, m, x[MAXN];

int tongKeo(int left, int right){
    int tong = 0;
    for(int i = left; i < right; i++) tong += x[i];
    return tong;
}

void ghiNhan(){
    for(int i = 1; i <=n; i++) cout<<x[i]<<' ';
    cout << endl;
}

void Try(int k){
    // lựa chọn UCV cho vị trí thứ i, còn x[k+1], x[k+2], ... x[n]
    // x[i] nằm trong khoảng từ 1 tới (m - (n - k) - tổng số kẹo đã chia )
    if(k==n){
        x[k] = (m - (n-k) - tongKeo(1,k));
        ghiNhan();return;
    }
    for(int i = 1; i <= (m - (n-k) - tongKeo(1,k)); i++){
        x[k] = i;
        if (k == n) ghiNhan();
        else Try(k+1);
        x[k] = 0;
    }
    
}

int main(){
    cin >> n >> m;
    Try(1);
    return 0;
}
