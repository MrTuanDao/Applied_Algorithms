/*
Bài toán EKO
Cho n cái cây có các chiều cao a1, a2, a3,...
Có thể thực hiện cắt ở độ cao h với tất cả các cây
Số lượng gỗ thu được là phần chóp của các cây cao hơn hơn h
Tìm h lớn nhất có thể để số lượng gỗ thu được tối thiểu là m
*/
#include <iostream>
using namespace std;

const int MAXN = 1e6 + 10;
int n, m;
int heights[MAXN];

long long amount(int h){
    long long totalWood = 0;
    for(int i = 1; i <= n; i++){
        if(heights[i] > h) totalWood += heights[i] - h;
    }
    return totalWood;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int max_h = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> heights[i];
        max_h = max(max_h, heights[i]);
    }
    int lo = 0, hi = max_h;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(amount(mid) >= m) lo = mid;
        else hi = mid - 1;
    }
    if(amount(hi) >= m)) cout << hi << endl;
    else cout << lo;
    return 0;
}
