//Dao Quoc Tuan 20210891
#include <bits/stdc++.h> 
using namespace std;

int sudoku[20][20];
int res = 0;

bool UCV(int row, int col, int i){
    // check hang ngang
    for(int j = 1; j <= 9; j++) if( sudoku[row][j] == i ) return false;
    // check hang doc
    for(int j = 1; j <= 9; j++) if( sudoku[j][col] == i ) return false;
    // check o vuong 3x3
    int square_ngang = col - (col-1) % 3  , square_doc = row - ( row - 1) % 3;
    for(int j = square_doc ; j <= square_doc + 2; j++){
        for(int k = square_ngang ; k <= square_ngang + 2; k++){
            if( sudoku[j][k] == i ) return false;
        }
    }
    return true;
}

void Try(int row, int col){
    if(sudoku[row][col] == 0){
        for(int i = 1; i <= 9; i++){
            if(UCV(row, col, i)){ // cứ áp dụng đúng form quay lui :v, chắc quan trọng nhất là phần check ứng viên rồi 
                sudoku[row][col] = i;
                
                if(row == 9 && col == 9) res++;
                else if(col < 9) Try(row, col + 1);
                else Try(row + 1, 1);
                
                sudoku[row][col] = 0;
            }
        }
    }
    else{
        if(row == 9 && col == 9) res++;
        else if(col < 9) Try(row, col + 1);
        else Try(row + 1, 1);
    }
}

int main() 
{   
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j<=9; j++) cin >> sudoku[i][j];
    
    Try(1,1);
    cout<<res;
    return 0;
}
