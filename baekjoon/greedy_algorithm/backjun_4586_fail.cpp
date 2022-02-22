#include <stdio.h>
int main()
{
    long long int temp_denom, temp_numer, i, k = 0;
    long long int denom_arr[1000];
    long long int numer_arr[1000];
    i = 0;
    while(1){
        scanf("%lld%lld", &numer_arr[i], &denom_arr[i]);
        if(numer_arr[i] == 0 && denom_arr[i] == 0) break;
        else i++;
    }
    while(numer_arr[k] != 0 && denom_arr[k] != 0){
        i = 1;
        temp_numer = numer_arr[k];
        temp_denom = denom_arr[k];
        while((long double)temp_numer/ temp_denom > 0){
            if(i*temp_numer-temp_denom>0){
                if(temp_denom*i>=1000000){
                    temp_numer = temp_numer*++i - temp_denom;
                    printf("%lld ",i);
                    temp_denom *= i;
                    continue;
                }
                else{
                    temp_numer = temp_numer*i - temp_denom;
                    printf("%lld ",i);
                    temp_denom *= i;
                }
            }
            if(i*temp_numer-temp_denom == 0){
                printf("%lld ",i);
                break;
            }
            i++;
        }
        k++;
        printf("\n");
    }
    return 0;
}