/*
Dao Quoc Tuan 20210891
ý tưởng: đưa về bài toán đơn giản hơn khi ta có 1 mảng cho biết,
index của nó có các đối thủ là các giá trị nằm trong index đó
Khi đã biết điều đó, ta áp dụng bfs và gán giá trị để phân nhóm cho từng index
Time: O(m + n + m)
Storage: O(m)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n,m;
vector <int> graph[MAXN];
int val[MAXN] = {}; // ô i chứa giá trị của nút i, nhóm 1 -> 1, nhóm 2  -> -1

void input(){ //hàm này giúp nhập vào các đỉnh và tạo một mảng mà mảng i chứa các đối thủ của i(do các đỉnh chạy từ 1 đến n)
    cin>>n>>m;
    // int temp = m;
    while(m--){
        int x, y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return;
}

bool bfs(int i){ // hàm này thực hiện trả về false nếu phát hiện hai nút ở cùng 1 nhóm, đồng thời điền giá trị cho từng nút đi qua theo chiều rộng
    if(val[i] != 0) return true; // làm như thế này để tránh những đồ thị rời, thì gán nhóm như nào cũng được    
    
    val[i] = 1;
    queue <int> q; q.push(i);
    
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j = 0 ; j < graph[i].size(); j++){
            int enemy = graph[i][j];
            if (val[enemy] == val[i]) return false;
            else if (val[enemy] == 0){
                val[enemy] = -1 * val[i];
                q.push(enemy);
            }
        }
    }
    return true;
    
}

bool solve(){ // hàm này nhận vào mảng đã tạo ở trên và thực hiện bfs 
    for(int i = 1; i<=n; i++) if (!bfs(i)) return false;
    return true;
}



int main(){
    input(); //hàm này giúp nhập vào các đỉnh và tạo một mảng mà mảng i chứa các đối thủ của i(do các đỉnh chạy từ 1 đến n)
    cout<<solve(); // hàm này nhận vào mảng đã tạo ở trên và thực hiện bfs 

    return 0;
}
