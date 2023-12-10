#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int kytu[10]; //H, U, S, T, O, I, C
int sum;
int visited[10];
int soLoigiai = 0;

int tinhTong() {
    return 1000*kytu[1] + 100*kytu[2] + 10010*kytu[3] + 2*kytu[4] + 1000*kytu[5] + 100*kytu[6] + 10*kytu[7];
}

void TRY (int k) {
    for (int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            if (i == 0 && (k==1 || k==3)) continue;
            kytu[k] = i;
            visited[i] = 1;
            
            if (k == 7) {
                if (tinhTong() == n) {
                    soLoigiai++;
                    // for (int i = 1; i <= 7; i++) cout << kytu[i] << ' ';
                    // cout << endl;
                }
            }
            else if (k < 7) TRY (k + 1);
            
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        soLoigiai = 0;
        memset(visited, 0, sizeof(visited));
        memset(kytu, 0 ,sizeof(kytu));
        cin >> n;
        TRY(1);
        cout << soLoigiai << endl;
    }
    
    return 0;
}
