#include<bits/stdc++.h>
using namespace std;

int main(){
    string P, C;
    getline(cin, P); getline(cin, C);
    int res = 0;
    size_t pos = C.find(P, 0);
    while(pos != -1){
        // cin >> tempC;
        // if(tempC.find(P) != -1) res++;
        // cout << (tempC.find(P, 0) != -1) << endl;
        res++;
        pos = C.find(P, pos + 1);
    }
    cout << res;
    return 0;
}
