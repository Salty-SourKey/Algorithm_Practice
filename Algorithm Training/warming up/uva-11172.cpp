#include <iostream>
using namespace std;
char ans[16];
int main(){
    int k, a, b;
    char c;
    cin >> k;
    while(k--){
        cin >> a >> b;
        c = ( a > b ) ? '>' : ((a < b) ? '<' : '=');
        cout << c << endl;
    }

    return 0;

}