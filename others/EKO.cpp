/*
Bài toán EKO
Cho n cái cây có các chiều cao a1, a2, a3,...
Có thể thực hiện cắt ở độ cao h với tất cả các cây
Số lượng gỗ thu được là phần chóp của các cây cao hơn hơn h
Tìm h lớn nhất có thể để số lượng gỗ thu được tối thiểu là m
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n, m;
int heights[MAXN];

int amount(int h){
    int totalWood = 0;
    for(int i = 1; i <= n; i++){
        if(heights[i] > h) totalWood += heights[i] - h;
    }
    return totalWood;
}

int main(){
    cin >> n >> m;
    int max_h = 0;
    for(int i = 1; i <= n; i++){
        cin >> heights[i];
        max_h = max(max_h, heights[i]);
    }
    int lo = 0, hi = max_h;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(amount(mid) > m) lo = mid + 1;
        else hi = mid - 1;
    }
    
    cout << lo;
    return 0;
}
