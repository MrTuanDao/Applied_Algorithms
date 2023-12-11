#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int n;
int timee[MAX_N];

void input() {
    cin >>  n;
    for (int i = 1; i <= n; i++) {
        cin >> timee[i];
    }
    
}

int solve() {
   sort(timee + 1, timee + n + 1, greater<int>());
   
   int res = 0;
   for (int i = 1; i <= n; i++) {
       res = max (res, timee[i] + i + 1);
   }
   return res;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
