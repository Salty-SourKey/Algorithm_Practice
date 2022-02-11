#include <iostream>
using namespace std;

int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

int main(){
    int k = 1 << 20;
    for(int i = 0; i < 8; i++){
        cout << "( ";
        for(int j = 0; j < 20; j++){
            if((i>>j)&1) cout << arr[j] << " ";
        }
        cout << ')' <<endl;
    }
    return 0;
}