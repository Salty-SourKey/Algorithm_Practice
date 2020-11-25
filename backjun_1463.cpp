#include <iostream>
#include <algorithm>
using namespace std;

int go_to_one(int x){
    if(x == 1) return 0;
    if(x < 1) return 1000001;
    return min(go_to_one(x/3) + x%3 + 1, go_to_one(x/2) + x%2 + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    cout << go_to_one(N);
    return 0;
}
