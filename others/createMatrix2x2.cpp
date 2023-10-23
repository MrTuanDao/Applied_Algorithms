/*
TÍnh số dư của số fibo thứ n cho 10^9 + 7.
(1 <= n <= 2^63 - 1)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 30; const ll MOD = 1e9 + 7;
int n;

typedef struct myMatrix{
    int a1, a2, a3, a4; 
    // |a1|a2|
    // |a3|a4|
} myMatrix;

myMatrix* multi(myMatrix* m1, myMatrix* m2){
    myMatrix* temp = new myMatrix();
    temp->a1 = m1->a1 * m2->a1 + m1->a2 * m2->a3;
    temp->a2 = m1->a1 * m2->a2 + m1->a2 * m2->a4;
    temp->a3 = m1->a3 * m2->a1 + m1->a4 * m2->a3;
    temp->a4 = m1->a3 * m2->a2 + m1->a4 * m2->a4;
    return temp;
}

myMatrix* Pow(ll n, myMatrix* matrix){
    if (n == 0) {
        myMatrix* temp = new myMatrix();
        temp->a1 = 1;
        temp->a2 = 0;
        temp->a3 = 0;
        temp->a4 = 1;
        return temp;
    }
    if (n % 2 != 0){
        return multi(matrix, Pow(n - 1, matrix));
    }
    myMatrix* res = Pow(n/2, matrix);
    return multi(res, res);
}

void printMatrix(myMatrix *m){
    cout << m->a1 << '|' << m->a2 << endl << m->a3 << '|' << m->a4 << endl;
}

// int calc(int n){
    
// }

int main(){
    myMatrix* baseMatrix = new myMatrix();
    baseMatrix->a1 = 1;
    baseMatrix->a2 = 1;
    baseMatrix->a3 = 1;
    baseMatrix->a4 = 0;
    printMatrix(Pow(10, baseMatrix));
    return 0;
}
