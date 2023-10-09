// Bai toan nguoi di du lich
// TSP
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int C[MAXN][MAXN];
int n, cmin, fcur, fopt = INT_MAX;
int x[MAXN], xopt[MAXN];
bool visited[MAXN];

void input(){
    cin >> n;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> C[i][j];
            if( i != j) cmin = min(cmin, C[i][j]);
        }    
}

int TRY(int k){
    for(int i = 2; i <= n; i++)}{
        if(!visited[i]){
            x[k] = i;
            visited[i] = true;
            fcur += C[x[k-1]][i];
            if (k == n){
                if(fcur + C[i][1] < fopt){
                    fopt = fcur + C[i]1];
                    for(int j = 1; j <= n; j++) xopt[j] = x[j];
                }
            }
            else if (fcur + (n - k + 1) * cmin < fopt) TRY(k + 1);
            visited[i] = false;
            fcur -= C[x[k-1]][i];
        }
    }
}

int main(){
    input();
    x[1] = 1;
    visited[1] = true;
    TRY(2);
    cout << fopt << endl;
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << "->" ;
    }
    return 0;
}
