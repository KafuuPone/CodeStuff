#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define G 15

int bounce_y(float t, int h, float g);
void delay(int mili);

int main(void)
{
    int h;
    printf("Input positive integer h: ");
    scanf("%d", &h);

    char disp[h+1];

    while(1)
    {
        float t=0;

        for(;t <= 2*sqrt(2*h/G);t+=0.1)
        {
            system("cls");

            for(int i=0; i<h+1; i++)
                disp[i] = ' ';

            disp[bounce_y(t, h, G)] = 'o';

            for(int i=h; i>=0; i--)
                printf("       %c\n", disp[i]);

            delay(100);
        }
    }

    return 0;
}

int bounce_y(float t, int h, float g)
{
    float coord = sqrt(2*g*h)*t-(g*t*t)/2;

    int output = (int)coord;
    if(coord-output >= 0.5)
        output++;

    return output;
}

void delay(int mili)
{
    clock_t start_time = clock();

    while(clock() < start_time + mili)
        ;
}
