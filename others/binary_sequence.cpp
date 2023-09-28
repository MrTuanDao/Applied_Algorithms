#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int a[MAXN];
int n;

void GhiNhan(){
    for(int i = 1 ; i <= n; i++){
        cout<<a[i];
    }
    cout<<endl;
}

void backTracking(int k){
    for(int i = 0; i <= 1; i++){
        a[k] = i;
        if(k==n) GhiNhan();
        else if(k < n) backTracking(k+1);
    }
}

int main(){
    cin>>n;
    backTracking(1);
    return 0;
}
