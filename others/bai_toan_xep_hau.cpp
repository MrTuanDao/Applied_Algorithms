# include <bits/stdc++.h>
using namespace std;

int vitri[10];

bool UCV(int k, int i){ // hàng thứ k và cột thứ i
    // kiểm tra trên đường chéo với các quân hậu đã xếp trước nó
    for(int j = 1; j < k ; j ++){
        if ( k - j == i - vitri[j]) return false;
    }
    // kiểm tra trên đường thẳng với các quân hậu đã xếp trước nó
    for(int j = 1; j < k;  j++){
        if(vitri[j] == i) return false;
    }
    // đường ngang không cần kiểm tra bởi vì mình đang xếp các con hậu theo chiều ngang
    
    return true;
}

void ghiNhan(){
    for(int i = 1; i <= 8; i ++) cout<<vitri[i] << ' ';
    cout << endl;
}

void Try(int k){
    for(int i = 1; i<= 8 ; i++){
        if(!UCV(k, i)) continue;
        vitri[k] = i;
        if ( k == 8) ghiNhan();
        else Try(k+1);
        vitri[k] = 0;
    }
}

int main(){
    Try(1);
    return 0;
}
