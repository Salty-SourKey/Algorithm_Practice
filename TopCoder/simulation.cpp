#include <iostream>
#include <vector>

using namespace std;

class KiwiJuiceEasy{
    public:
        vector<int> thePouring(vector<int> capacities,
        vector<int> bottles,
        vector<int> fromId, vector<int> toId)
    {
        for(int i = 0; i < fromId.size(); ++i){
            int f = fromId[i];
            int t = toId[i];
            int vol = min(bottles[f], capacities[t]-bottles[t]);
            bottles[f] -= vol;
            bottles[t] += vol;
        }
        return bottles;
    }
};

