#include <stdio.h>

/*Declare functions*/
void diarow(int);
void dia(int);

int main(void)
{
    /*Declare variables*/
    int a, b, result;
    char opr;

    /*Obtain input from user*/
    printf("Enter two numbers and an operator in the form\n");
    printf("number1 operator number2 (e.g. 4 - 2): ");
    scanf("%d %c %d", &a, &opr, &b);

    /*Display input numbers and diamonds*/
    printf("The first number is %d\n", a);
    dia(a);
    printf("The second number is %d\n", b);
    dia(b);

    /*Calculate result of input*/
    switch(opr)
    {
    case '+':
        result = a+b;
        break;
    case '-':
        result = a-b;
        break;
    case '*':
        result = a*b;
        break;
    default:
        result = -1;
    }

    /*Output result and diamonds if operator is valid*/
    if(result != -1)
    {
        printf("%d %c %d is %d\n", a, opr, b, result);
        dia(result);
    }
    else
        printf("Invalid operator %c\n", opr);

    return 0;
}

/*Prints a row of diamonds of certain number*/
void diarow(int n)
{
    int i;
    /*Top row*/
    for(i=0; i<n; i++)
        printf("/\\");
    printf("\n");
    /*Bottom row*/
    for(i=0; i<n; i++)
        printf("\\/");
    printf("\n");
}

/*Prints all diamonds in separate rows*/
void dia(int n)
{
    int i;
    /*Rows in 10s*/
    for(i=0; i<n/10; i++)
        diarow(10);
    /*Leftover*/
    if(n%10!=0)
        diarow(n%10);
}
