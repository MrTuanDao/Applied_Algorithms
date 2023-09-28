// Time: O(n*logn)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    
    int res = 0;
    set<int> mySet;
    
    while(n--){
        int x; cin >> x;
        if(mySet.find(m-x) != mySet.end()) res += 1;
        mySet.insert(x);
    }
    cout<<res;
    return 0;
}
