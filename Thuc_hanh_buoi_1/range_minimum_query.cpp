// ý tưởng là lưu trữ một bảng, cho phép lấy giá trị min từ i tới i + (2 mũ j) - 1
// vậy ta tạo mảng có n cột, có logarit cơ số 2 của n hàng

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 +5 ;
int n, m;
int minTable[30][MAXN];
int arr[MAXN];

void debugger(){//in ra bảng trong trường hợp cần kiểm tra lại bảng
	for (int j = 0; (1<<j) - 1 < n; j++){
		for (int i = 0 ; i <n; i++){
			cout<<minTable[j][i]<<' ';
		}
		cout<<endl;
	}
}

void precompute(){//khởi tạo mảng cần thiết
	for (int j = 0; (1<<j) - 1 < n; j++)
		for (int i = 0 ;i <n; i++)
			minTable[j][i] = 0;

	//bottom up
	//M[0][i] = i
	for(int i = 0; i < n; i++)
		minTable[0][i] = arr[i];
    
	for(int j = 1; (1<<j) - 1 < n; j++) {
        
		for(int i = 0; i + (1<<j) <= n; i++) {//lưu ý xác định đúng công thức giới hạn 
			minTable[j][i] = min(minTable[j-1][i], minTable[j-1][i + (1<<(j-1))] ); // sai lầm ở thiếu giấu ngoặc làm cho phép toán trở thành i + 1 tất cả mũ j - 1
        }
    }

    // debugger();
}

int rmq(int left, int right){
	int range = log2(right - left + 1);
	return min(minTable[range][left], minTable[range][right - (1<<range) + 1] );
}

int solve(){
	long long ans = 0;
	int left, right;
	cin>>n;
	for(int i = 0; i<n;i++) cin>>arr[i];
	precompute();
	cin >> m;
	for(int i = 0; i< m; i++){
		cin >> left >> right;
		ans += rmq(left, right);
	}
	return ans;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
	cout<<solve()<< endl;
	return 0;
}
