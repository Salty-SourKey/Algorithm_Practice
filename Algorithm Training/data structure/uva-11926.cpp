#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bool flag;
    int n, m, start, end, interval;
    bitset<1000001> calendar;
    while(cin >> n >> m, n | m){
        flag = true;
        calendar.reset();
        for(int i = 0; i < n; i++){
            cin >> start >> end;
            for(int j = start; j < end; j++)
                if(calendar[j]) flag = false;
                else calendar.set(j);
        }
        for(int i = 0; i < m; i++){
            cin >> start >> end >> interval;
            while(end <= 1000000){
                for(int j = start; j < end; j++){
                    if(calendar[j]) flag = false;
                    else
                        calendar.set(j);
                }
                start += interval;
                end += interval;
            }
        }
 
        if(flag) cout << "NO CONFLICT" << endl;
        else cout << "CONFLICT" << endl;
        
    }
    return 0;
}