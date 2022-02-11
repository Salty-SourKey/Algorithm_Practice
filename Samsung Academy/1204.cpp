#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, score, ans, maximum = 0;
        cin >> N;
        map<int, int> freq;
        for(int i = 0; i < 1000; i++){
            cin >> score;
            freq[score]++;
        }

        for(map<int,int>::iterator iter = freq.begin(); iter != freq.end(); iter++){
            if(maximum <= iter->second){
                maximum = iter->second;
                ans = iter->first;
            }
        }
        
        cout << "#" << N << " " << ans << endl;
    }
    return 0;
}