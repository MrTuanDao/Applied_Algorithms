#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b; cin >> a >> b;
    //ý tưởng nhân từng vị trí với nhau nếu thừa ra thì cộng vào cái đằng trước
    int m = a.size(), n = b.size();
    vector<int> result(m + n, 0);
    // Duyệt qua từng cặp chữ số trong chuỗi a và b
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // Tính tích của hai chữ số và cộng vào vị trí tương ứng trong mảng result
            int product = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = product + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }
    bool check = 0;
    for(auto it = result.begin(); it != result.end(); it++) {
        if(check == 0 && *it != 0) check = 1;
        if(check) cout << *it;
        
    }
}
