// khá giống bài TSP nhưng thay một số điều kiện bắt đầu và kết thúc

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
const int MAX_N = 110;
const int MAX_R = 15;

int n, r, fopt = INF, fcur, cmin = 1;
int batdau, dich;
int x[MAX_N], visited[MAX_N], route, xopt[MAX_N];
vector<int> spot_lines[MAX_R];
int C[MAX_N][MAX_N];

void TRY(int k){
    int size = spot_lines[route].size();
    
    if (k == size){
        if (C[x[k - 1]][dich] == 0) return;
        if(fcur + C[x[k - 1]][dich] < fopt){
            fopt = fcur + C[x[k - 1]][dich]; 
        }
    }
    
    for(int j = 1; j < size - 1; j++){
        int i = spot_lines[route][j];
        if(visited[i] == 0){
            x[k] = i; 
            // cout << "trong try " << i << endl;
            if (C[x[k-1]][i] == 0) continue;
            visited[i] = 1;
            fcur += C[x[k-1]][i];
            if (fcur + (size - k) * cmin < fopt) TRY(k + 1);
            visited[i] = 0;
            fcur -= C[x[k-1]][i];
        }
    }
}

void solve() {
    for (route = 1; route <= r; route++) {
        //B1: gan cho tat ca nhung diem khong co trong plan la da di qua
        memset(visited, 0, sizeof(visited));
        memset(x, 0 , sizeof(x));
        fopt = INF;
        fcur = 0;
        
        batdau = spot_lines[route][0];
        int size = spot_lines[route].size();
        dich = spot_lines[route][size - 1];
        
        visited[batdau] = 1; visited[dich] = 1; x[1] = batdau;
        //B2: bat dau di
        TRY(2);
        
        if (fopt == INF) fopt = 0;
        cout << fopt << endl;
    }
}

void input() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j]; 
        }
    }
    
    string line;
    getline(cin, line);
    
    for (int i = 1; i <= r; i++) {
        getline(cin, line);
        istringstream iss(line);
        
        int num;
        while (iss >> num) {
            spot_lines[i].push_back(num);
        }
    }
    
}

int main() {
    input();
    solve();
    
    return 0;
}
