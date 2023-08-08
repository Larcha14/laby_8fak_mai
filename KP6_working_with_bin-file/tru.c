#include <stdio.h>
#include "flights.h"

int main(){
    flights fl;
    for(int i=0;i<18;++i){
        scanf("%s%s%s%s%s%s%s%s%s%s", fl.sername, fl.initials, fl.sex, fl.baggage, fl.company, fl.flight, fl.date, fl.time, fl.from, fl.to);
        printf("%s ", fl.sername);
        printf("%s ", fl.initials);
        printf("%s ", fl.sex);
        printf("%s ", fl.baggage);
        printf("%s ", fl.company);
        printf("%s ", fl.flight);
        printf("%s ", fl.date);
        printf("%s ", fl.time);
        printf("%s ", fl.from);
        printf("%s \n", fl.to);
        
    }   
}