#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UPPER 200

int randint(int, int);
int compare(int, int);

int main(void)
{
    /*Introduction of game*/
    printf("Let's play the game of 'Guess the number'.\n");
    printf("Guess the number between 1 and %d (inclusive).\n\n", UPPER);

    srand((unsigned)time(NULL)); /*Generates seed for rand()*/

    /*Declares and initializes variables for later use*/
    int number=randint(1, UPPER), guess, n, range_l = 1, range_u = UPPER;

    for(n=1; n<=7; n++)
    {
        /*Starts the turn and gets guess for turn*/
        printf("Turn %d\n", n);
        printf("Enter your guess: ");
        scanf("%d", &guess);

        /*Deals with inputs that are out of range, prompt for input again*/
        int c;
        for(c=1; c<=5&&(guess>range_u||guess<range_l); c++)
        {
            printf("The number exists between %d and %d.\n", range_l, range_u);
            printf("Enter your guess again: ");
            scanf("%d", &guess);
        }
        if(c>5)
        {
            printf("The number exists between %d and %d.\n\n", range_l, range_u);
        }
        else /*Only runs if input is in range*/
        {
            if(compare(guess, number)==0)
            {
                printf("The guess is correct.\n\n");
                break;
            }
            else if(compare(guess, number)<0)
            {
                printf("The guess is too low.\n\n");
                range_l = guess+1;
            }
            else
            {
                printf("The guess is too high.\n\n");
                range_u = guess-1;
            }
        }
    }

    /*Runs when all 7 guesses are wrong*/
    if(n>7)
        printf("You lost the game. The number is %d.", number);

    return 0;
}

/*Generates integer between 2 integers (inclusive)*/
int randint(int a, int b)
{
    return rand()%(b-a+1)+a;
}

/*Output<0, i<n; Output=0, i=n; Output>0, i>n*/
int compare(int i, int n)
{
    return i-n;
}
