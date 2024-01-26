#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds)
{
    int in_time = time(NULL);
    while(1)
    {
        if(time(NULL)==in_time+seconds) break;
    }
}

int main(void)
{
    int mins, secs;
    printf("Min: ");
    scanf("%d", &mins);
    printf("Sec: ");
    scanf("%d", &secs);
    fflush(stdin);

    int tsec=60*mins+secs;
    printf("Press enter to start timer");
    getchar();
    system("cls");
    delay(1);

    while(tsec>=0)
    {
        printf("%02d:%02d", tsec/60, tsec%60);
        delay(1);
        tsec--;
        system("cls");
    }

    printf("Time's up!");
    return 0;
}
