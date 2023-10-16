/* Bai toan day con co tong lon nhat
Input:
5
-16 7 -3 0 -1 5 -4
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, a[MAXN];

int MaxLeft(int i, int m){
    int ans = a[m], sum = 0;
    for(int k = m; k >= i; k--){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRight(int m1, int j){
    int ans = a[m1], sum = 0;
    for(int k = m1; k <= j; k++){
        sum += a[k];
        ans = max(ans, sum);
    }    
    return ans;
}

int MaxSubSeq(int i, int j){
    if(i == j) return a[i];
    // DIVIDE
    int m = (i + j)/2;
    // XU LY
    int wL = MaxSubSeq(i, m);
    int wR = MaxSubSeq(m + 1, j);
    // KET HOP LOI GIAI
    int wLM = MaxLeft(i, m);
    int wRM = MaxRight(m + 1, j);
    int wM = wLM + wRM;
    
    return max(max(wL, wR), wM);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << MaxSubSeq(1, n);
    
    return 0;
}
