// Dao Quoc Tuan 20210891
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m;
set<int> mySet[N]; // lưu trữ tập các nút kề
int visited[N];

int main(){
    cin >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        mySet[x].insert(y);
        mySet[y].insert(x);
    }
    
    for(int i = 1; i <= n; i++){ // lặp qua từng nút và dfs từ nút đó
        if(visited[i]) continue;
        else{
            // dfs
            int cur = i, prevCur = i;
            visited[i] = 1;
            while(true) {
                cout << cur << ' ';
                prevCur = cur;
                // tim kiem phan tu tiep theo 
                for(auto it = mySet[cur].begin(); it != mySet[cur].end(); it++){
                    if(visited[*it]) continue;
                    else{
                        cur = *it;
                        visited[cur] = 1;
                        break;
                    }
                }
                if(cur == prevCur) break;
            }
        }
    }
    return 0;
}
