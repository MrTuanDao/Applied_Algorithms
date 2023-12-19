#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

void nhap_big_int(vector<int>& a) {
    a.clear();
    fflush(stdin);
    // read input
    string input;
    getline(cin, input);

    // initialize string stream
    stringstream ss(input);
    char x;
    while(ss>>x) {
        if (x - '0' < 0 || x - '0' > 9) continue;
        if (x - '0' == 0 && a.empty()) continue;
        a.push_back(x - '0');
    }
    reverse(a.begin(), a.end());
}

void input() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    nhap_big_int(a);
    nhap_big_int(b);
}

vector<int> cong_2_big_int(vector<int>& a, vector<int>& b) {
    vector<int> res; res.clear();
    int cur, cura, curb, lena = a.size(), lenb = b.size(), carry = 0;
    int i = 0;
    while (true) {
        if (i < lena) cura = a[i];
        else cura = 0;
        
        if (i < lenb) curb = b[i];
        else curb = 0;
        
        if (i >= lena && i >= lenb && carry == 0) break;
        
        cur = cura + curb + carry;
        
        carry = 0;
        if (cur > 9) {
            carry = 1;
            cur -= 10;
        }
        
        res.push_back(cur);
        i++;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    input();
    vector<int> res = cong_2_big_int(a, b);
    
    for(int &x: res) cout << x;
    
    return 0;
}
