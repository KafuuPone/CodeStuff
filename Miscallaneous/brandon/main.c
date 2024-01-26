#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "learn.h"

int main(int argc, char **argv)
{
    printf("Hello world!\n");
    int p=1;
    while(p<4){
       printf("argv[p]=%s\n",argv[p]);
       char str1[100]="";
       char str2[100]="";
       strcpy(str1,argv[p]);
       filterLegitimate(str1,str2);
       printAsciiArt(str2);
       p++;
    }


    return 0;
}
