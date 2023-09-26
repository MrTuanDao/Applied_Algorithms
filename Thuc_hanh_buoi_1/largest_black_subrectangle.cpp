#include <bits/stdc++.h>
using namespace std;

// Sử dụng kiến thức từ bài tính largestRectangleInHistogram với đầu vào là chiều cao của các cột trong list, 
// bằng cách sử dụng stack để chứa index và height của từng cột
// Time: O(n*m)
// Storage: O(m)

#define N 1000
#define M 1000

int n, m, matrix[N][M];
int largestRectangleArea(int heights[]){ // Input: danh sách các chiều cao -> Output: diện tích hình chữ nhật rộng nhất trong các cột 
    stack<int> _stack;
    int maxArea = 0;

    for(int i = 0; i < m; i ++){
        int start = i;
        int height = heights[i];
        while(!_stack.empty() && height < _stack.top()){
            int end_height = _stack.top(); _stack.pop();
            int end_id = _stack.top(); _stack.pop();
            start = end_id;
            maxArea = max(maxArea, (i - end_id) * end_height);
        }

        _stack.push(start); _stack.push(height);
    }

    while(!_stack.empty()){
        int end_height = _stack.top(); _stack.pop();
        int end_id = _stack.top(); _stack.pop();
        maxArea = max(maxArea, (m - end_id) * end_height);
        }

    return maxArea;
}

int maximalRectangle(int matrix[N][M]){// Input: ma trận -> Output: hình chữ nhật rộng nhất trong matrix
    // lặp qua từng hàng và tính hình chữ nhật lớn nhất trong các cột tạo bởi hàng đó
    // Tìm kiếm largestRectanlge in histogram để hiểu rõ hơn 
    int heights[m] = {};
    int maxArea = 0;
    
    for(int i = 0; i< n ; i++){
        for(int j = 0; j< m; j++){
            int bit = matrix[i][j];
            if(bit == 1) heights[j] ++;
            else heights[j] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin>>matrix[i][j];
    }

    cout << maximalRectangle(matrix);
    return 0;
}
