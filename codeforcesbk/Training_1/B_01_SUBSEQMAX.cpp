#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 10;
int n;
long long a[MAX_N];

void input() {
    cin >> n;
    int x;
    long long maxsum = -1e9;
    long long cur = 0;

  // slicing window
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x < 0) {
            maxsum = max(maxsum, cur);
            if (cur + x < 0){
                cur = 0;
                continue;
            }
        }
        cur += x;
        
    }
    maxsum = max(maxsum, cur);
    cout << maxsum;
    
}

int main() {
    input();
    
    return 0;
    
}
