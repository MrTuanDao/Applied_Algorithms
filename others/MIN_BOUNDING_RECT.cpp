#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int min_x = 100, min_y = 100, max_x = 0, max_y = 0;
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        min_x = min(min_x, min(x1, x2));
        min_y = min(min_y, min(y1, y2));
        max_x = max(max_x, max(x1, x2));
        max_y = max(max_y, max(y1, y2));
    }
    cout << (max_x - min_x) * (max_y - min_y);
}
