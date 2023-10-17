/*
Bài toán AGGRCOW
Có n chuồng ở x1, x2, ...
Tìm số khoảng cách lớn nhất mà mấy con bò có thể ở các chuồng mà cách nhau khoảng cách này
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, c;
int x[N];

int amount(int dis){
    int total = 1, cur = x[1];
    for(int i = 2; i <= n; i++){
        if(x[i] >= cur + dis) {
            total++;
            cur = x[i];
        }
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test; cin >> test;
    while(test--){
        cin >> n >> c;
    
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        sort(x + 1, x + n + 1);
        
        int low = 1, high = x[n];
        while(low < high - 1){
            int mid = (low + high) / 2;
            if(amount(mid) >= c) low = mid;
            else high = mid - 1;
        }
        if(amount(high) >= c) cout << high << endl;
        else cout << low << endl;
    }
    return 0;
}
