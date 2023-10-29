#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e3;
int a, b, c;
int count_step[MAXA][MAXA]; // count_step[i][j] số bước cần thiết để 
                            // đạt được trạng thái i và j

int main() {
    cin >> a >> b >> c;
    
    queue< pair<int, int> > q; q.push({0, 0});
    
    while ( !q.empty() ) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int step = count_step[x][y];
        
        // Nếu tìm ra lời giải
        if ( x == c || y == c ) {
            cout << count_step[x][y] << endl;
            break;
        }
        
        // 6 trường hợp có thể sinh ra từ (x, y) 
        if ( !count_step[a][y] ) {
            count_step[a][y] = step + 1;
            q.push({a, y});
        }
        
        if ( !count_step[x][b] ) {
            count_step[x][b] = step + 1;
            q.push({x, b});
        }
        
        if( !count_step[0][y] ) {
            count_step[0][y] = step + 1;
            q.push({0, y});
        }
        
        if ( !count_step[x][0] ) {
            count_step[x][0] = step + 1;
            q.push({x, 0});
        }
        
        if ( !count_step[ max(x + y - b, 0)][ min(x + y, b) ] ) {
            count_step[ max(x + y - b, 0)][ min(x + y, b) ] = step + 1;
            q.push({max(x + y - b, 0), min(x + y, b)});
        }
        
        if ( !count_step[ min(x + y, a)][max(x + y - a, 0) ] ) {
            count_step[ min(x + y, a)][max(x + y - a, 0) ] = step + 1;
            q.push({min(x + y, a), max(x + y - a, 0)});
        }
        
    }
    
    return 0;
}
