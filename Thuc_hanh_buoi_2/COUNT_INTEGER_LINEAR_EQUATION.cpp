// Dao Quoc Tuan 20210891
// backtrack và nhập vào vào vị trí i từng số một, 
// rồi nhập vào vị trí i + 1, khi nào có n vị trí được điền rồi thì tính thử xem tổng nó có bằng m không và ghi nhận thêm lời giải
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n,m, a[MAXN], kq[MAXN];
int ans = 0;

void input(){// nhập input
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
}

int sum(int left, int right){// tính tổng các số chạy từ left tới right
    int res = 0;
    for(int i = left; i<right; i++){
        res += kq[i] * a[i];
    }
    return res;
}

void ghiNhan(){
    if (sum(1, n + 1) == m) ans ++;
}

void Try(int i){// điền số vào vị trí thứ i
    for(int j = 1; j <= (m-sum(1, i))/a[i]; j ++){
        kq[i] = j;
        if (i == n) ghiNhan();
        else Try(i+1);
    }
}

int main(){
    input();
    Try(1);
    cout<<ans;
    return 0;
}
