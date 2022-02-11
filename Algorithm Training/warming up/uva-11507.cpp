#include <iostream>
#include <string>

using namespace std;


int main(){
    int L;
    char input_sign, input_dir, sign, dir;
    while(cin >> L, L){
        sign = '+';
        dir = 'x';
        for(int i = 0; i < L-1; i++){
            cin >> input_sign >> input_dir;
            if(input_sign == 'N'); 
            else if(input_dir != dir){
                if(dir == 'x'){
                    dir = input_dir;
                    if(sign == '-')
                        sign = (input_sign == '-' ? '+' : '-');
                    
                    else
                        sign = input_sign;
                }
            }
            else{
                dir = 'x';
                if(sign == input_sign)
                    sign = '-';
                else
                    sign = '+';
            }
        }
        cout << sign << dir << endl;    
    }

    return 0;
}