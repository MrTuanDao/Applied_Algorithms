#include<bits/stdc++.h>
using namespace std;

map<char, char> parenthesis = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool checkParen(string target){
    
    stack <char> mystack; mystack.push(target[0]);
    
    for(int i = 1 ; i < target.size() ; i ++){
        char parenRight = target[i];
        if(parenthesis.find(parenRight) == parenthesis.end()){ // nếu là dấu đóng ngoặc thì so nó với top stack
            if(mystack.empty()) return false;
            char parenLeft = mystack.top(); mystack.pop();
            if(parenthesis[parenLeft] != parenRight) return false;
        } // nếu là dấu mở ngoặc thì append vào
        else mystack.push(parenRight);
    }
    return !mystack.size();

}

int main(){
    string target; cin >> target;
    cout<<checkParen(target);
    
    return 0;
}
