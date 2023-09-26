#include <bits/stdc++.h>
using namespace std;
//Time: O(n) + O(m), n dòng log, m số điện thoại khác nhau
//Storage: O(n)
int main(){
    // ios_base::sync_with_stdio(0); //nhập dòng này bị lỗi input do nó xung đột với scanf()
    // cin.tie(0), cout.tie(0);

    map <string, int> call_from;
    map <string, int> call_time_map;
    int total_call;
    //vòng lặp while thứ nhất, nhập các thôn tin của các cuộc gọi
    while(true){
        string query; cin >> query;

        if(query.compare("call") == 0){
            char sdt_char_1[15], sdt_char_2[15];
            int y1,mm1,d1,h1,m1,s1,h2,m2,s2;
            scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d", &sdt_char_1,&sdt_char_2,&y1,&mm1,&d1,&h1,&m1,&s1,&h2,&m2,&s2);
            string sdt1 = sdt_char_1, sdt2 = sdt_char_2;
            call_from[sdt1] += 1;
            total_call += 1;

            int call_time = (h2-h1)*60*60 + (m2 - m1)*60 + (s2 - s1);
            call_time_map[sdt1] += call_time;

        }
        else break;
    }
    // vòng while thứ hai nhập các truy vấn
    int check = -1; // có cách khác là check với mỗi số điện thoại được nạp vào map 
    while(true){

        string query; cin >> query;
        if(query.compare("?check_phone_number") == 0) {
            if(check == 0) {
                continue;
            }
            else if (check == 1){
                cout<<1<<endl;
                continue;
            }
            for(map<string, int>::iterator iter = call_from.begin(); iter != call_from.end(); ++iter){
                string sdt = iter->first;
                if (sdt.size() > 10) {
                    check = 0;
                    break;
                }
            }
            check = 1;
            cout<<check<<endl;
            
        }
        else if (query.compare("?number_calls_from") == 0){
            string sdt; cin >> sdt;
            cout<<call_from[sdt]<<endl;
        }
        else if (query.compare("?number_total_calls") == 0) cout<<total_call<<endl;
        else if (query.compare("?count_time_calls_from") == 0){
            string sdt; cin >> sdt;
            cout<<call_time_map[sdt]<<endl;
        }
        else break;
    }

}
