#include<bits/stdc++.h>
using namespace std;

const int MAXN = 30 + 5;
vector<int> T[MAXN]; // những giáo viên có thể dạy môn thứ i
int x[MAXN]; // course thứ i đã có ông nào dạy
int load[MAXN] = {};
int m, n, conflicts_num;
bool conflicts[MAXN][MAXN];
int res = 99;

void input(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int course_num, course_id;
        cin >> course_num;
        for(int j = 0; j < course_num; j++){
            cin >> course_id;
            T[course_id].push_back(i);
        }
    }

    cin >> conflicts_num;
    for(int i = 0 ; i < conflicts_num; i++){
        int u, v;
        cin >> u >> v;
        conflicts[u][v] = conflicts[v][u] = true;
    }
}

bool check(int t, int k){
    for(int i = 1 ; i <= k; i++){
        if(x[i] == t && conflicts[i][k]) return false; // nếu ông t đã dạy môn i mà môn i conflicts với k thì false
    }
    return true;
}

void update_res(){
    int max_load = -1;
    for(int i = 1; i <= m; i++) max_load = max(max_load, load[i]);
    res = min(res, max_load);
}

void TRY(int course){
    for(int i = 0; i < T[course].size(); i++){
        int t = T[course][i];
        if (check(t, course)){
            x[course] = t;
            load[t] += 1;
            
            if (course == n) update_res();
            else if (load[t] < res) TRY(course + 1);
            
            load[t] -= 1;
        }
    }
}

int main(){
    input();
    TRY(1);
    cout << res;
    return 0;
}
