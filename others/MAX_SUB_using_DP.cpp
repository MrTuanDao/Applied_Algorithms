#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int A[N];
int mem[N], marked[N];
int n;

int maxSum(int i){ // giá trị lớn nhất mà kết thúc ở i
    if (i == 1) return A[i];
    // if(marked[i]) {
    //     cout << "Phat hien marked" << endl;
    //     return mem[i];
    // }
    int res = max(A[i], A[i] + maxSum(i - 1));
    mem[i] = res;
    // marked[i] = true;
    return res;
}

void trace(int i){// xác định phần tử thứ i có nằm trong kết quả không
    if(i != 1 && mem[i] == mem[i - 1] + A[i]){
        trace(i - 1);
    }
    cout << A[i] << ' ';
}

int main(){
    memset(marked, 0, sizeof(marked));
    cin >> n; for(int i = 1; i <= n; i++) {cin >> A[i]; mem[i] = A[i];}
    maxSum(n);
    int ans = 0, pos = 0;;
    for (int i = 1; i <= n; i++) {ans = max(ans, mem[i]); if (ans == mem[i]) pos = i;} 
    cout << ans << endl;
    trace(pos);
    return 0;
}
