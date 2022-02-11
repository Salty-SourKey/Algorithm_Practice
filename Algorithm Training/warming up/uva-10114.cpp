#include <cstdio>


int main(){
    int month, num, idx, curMonth, dep_month[101];
    double rate[101], cur_rate, loan, value, pay, loan_pay;
    while(scanf("%d", &month), month > 0){
        idx = 0;
        cur_rate = 0.0;
        scanf("%lf %lf %d", &pay, &loan, &num);
        value = pay + loan;
        
        for(int i = 0; i < num; i++)
            scanf("%d %lf", &dep_month[i], &rate[i]);
        loan_pay = loan / month;
        for(curMonth = 0; curMonth <= 100; curMonth++){ 
            if(curMonth)
                loan -= loan_pay;
            if(curMonth == dep_month[idx])
                cur_rate = rate[idx++];
            value *= (1.0 - cur_rate);

            if(value > loan){
                printf("%d month", curMonth);
                if(curMonth == 1) printf("\n");
                else printf("s\n");
                curMonth = 101;
            } 
        }
    }
    
    return 0;
}
