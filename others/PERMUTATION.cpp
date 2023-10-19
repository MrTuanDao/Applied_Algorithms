//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 100;
int n;
int a[MAXN];

bool UCV(int k, int i){
    for(int j = 1; j < k ; j++) if(i == a[j]) return false;
    return true;
}

void ghiNhan(){
    for(int i = 1; i <= n ; i++ ) cout<<a[i]<<' ';
    cout<<endl;
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(UCV(k, i)) { // cứ áp đúng cái form của backtracking là ra :v
            a[k] = i;
            if (k == n) ghiNhan();
            Try(k + 1);
            a[k] = 0;
        }
    }
}

int main() 
{ 
    cin>>n;
    Try(1);
    return 0;
}
