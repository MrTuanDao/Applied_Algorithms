/*
Bai toan chia banh 
Tai sao day la bai toan Binary Search
P(x) đúng nếu chia đươc
Đ Đ Đ Đ ... Đ S S S ... S
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
const double PI = M_PI;

double EPS = 1e-4,
       lo, hi;
int n, f;
double max_area = 0;
double area[MAXN];

bool P(double x){ // neu chia duoc so banh cho F + 1 nguoi thi la DUNG
    int sumPies = 0;
    for(int i = 1; i <= n; i++){
        int pies = area[i]/x;
        sumPies += pies;
    }
    if(sumPies >= f + 1) return true;
    return false;
}

int main(){

    cin >> n >> f;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x; area[i] = PI * x * x;
        max_area = max(max_area, area[i]);
    }
    
    lo = 0; hi = max_area;
    while(hi - lo > EPS){
        double mid = (lo + hi) / 2.0;
        if (P(mid) == true){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    
    printf("%.4f", lo);
    
    return 0;
}
