#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;


int main()
{   
    for(int i = 100000; i > 0; i--){
        cout << i << " ";
        if(i % 25 == 0) cout << endl;
    }
    return 0;
}