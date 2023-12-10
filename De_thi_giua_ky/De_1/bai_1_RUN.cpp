#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int solancat = 0;
    int sotruoc, sosau;
    cin >> sotruoc;
    for (int i = 2; i <= n; i++) {
        cin >> sosau;
        if (sotruoc > sosau) solancat++;
        sotruoc = sosau;
    }
    
    cout << solancat + 1 << endl;
    return 0;
    
}
