#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dayofweek(int day, int month, int year);
void quiz(void);

int main(void) {
    char loop;
    do{
        quiz();
        printf("Play again? (y/n): ");
        fflush(stdin);
        scanf("%c", &loop);
    }while(loop=='y'||loop=='Y');

    return 0;
}

int dayofweek(int day, int month, int year) {
    int f = (14-month)/12;
    int y = year-f;
    int m = month+12*f-2;
    return (day+y+(31*m)/12+y/4-y/100+y/400)%7;
}

void quiz(void) {
    //random seed
    srand((unsigned)time(NULL));
    int day, month, year;
    //generate year
    year = 100*(rand()%2+19)+10*(rand()%10)+(rand()%10);
    //generate month
    month = rand()%12+1;
    //generate day
    int leap = (year%4==0 && year%100!=0) || (year%400==0);
    int day_num = 31;
    if(month == 2)
        day_num = (leap)?29:28;
    else{
        int temp_m = month;
        if(temp_m > 7)
            temp_m--;
        if(temp_m%2 == 0)
            day_num = 30;
    }
    day = rand()%day_num+1;
    //output date
    printf("%d.%d.%d\n", day, month, year);

    //quiz
    while(1){
        printf("Day = ");
        int ans; scanf("%d", &ans);
        if(ans == dayofweek(day, month, year))
            break;
        else
            printf("Wrong\n");
    }
    printf("Correct\n");
}