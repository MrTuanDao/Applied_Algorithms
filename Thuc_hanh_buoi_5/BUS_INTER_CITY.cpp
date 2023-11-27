// Dao Quoc Tuan 20210891
#define MAX_N 5010
#define MAX_M 10010
#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[MAX_N];
int soChang[MAX_N];
int soChangTuXP[MAX_N];
vector<int> adj[MAX_N];
vector<int> next_adj_in_costG[MAX_N];
int visited[MAX_N];

priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > 
                min_path_sum_and_node;  // lưu trữ đường đi tới các đỉnh và đỉnh đó, 
                                        // cài đặt bằng priority_queue để nó tự sắp xếp 
                                        // theo mức độ tăng dần của đường đi

int shortest_path_from_start[MAX_N];

void input() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> c[i] >> soChang[i];
    }
    
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// run bfs make cost graph
void bfs(int k) {
    memset(visited, 0, sizeof(visited));
    memset(soChangTuXP, 0 , sizeof(soChangTuXP));
    
    queue<int> q;
    q.push(k); visited[k] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for (const int& next : adj[cur]) {
            if(visited[next] == 0) {
                soChangTuXP[next] = soChangTuXP[cur] + 1;
                if(soChangTuXP[next] <= soChang[k]) {
                    q.push(next);
                    next_adj_in_costG[k].push_back(next);
                    visited[next] = 1;
                }
            }
        }
    }
}

void make_cost_graph() {
    for (int i = 1; i <= n; i++) bfs(i);
}

// Apply Dijkstra

void djisktra() {
    memset(visited, 0, sizeof(visited));
    memset(shortest_path_from_start, 1, sizeof(shortest_path_from_start)); // ham memset kha quan trong
    shortest_path_from_start[1] = 0; visited[1] = 0;
    int cur_node = 1, cur_path_sum_w;
    min_path_sum_and_node.push({0, 1});
    
    while (!min_path_sum_and_node.empty()) {
        cur_node = min_path_sum_and_node.top().second;
        min_path_sum_and_node.pop();

        cur_path_sum_w = shortest_path_from_start[cur_node];
        visited[cur_node] = 1;
        
        if(cur_node == n) break;
        
        for(const int& next : next_adj_in_costG[cur_node]) {
            if (visited[next]) continue;
            
            int weight = c[cur_node];            
            if (shortest_path_from_start[next] > cur_path_sum_w + weight ){
                shortest_path_from_start[next] = cur_path_sum_w + weight;
                                                      
                // luu lai cac gia tri de tinh ra cai min 
                min_path_sum_and_node.push({shortest_path_from_start[next], next});
            }
        }
    }
}

int main() {
    input();
    make_cost_graph();
    djisktra();
    cout << shortest_path_from_start[n] << endl;
    
    return 0;    
}
