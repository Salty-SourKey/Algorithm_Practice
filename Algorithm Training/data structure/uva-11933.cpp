#include <iostream>

using namespace std;

int main(){
    unsigned int n, iter, a, b;
    bool flag;
    while(cin >> n, n > 0){
        a = 0;
        b = 0;
        iter = 1;
        flag = true;
        for(int i = 0; i < 32; i++){
            if(n & iter){
                if(flag)
                    a += (1 << i);
                else   
                    b += (1 << i);
                flag = !flag;
            }
            iter = iter << 1;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}