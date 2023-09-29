/* Dao Quoc Tuan 20210891
Ý tưởng của giải thuật này là khi so sánh hai nút nếu có cùng tổ tiên thì chúng thuộc cùng 1 đồ thị liên thông
Vì các nút là giá trị từ 1 tới N nên ta có thể cài đặt cây bằng mảng với index là giá trị của nút, 
và giá trị của mảng tại index là giá trị của cha 
*/

//CPP 
#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 1e5 + 5;

int par[MAXN];
int _rank[MAXN];
int n, m;

int find(int n1){ // hàm cho ra tổ tiên của nút
    int res = n1;
    while(res != par[res]){
        par[res] = par[par[res]]; // tăng tốc tìm kiếm cũng như thu nhỏ lại chiều cao của cây
        res = par[res];
    }
    return res;
}

int unite(int n1, int n2){
    int p1 = find(n1), p2 = find(n2);
    
    if (p1 == p2) return 0;
    
    if (_rank[p1] > _rank[p2]) { // cài đặt rank nhằm giảm thời gian đi tới nút tổ tiên của nút con
        par[p2] = p1;
        _rank[p1] += _rank[p2];
    } else {
        par[p1] = p2;
        _rank[p2] += _rank[p1];
    }
    return 1;
    
}

int main() 
{ 
    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++)  {
        par[i] = i;
        _rank[i] = 1;
    }
    
    for(int i = 0 ; i < m; i++){
        int n1, n2; cin>>n1>>n2;
        n -= unite(n1,n2);
    }
    cout<<n;
    return 0;   
}
