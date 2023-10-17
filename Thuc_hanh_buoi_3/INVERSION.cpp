/* sử dụng mergesort để tính số inversion
mỗi lần mergesort sắp xếp mà lấy element ở array đằng sau thì 
số inversion tăng một lượng là số element ở array đằng trước
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 1e9 + 7;
int n;
int a[N];
int res = 0;

void merge(int l, int mid, int mid1, int r){
    int temp[r - l + 10], old_l = l, old_r = r, i = 1;
    while(l <= mid && mid1 <= r){
        if(a[l] <= a[mid1]) {
            temp[i] = a[l];
            l++;
        }
        else{
            temp[i] = a[mid1];
            mid1++;
            res = (res + (mid - l + 1) % M) % M;
        }
        i++;
    }
    
    for(int j = l; j <= mid; j++, i++) temp[i] = a[j];  
    for(int j = mid1; j <= r; j++, i++) temp[i] = a[j];
    for(int j = old_l, i = 1; j <= old_r; j++, i++) a[j] = temp[i];
}

void mergeSort(int l, int r){
    if(l == r) return;
    else if(l < r){
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, mid + 1, r);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    mergeSort(1, n);
    cout << res;
    return 0;
}
