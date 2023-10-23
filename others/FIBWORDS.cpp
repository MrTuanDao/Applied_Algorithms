#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 25, MAXN = 100 + 5;
ll mem[MAXN];
string fibo[M + 5];
int n; string p;

string suffix(string str, int l){
    return str.substr(str.size() - l);
}

string prefix(string str, int l){
    return str.substr(0, l);
}

ll count_p(string str, string p){ // tính cho trường hợp overlap
    ll ans = 0;
    for(int i = 0; i + p.size() - 1 <= str.size(); i++){
        bool ok = true;
        for(int j = 0 ; j < p.size(); j++){
            if(p[j] != str[i + j]){
                ok = false; break;
            }
        }
        if (ok) ans++;
    }
    return ans;
}

ll calc(int n, string p){
    if(n < M) return count_p(fibo[n], p);
    if(mem[n] != -1) return mem[n];
    ll res = 0;
    res = calc(n - 1, p) + calc(n - 2, p);
    string mid = suffix(fibo[M + (n % 2)], p.size() - 1) + 
                 prefix(fibo[M], p.size() - 1);
    res += count_p(mid, p);
    return mem[n] = res;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(mem, -1, sizeof(mem));
        cin >> n >> p;
        fibo[0] = "0";
        fibo[1] = "1";
        for(int i = 2; i <= M + 1; i++)
            fibo[i] = fibo[i-1] + fibo[i-2];
        cout << calc(n, p) << endl;
        
    }
    return 0;
}
