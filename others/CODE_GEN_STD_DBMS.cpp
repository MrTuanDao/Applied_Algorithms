#include<bits/stdc++.h>
using namespace std;

int  main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, L;
    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        string x; cin >> x;
        for(int j = 1; j <= L - x.size(); j++) cout << '0';
        cout << x << "\n";
    }
    return 0;
}
