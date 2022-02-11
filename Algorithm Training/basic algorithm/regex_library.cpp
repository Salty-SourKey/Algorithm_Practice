#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(){
    string S = "line: a70 and z72 will be replaced, aa24 and a872 will not";
    regex re("[a-zA-Z]?[0-9][0-9]{3,3}");
    cout << regex_replace(S, re, "*** ");
}
