// Dao Quoc Tuan 20210891
#include<bits/stdc++.h>
using namespace std;


// unsigned long long int	8bytes	0 to 18,446,744,073,709,551,615
#define ull unsigned long long 
const ull m = 1000000007; //m = 10^9 + 7

ull expmod(ull a, ull b){
    if(b==0) return 1;
    if(b%2 == 0){
        ull temp = expmod(a, b/2);
        return ((temp % m) * (temp % m))%m;
    }
    else return ((a % m) * (expmod(a, b - 1) % m )) % m;
}

int main(){
    
    ull a, b; cin >> a >> b;
    cout<< expmod(a,b) << endl;
    
    // unsigned long long int x = 1e30; cout << x %  m << endl;
    return 0;
}
