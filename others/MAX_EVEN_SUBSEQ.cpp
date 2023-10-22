/*
Max Even SubSequence
Tìm dãy con có tổng chẵn là lớn nhất
Đạt 4/5 test case
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, a[N];

//Slicing window

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    long long curSum = 0, ans = (a[1] % 2 == 0) ? a[1] : INT_MIN;
    for(int i = 1; i <= n; i++){
        if(curSum < 0) curSum = 0;
        curSum += a[i];
        if(curSum % 2 == 0) ans = max(ans, curSum);
    }
    
    cout << ans;
    
    return 0;
}
