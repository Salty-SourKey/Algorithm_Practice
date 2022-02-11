#include <iostream>

using namespace std;

int main(){
    long long SZ, P, idx, num, coor, line, col;
    while(cin >> SZ >> P, SZ && P){
        idx = SZ;
        for(long long i = SZ; i > 0; i = i - 2){
            if(P >= i * i){
                num = i;
                break;
            }
            else idx--;           
        }
        
        coor = num * num;
        line = idx;
        col = idx;


        if(P != coor){
            coor++;
            line++;
        }
        for(int i = 0; i < num; i++){
            if(coor == P) break;
            coor++;
            col--;
        }
        if(P != coor){
            coor++;
            line--;
        }
        for(int i = 0; i < num; i++){
            if(coor == P) break;
            coor++;
            line--;
        }
        if(P != coor){
            coor++;
            col++;
        }
        for(int i = 0; i < num; i++){
            if(coor == P) break;
            coor++;
            col++;
        }
        if(P != coor){
            coor++;
            line++;
        }
        for(int i = 0; i < num; i++){
            if(coor == P) break;
            coor++;
            line++;
        }


        cout << "Line = " << line << ", column = " << col << "." << endl; 
        
    }
    return 0;
}