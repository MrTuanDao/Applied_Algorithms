#include<bits/stdc++.h>
using namespace std;

int  main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, L, m;
    set<int> khoiTao;
    
    cin >> n >> L >> m;
    for(int i = 1; i <= n; i++){
        string temp; cin >> temp;
        khoiTao.insert(stol(temp));
    } 
    
    int bienDem = 1;
    while (m--) {
        while( khoiTao.count(bienDem) != 0 ) bienDem++;
        khoiTao.insert(bienDem);
    }
    
    for(const int& so : khoiTao) {
        for(int j = 1; j <= L - to_string(so).size(); j++) cout << '0';
        cout << so << "\n";   
    }
    
    return 0;
}
