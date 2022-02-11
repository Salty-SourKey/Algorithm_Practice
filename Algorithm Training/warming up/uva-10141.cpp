#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, p, max_met, met, ans = 1;
    double min_price, price;
    
    while(cin >> n >> p, n || p){
        string best, name, temp;
        min_price = 100000000000.0;
        max_met = 0;
        for(int i = 0; i < n; i++){
            cin.ignore();
            getline(cin, temp);
        }
        for(int i = 0; i < p; i++){
            getline(cin, name);
            scanf("%lf %d", &price, &met);
            if(max_met == met){
                if(min_price > price){
                    max_met = met;
                    min_price = price;
                    best = name;
                }
            }
            else if(max_met < met){
                max_met = met;
                min_price = price;
                best = name;
            }
            for(int i = 0; i < met; i++){
                cin.ignore();
                getline(cin, temp);
            }
        }
        if(ans > 1) cout << endl;
        printf("RFP #%d\n", ans);
        cout << best << endl;
        ans++;
    }
    return 0;
}