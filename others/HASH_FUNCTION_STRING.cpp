#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(n--){
        string s; cin >> s;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res = (s[i] + 256 * res) % m ;
        }
        cout << res <<endl;
    }
    return 0;
}
