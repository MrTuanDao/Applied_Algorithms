/*
Greedy approach, giả sử ta có các cặp start end đã được sắp xếp, 
khi xuất hiện hai đoạn trùng nhau, phương án tốt nhất 
là loại bỏ đoạn mà có điểm kết thúc xa hơn bởi vì 
đằng sau đoạn kết thúc nhỏ hơn có khả năng có đoạn khác
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> intervals;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int start, end; cin >> start >> end;
        intervals.push_back(make_pair(start, end));
    }
    sort(intervals.begin(), intervals.end());
    
    int prevEnd = intervals[0].second;
    int drop = 0;
    for(auto it = intervals.begin() + 1; it != intervals.end(); it++){
        pair<int, int> pair = *it;
        if(pair.first <= prevEnd) {
            drop++;
            prevEnd = min(prevEnd, pair.second);
        }
        else prevEnd = pair.second;
    }
    
    cout << n - drop; 
    return 0;
}
