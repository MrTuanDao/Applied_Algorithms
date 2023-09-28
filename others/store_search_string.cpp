#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> myset;
    
    while(1){
        string word; cin >> word;
        if(word.compare("*") == 0) break;
        myset.insert(word);
    }
    
    while(1){
        string query; cin >> query;
        if(query.compare("***") == 0) break;
        else if(query.compare("find") == 0){
            string word; cin >> word;
            if(myset.find(word) == myset.end()) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(query.compare("insert") == 0){
            string word; cin >> word;
            if(myset.find(word) == myset.end()) cout<<1<<endl;
            else cout<<0<<endl;
            myset.insert(word);
        }
    }
    
    return 0;
}
