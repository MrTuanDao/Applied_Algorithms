/*
Dao Quoc Tuan 20210891
Dat 3/5 mau test tren he thong hustack, co 1 mau test, kiem nghiem lai thay he thong sai ket qua
Ap dung phuong phap nhanh can, phan course cho tung giao vien
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 15, MAXN = 35;
int m, n;
int min_of_max_load = 99;
set <int> courses[MAXM]; // courses mà mỗi giáo viên dạy 
set <int> teaching[MAXM]; // môn mà giáo viên sẽ dạy 
set <int> conflicts[MAXN]; // các khóa học conflicts với nhau

bool found(int course, int course2) {
    return conflicts[course2].count(course) > 0;
}

bool UCV(int course, int teacher) {
    if (courses[teacher].count(course) == 0) return false;
    
    // conflict với khóa học mà GV đã dạy
    for( const int& course_assigned : teaching[teacher]) if(conflicts[course_assigned].count(course) > 0) return false;
    return true;
}
void update_best(){
    int max_load = 0;
    
    for(int teacher = 1; teacher <= m ; teacher++) max_load = max(max_load, (int)teaching[teacher].size());
    
    // In ra lời giải trong trường hợp muốn xem lời giải có hợp lý không 
    // for(int i = 1; i <= m; i++){
    //     for( const int& element : teaching[i]) cout<<element << ' ';
    //     cout << endl;
    // }
    // cout << "Max load la "<< max_load << endl << endl;
    
    min_of_max_load = min(max_load, min_of_max_load);
}

void Try(int course) {// course choose teacher
    for(int teacher = 1; teacher <= m ; teacher++){
        if(UCV(course, teacher)){
            teaching[teacher].insert(course);
            
            if (course == n) update_best();
            else if( (int)teaching[teacher].size() < min_of_max_load) Try (course + 1);
            
            auto it = teaching[teacher].find(course);
            teaching[teacher].erase(it);
        }
    }
}

int main(){
    scanf("%d %d", &m, &n); 
    for(int i = 0; i <= m  ; i ++){ // bỏ một hàng vì nó nhập vô là rỗng :v tôi cũng chưa biết là thế nào nhưng code nó cho input đúng là bus
        string input;
        getline( cin, input);
        stringstream ss(input);
        
        int num;
        while(ss >> num) courses[i].insert(num);
    }
    
    
    int k; cin >> k; 
    while(k--){
        int c1, c2; cin >> c1 >> c2;
        conflicts[c1].insert(c2);
        conflicts[c2].insert(c1);
    }

    Try(1);
    cout<<min_of_max_load;
    return 0;
}
