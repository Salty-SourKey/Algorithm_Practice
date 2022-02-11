#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class FriendScore{
public:
    int highestScore(vector<string> friends){
        int N = friends.size();
        int result = 0;
        for(int i = 0; i < N; ++i){
            int temp = 0;
            for(int j = 0; j < N; ++j){
                if(friends[i][j] != 'Y') continue;
                else{
                    temp++;
                    for(int k = 0; k < N; ++k){
                        if(friends[k][j] == 'Y' && k != i && friends[i][k] != 'Y') temp++;
                    }
                }
            }
            result = max(result, temp);
        }
        return result;
    }
};

int main(){
    vector<string> fr;
    int n;
    FriendScore score;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string temp;
        cin >> temp;
        fr.push_back(temp);
    }
    cout << score.highestScore(fr);
    return 0;
}