#include <bits/stdc++.h>
using namespace std;

int top = -1; // vi ban dau stack la rong
vector<int> simul_stack;

int main(){
    while(true){
        string query; cin >> query;
        if(query == "#") break;
        else if(query == "PUSH"){
            int x; cin >> x;
            simul_stack.push_back(x);
            top++;
        }
        else if(query == "POP"){
            if(top == -1) cout << "NULL" << endl;
            else {
                auto it = simul_stack.begin() + top;
                cout << *it << endl;
                simul_stack.erase(it);
                top--;
            }
        }
    }
    return 0;
}
