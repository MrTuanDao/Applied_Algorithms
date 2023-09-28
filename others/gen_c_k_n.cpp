//CPP 
#include <bits/stdc++.h> 
using namespace std;

int  a[100] = {0};
int n,k;

void GhiNhan(){
    for(int i = 1; i <= k ; i ++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

void backtrack(int j){
    for(int i = a[j-1]+1; i <= n - (k-j); i++ ){
        // cout<<j;
        a[j] = i;
        if (j==k) GhiNhan();
        else backtrack(j+1);
    }
}

int main() 
{ 
    cin >> k >> n;
    backtrack(1);
    return 0;
}
