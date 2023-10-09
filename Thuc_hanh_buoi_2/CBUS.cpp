/*
Dao Quoc Tuan 20210891
Áp dụng phương pháp nhánh cận
Điều quan trọng nhất khi sử dụng phương pháp này đó là thiết kế hàm UCV, cũng tức là thiết kế cách duyệt sao cho hợp lý
Ý tưởng của tôi là kiểm tra điếm đến đã được thăm chưa, nếu điểm đến nhỏ hơn n thì còn ghế trống không, 
nếu điểm đến lớn hơn n thì đã có hành khách (k - n) trên xe hay chưa.
*/
// nhánh cận đạt 5/5 test case trên hustack
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
int n,seats;
int dis_matrix[2*MAXN][2*MAXN];
int coor[2*MAXN] = {0};//lưu những vị trí đã đi qua
int visited[MAXN];
int distances = 0;
int shortest = 9999999;

bool UCV(int k, int i){// kiểm tra xem i có phù hợp để điền vào coor[k] khkhông
    // Nếu i <=n thì phải có số hành khách < seats hành khác trên xe
    if (visited[i]) return false;
    if(i<=n){
        return seats > 0;
    }
    // Nếu i > n thì phải có hành khác i-n trong xe
    else{
        if(!visited[i-n]) return false;
    }       
}

void Try(int k){// thêm điểm dừng cho bước thứ k
    // Điều kiện dừng là xe bus đi được 2*(n+1) bước
    if (k == 2*n+1) {
        if(shortest > distances + dis_matrix[ coor[2*n] ][0]) shortest = distances + dis_matrix[ coor[2*n] ][0];
        return;
    }
    for(int i = 1; i <=2*n; i++){
        if(UCV(k, i)){// kiểm tra xem nó đi tới vị trí i tại lần đi thứ k có vi phạm điều gì không
            // Update biến trạng thái
            coor[k] = i;
            visited[i] = 1;
            distances += dis_matrix[ coor[k-1] ][i];
            if(i<=n) seats--;
            else seats++;
            
            if(distances + (2 * n - k)< shortest) Try(k+1);
            
            // Trả các biến trạng thái về trạng thái cũ
            coor[k] = 0;
            visited[i] = 0;
            distances -= dis_matrix[ coor[k-1] ][i];
            if(i<=n) seats++;
            else seats--;
        }
    }
}

int main(){
    cin >> n >> seats;
    for(int i = 0; i <=2*n; i++){
        for(int j = 0; j <=2*n; j++) cin >> dis_matrix[i][j];
    }
    Try(1);
    cout<<shortest;
    return 0;
}
