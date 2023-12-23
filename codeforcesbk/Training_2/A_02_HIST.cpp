// A. 02. HIST
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 10;
int n;
int phienda[MAX_N];

bool input() {
    cin >> n; if (n == 0) return false;
    
    for (int i = 1; i <= n; i++) cin >> phienda[i];
    phienda[n+1] = 0;
    return true;
}

long long solve() {
    stack<int> _stack;
    long long maxArea = 0;

    for(int i = 1; i <= n + 1; i ++){
        int start = i;
        int height = phienda[i];
        while(!_stack.empty() && height < _stack.top()){
            int end_height = _stack.top(); _stack.pop();
            int end_id = _stack.top(); _stack.pop();
            start = end_id;
            maxArea = max(maxArea, (long long)(i - end_id) * (long long)end_height);
        }
        if (height == 0) continue;
        _stack.push(start); _stack.push(height);
    }

    return maxArea;
}

int main() {
    while(input()) {
        cout << solve() << endl;
    }
}
