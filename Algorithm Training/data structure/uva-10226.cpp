#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int num;
    double n;
    map<string, int> dict;
    string name;
    cin >> num;
    cout << fixed;
    cout.precision(4);  
    cin.ignore();
    cin.ignore();
    while(num--){
        n = 0.0;    
        while(getline(cin, name) && name.length() != 0){
            if(dict.find(name) != dict.end())
                dict[name]++;
            else
                dict.insert({name, 1});
            n += 1.0;
        }
        for(map<string, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
            cout << iter->first << " " << (iter->second / n) * 100 << endl;
        
        if(num) cout << endl;
        dict.clear();
    }
    return 0;
}