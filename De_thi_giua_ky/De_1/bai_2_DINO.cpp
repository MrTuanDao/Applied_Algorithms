#include <bits/stdc++.h>
using namespace std;

queue<int> hanhlang;
deque<int> chuong;

int n;

int main() {
    cin >> n;
    int x; 
    for (int i = 1; i <= n; i++) {
        cin >> x;
        chuong.push_back(x); 
    }
    
    char denhieu;
    
    while (cin >> denhieu) {
        if (denhieu == 'C') {
            x = chuong.front();
            chuong.pop_front();
            hanhlang.push(x);
        }
        else {
            x = hanhlang.front();
            hanhlang.pop();
            chuong.push_front(x);
        }
    }
    
    while (!chuong.empty()) {
        cout << chuong.front() << ' ';
        chuong.pop_front();
    }
    
    return 0;
    
    
}
