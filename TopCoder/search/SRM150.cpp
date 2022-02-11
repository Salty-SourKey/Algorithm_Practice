#include <iostream>
#include <vector>
using namespace std;

class InterestingDigits{
    public:
        vector<int> digits(int base){
            vector<int> interestingDigit;
            for(int i = 2; i < base; ++i){
                if((base-1) % i == 0) 
                    interestingDigit.push_back(i);
            }
            /*
            for(int digit = 2; digit < base; ++digit){
                bool ok = true;
                for(int a = 0; a < base; ++a){
                    for(int b = 0; b < base; ++b){
                        for(int c = 0; c < base; ++c){
                            if((a*base*base + b*base + c) % digit ==0 && (a+b+c) % digit != 0){
                                ok = false;
                                break;
                            } 
                        }
                        if(!ok) break;
                    }
                    if(!ok) break;
                }
                if(ok) interestingDigit.push_back(digit);
            }
            */
            return interestingDigit;
        }
};

int main(){
    int digit;
    cin >> digit;
    InterestingDigits interesting;
    vector<int> ans = interesting.digits(digit);
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}