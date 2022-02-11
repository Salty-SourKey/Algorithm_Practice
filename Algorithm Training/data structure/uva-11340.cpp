#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N, K, M, cost;
    char ch;
    double ans;
    string sentence;
    cin >> N;
    map<char, int> dict;                  //map을 python의 dict 처럼 사용하자

    while(N--){
        ans = 0.0;
        dict.clear();
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> ch >> cost;
            dict.insert({ch, cost});
        }
        cin >> M;
        cin.ignore();                    //stdin 버퍼에 남아있는 개행문자 무시
        for(int i = 0; i < M; i++){
            getline(cin, sentence);

            for(int j = 0; j < sentence.length(); j++){
                if(dict.find(sentence[j]) != dict.end())   //map.find에서 찾지 못했다면 map.end()를 return하니..
                    ans += dict[sentence[j]];              //map[key]는 value를 return
            }
        }
        printf("%0.2lf$\n", ans/100);
    }
    return 0;
}