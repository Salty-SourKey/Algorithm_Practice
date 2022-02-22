#include <iostream>
#include <stdio.h>
using namespace std;
char DNA[1000][50];
int count[50][4];
int main()
{
    int m,n;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> DNA[i][j];
            if(DNA[i][j] == 'A') count[j][0]++;
            else if(DNA[i][j] == 'C') count[j][1]++;
            else if(DNA[i][j] == 'G') count[j][2]++;
            else if(DNA[i][j] == 'T') count[j][3]++;
        }
    }
    int max, max_index, sum = 0;
    for(int i = 0; i < m; i++){
        max = count[i][0];
        max_index =0;
        for(int j = 0; j < 4; j++){
            sum += count[i][j];
            if(max < count[i][j]){
                max = count[i][j];
                max_index = j;
            }
        }
        sum -= max;
        if(max_index == 0) cout << "A";
        else if(max_index == 1) cout << "C";
        else if(max_index == 2) cout << "G";
        else if(max_index == 3) cout << "T";
    }
    printf("\n%d", sum);
    return 0;
}