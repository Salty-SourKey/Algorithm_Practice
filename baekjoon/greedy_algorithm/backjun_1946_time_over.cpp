#include <iostream>
using namespace std;
int score_a[100000];
int score_b[100000];
int result[20];
int main()
{
    int t, temp, num, count;
    cin >> t;
    temp = t;
    for(int k = 0; k < t; k++){
        cin >> num;
        count = num;
        for(int i = 0; i < num; i++) cin >> score_a[i] >> score_b[i];
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if(score_a[i] > score_a[j] && score_b[i] > score_b[j]){
                    count--;
                    break;
                } 
            }
        }
        result[k] = count;
    }
    for(int i = 0; i < t; i++) cout << result[i] << endl;
    return 0;
}