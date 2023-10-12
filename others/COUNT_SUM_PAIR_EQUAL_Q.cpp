#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int res = 0;
    int n, Q; cin >> n >> Q;
    set<int> mySet;
    for(int i = 1; i <= n ; i++){
        int x; cin >> x; 
        if(mySet.count(Q - x) != 0) {res++; continue;}
        mySet.insert(x);
    }
    cout << res;
    return 0;
}
