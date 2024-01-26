#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //Declaration of variables
    int suit, rank, user_suit, user_rank;

    //Program picks a random card
    srand((unsigned)time(NULL));
    suit = rand()%4+1;
    rank = rand()%13+1;
    printf("Let's play a game of Guess the Card!\n\n");
    printf("Dealer picked a random card.\n\n");

    //User guess for card suit
    printf("What is the card suit?\n");
    printf("Enter 1 for SPADE; 2 for HEART; 3 for CLUB; 4 for DIAMOND: ");
    scanf("%d", &user_suit);

    //Check if guess is correct
    if(user_suit == suit)
        printf("You guessed right!\n\n");
    else
    {
        printf("You guessed wrong!\n\n");

        //Gives a hint if wrong
        printf("Hint: The color of the card is %s.\n", (suit%2)?"Black":"Red");

        //Second guess from user
        printf("What is the card suit?\n");
        printf("Enter 1 for SPADE; 2 for HEART; 3 for CLUB; 4 for DIAMOND: ");
        scanf("%d", &user_suit);

        //Check if second guess is correct
        if(user_suit == suit)
            printf("You guessed right!\n\n");
        else
            printf("You guessed wrong!\n\n");
    }

    //User guess for card rank
    printf("What is the card number?\n");
    printf("Enter a number between 1 and 13: ");
    scanf("%d", &user_rank);

    //Check if guess is correct
    if(user_rank == rank)
        printf("You guessed right!\n\n");
    else
    {
        //Gives a hint
        printf("Your guess is too %s.\n", (user_rank>rank)?"high":"low");

        //Second guess from user
        printf("One more chance. Enter a number between 1 and 13: ");
        scanf("%d", &user_rank);

        //Check if second guess is correct
        if(user_rank == rank)
            printf("You guessed right!\n\n");
        else
            printf("You guessed wrong! The card number is %d.\n\n", rank);
    }

    return 0;
}
