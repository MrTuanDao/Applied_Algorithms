#include<bits/stdc++.h>
using namespace std;
// cai dat bang mang
int front = 0, back = 0;
vector<int> queue_simul;

int main(){
    while(true){
        string query; cin >> query;
        if (query == "#") break;
        else if(query == "PUSH"){
            int x; cin >> x;
            queue_simul.push_back(x);
            back += 1;
        }
        else if(query == "POP"){
            if(back - front == 0) cout << "NULL" << endl;
            else{
                cout << *(queue_simul.begin() + front) << endl;
                front++;
            }        
        }
    }
    return 0;
}
