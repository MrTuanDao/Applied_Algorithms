#include <bits/stdc++.h>
using namespace std;

int n;
int coban[6] = {500, 100, 50, 10, 5, 1};

void input() {
    cin >> n;
}

int solve() {
    
    int w = 1000 - n;
    
    int chidiem = 0;
    int res = 0;
    
    while (w > 0) {
        int giatri = coban[chidiem];
        if (giatri > w) {
            chidiem++;
            if (chidiem == 6) return 0;
        }
        else {
            w -= giatri;
            res++;
        }
    }
    
    return res;
}

int main() {
        input();
        
        int res = solve();
        cout << res << endl;
    
    return 0;
}
