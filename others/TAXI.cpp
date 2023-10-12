#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int dis_matrix[2*N][2*N];
int travelLog[2*N];
int visited[N];
int n, dis_min = INT_MAX;
int distances = 0, min_travel = INT_MAX;

void TRY(int k){
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            visited[i] = 1; travelLog[k] = i;
            if (k > 1) distances += dis_matrix[travelLog[k-1] + n][i] + dis_matrix[i][i + n];
            else distances += dis_matrix[travelLog[k-1]][i] + dis_matrix[i][i + n];
            if(k == n) {
                min_travel = min(min_travel, distances + dis_matrix[i + n][0]);
            }
            else if(distances + 2*(n - k) * dis_min < min_travel) TRY(k + 1);
            
            if (k > 1) distances -= dis_matrix[travelLog[k-1] + n][i] + dis_matrix[i][i + n];
            else distances -= dis_matrix[travelLog[k-1]][i] + dis_matrix[i][i + n];
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i <= 2*n ; i++){
        for(int j = 0; j <=2*n; j++) {
            int x; cin >> x;
            dis_matrix[i][j] = x;
            dis_min = min(dis_min, x);
        }
    }
    TRY(1);
    cout << min_travel;
    return 0;   
}
