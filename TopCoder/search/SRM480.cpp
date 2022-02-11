#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Cryptography{
    public:
        long long encrypt(vector<int> numbers){
            sort(numbers.begin(),numbers.end());
            long long temp = ++numbers[0];
            for(int i = 1; i < numbers.size(); ++i) temp *= numbers[i];
            return temp;
        }
};
int main(){
    vector<int> numbers;
    int temp;
    for(int i = 0; i < 5; ++i){
        cin >> temp;
        numbers.push_back(temp);
    }
    Cryptography crp;
    cout << crp.encrypt(numbers);
    return 0;
}