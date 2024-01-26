#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//starting off with the data for ascii-alphabet/number/white-spaces
//arrays of items which will be included in the ascii conversion
//char asciiCharactersL[26];
//int asciiNumbersL[];
//char asciiWhitespaceL[];


//the ascii conversion equivalent for each of the elements which will be ascii converted
//ascii art conversion for upper case alphabets


//following part are the functions where the inputs from scanf will be processed
//this function takes in char *A and char *B,it extracts legitimate characters from char *A and puts them into char *B
void filterLegitimate(char *A,char *B);
//this function takes the previously assigned ascii art form by rows and put them into strings according to
//char *c,then prints the strings out one by one,into the desired ascii art form
void printAsciiArt(char *C);

