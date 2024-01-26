#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//starting off with the data for ascii-alphabet/number/white-spaces
//arrays of items which will be included in the ascii conversion
char asciiCharactersL[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char asciiNumbersL[]="0123456789";
char asciiWhitespaceL[]=" !?#*()[],.";


//the ascii conversion equivalent for each of the elements which will be ascii converted
//ascii art conversion for upper case alphabets
//for the letter 'A'
char RA[5][6]={"   *  ",
               "  * * ",
               "  *** ",
               " *   *",
               " *   *"};
//for the letter 'B'
char RB[5][6]={" **** ",
               " *   *",
               " **** ",
               " *   *",
               " **** "};
//for the letter 'C'
char RC[5][6]={"  *** ",
               " *   *",
               " *    ",
               " *   *",
               "  *** "};
//for the letter 'D'
char RD[5][6]={" **** ",
               " *   *",
               " *   *",
               " *   *",
               " **** "};
//for the letter 'E'
char RE[5][6]={" *****",
               " *    ",
               " *****",
               " *    ",
               " *****"};
//for the letter 'F'
char RF[5][6]={" *****",
               " *    ",
               " *****",
               " *    ",
               " *    "};
//for the letter 'G'
char RG[5][6]={"  *** ",
               " *   *",
               " * ***",
               " *  * ",
               "  *** "};
//for the letter 'H'
char RH[5][6]={" *   *",
               " *   *",
               " *****",
               " *   *",
               " *   *"};
//for the letter 'I'
char RI[5][6]={" *****",
               "   *  ",
               "   *  ",
               "   *  ",
               " *****"};
//for the letter 'J'
char RJ[5][6]={" *****",
               "   *  ",
               " * *  ",
               " * *  ",
               "  *   "};
//for the letter 'K'
char RK[5][6]={" *   *",
               " *  * ",
               " ***  ",
               " *  * ",
               " *   *"};
//for the letter 'L'
char RL[5][6]={" *    ",
               " *    ",
               " *    ",
               " *    ",
               " *****"};
//for the letter 'M'
char RM[5][6]={" *   *",
               " ** **",
               " * * *",
               " * * *",
               " *   *"};
//for the letter 'N'
char RN[5][6]={" *   *",
               " **  *",
               " * * *",
               " *  **",
               " *   *"};
//for the letter 'O'
char RO[5][6]={" *****",
               " *   *",
               " *   *",
               " *   *",
               " *****"};
//for the letter 'P'
char RP[5][6]={" **** ",
               " *   *",
               " **** ",
               " *    ",
               " *    "};
//for the letter 'Q'
char RQ[5][6]={"  *** ",
               " *   *",
               " * * *",
               " *  **",
               "  ****"};
//for the letter 'R'
char RR[5][6]={" **** ",
               " *   *",
               " **** ",
               " *  * ",
               " *   *"};
//for the letter 'S'
char RS[5][6]={"  ****",
               " *    ",
               "  *** ",
               "     *",
               " **** "};
//for the letter 'T'
char RT[5][6]={" *****",
               "   *  ",
               "   *  ",
               "   *  ",
               "   *  "};
//for the letter 'U'
char RU[5][6]={" *   *",
               " *   *",
               " *   *",
               " *   *",
               "  * *  "};
//for the letter 'V'
char RV[5][6]={" *   *",
               " *   *",
               "  * * ",
               "  * * ",
               "   *  "};
//for the letter 'W'
char RW[5][6]={" *   *",
               " *   *",
               " * * *",
               " * * *" ,
               "  * * "};
//for the letter 'X'
char RX[5][6]={" *   *",
               "  * * ",
               "   *  ",
               "  * * ",
               " *   *"};
//for the letter 'Y'
char RY[5][6]={" *   *",
               "  * * ",
               "   *  ",
               "   *  ",
               "   *  "};
//for the letter 'Z'
char RZ[5][6]={" *****",
               "    * ",
               "   *  ",
               "  *   ",
               " *****"};

//ascii art conversions for numbers
//for the number '0'
char R0[5][6]={"  *** ",
               " *   *",
               " *   *",
               " *   *",
               "  *** "};
//for the number '1'
char R1[5][6]={"   *  ",
               "  **  ",
               "   *  ",
               "   *  ",
               " *****"};
//for the number '2'
char R2[5][6]={"  *** ",
               " *   *",
               "    * ",
               "   *  ",
               " *****"};
//for the number '3'
char R3[5][6]={"  *** ",
               " *   *",
               "   ** ",
               " *   *",
               "  *** "};
//for the number '4'
char R4[5][6]={" * *  ",
               " * *  ",
               " *****",
               "   *  ",
               "   *  "};
//for the number '5'
char R5[5][6]={" *****",
               " *    ",
               " **** ",
               "     *",
               " **** "};
//for the number '6'
char R6[5][6]={"    * ",
               "   *  ",
               "  * * ",
               " *   *",
               "  *** "};
//for the number '7'
char R7[5][6]={" *****",
               "    * ",
               "   *  ",
               "  *   ",
               " *    "};
//for the number '8'
char R8[5][6]={"  *** ",
               " *   *",
               "  *** ",
               " *   *",
               "  *** "};
//for the number '9'
char R9[5][6]={"  *** ",
               " *   *",
               "  ****",
               "     *",
               "  ****"};

//ascii art conversion for whitespace
//for the whitespace ' '
char R_[5][6]={"      ",
               "      ",
               "      ",
               "      ",
               "      "};
//for the whitespace'!'
char Ra[5][6]={"   *  ",
               "   *   ",
               "   *   ",
               "       ",
               "   *   "};
//for the whitespace'?'
char Rb[5][6]={"  *** ",
               " *   *",
               "    * ",
               "      ",
               "    * "};
//for the whitespac,'#'
char Rc[5][6]={"  * * ",
               " *****",
               "  * * ",
               " *****",
               "  * * "};
//for the whitespace'*'
char Rd[5][6]={"   *  ",
               "   *  ",
               " *****",
               "  * * ",
               " *   *"};
//for the whitespace'('
char Re[5][6]={"  *   ",
               " *    ",
               " *    ",
               " *    ",
               "  *   "};
//for the whitespace')'
char Rf[5][6]={"  *   ",
               "   *  ",
               "   *  ",
               "   *  ",
               "  *   "};
//for the whitespace'['
char Rg[5][6]={" ***  ",
               " *    ",
               " *    ",
               " *    ",
               " ***  "};
//for the whitespace']'
char Rh[5][6]={"  *** ",
               "    * ",
               "    * ",
               "    * ",
               "  *** "};
//for the whitespace','
char Ri[5][6]={"      ",
               "      ",
               "   ** ",
               "   *  ",
               "  *   "};
//for the whitespace'.'
char Rj[5][6]={"      ",
               "      ",
               "      ",
               "  *** ",
               "  *** "};



//following part are the functions where the inputs from scanf will be processed
//this function takes in char *A and char *B,it extracts legitimate characters from char *A and puts them into char *B
void filterLegitimate(char *A,char *B){

    int v;
    int x;
    int y;
    int z;
    int q=strlen(*A);
    //sorting out legitimate characters
    for(v=0;v<q;v++){
       z=0;
       for (x=0;x<26;x++){
        if(A[v]==asciiCharactersL[x]){
            strncat(*B,A[v],1);
        }
       }
       for (y=0;y<10;y++){
         if(A[v]==asciiNumbersL[y]){
            strncat(*B,A[v],1);
         }
       }
       while (z<11){
       if(A[v]==asciiWhitespaceL[0]){
          strncat(*B," ",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[1]){
          strncat(*B,"a",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[2]){
          strncat(*B,"b",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[3]){
          strncat(*B,"c",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[4]){
          strncat(*B,"d",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[5]){
          strncat(*B,"e",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[6]){
          strncat(*B,"f",1);
          z++;
       }
       else if(A[v]==asciiWhitespaceL[7]){
          strncat(*B,"g",1);
          z++;
       }
        else if(A[v]==asciiWhitespaceL[8]){
          strncat(*B,"h",1);
          z++;
       }
        else if(A[v]==asciiWhitespaceL[9]){
          strncat(*B,"i",1);
          z++;
       }
        else if(A[v]==asciiWhitespaceL[10]){
          strncat(*B,"j",1);
          z++;
       }
      }
    }
}
//this function takes the previously assigned ascii art form by rows and put them into strings according to
//char *c,then prints the strings out one by one,into the desired ascii art form
 void printAsciiArt(char *C){

      int k;
      int m;
      int n;
      //assign ing strings to hold different rows of ascii art
      char r[5][500]={"","","","",""};
      k=strlen(*C);

      //forming ascii art str
      //to make up string char r[5][500]
      m=0;
      n=0;
      while (n<5){
         while (m<k) {
            switch (C[m]){    //it takes in string C to match the characters one by one then carry out commands according to different characters
                case 'A':
                    strncat(r[n],RA[n],6);
                    m++;
                    break;
                case 'B':
                    strncat(r[n],RB[n],6);
                    m++;
                    break;
                case 'C':
                    strncat(r[n],RC[n],6);
                    m++;
                    break;
                case 'D':
                    strncat(r[n],RD[n],6);
                    m++;
                    break;
                case 'E':
                    strncat(r[n],RE[n],6);
                    m++;
                    break;
                case 'F':
                    strncat(r[n],RF[n],6);
                    m++;
                    break;
                case 'G':
                    strncat(r[n],RG[n],6);
                    m++;
                    break;
                case 'H':
                    strncat(r[n],RH[n],6);
                    m++;
                    break;
                case 'I':
                    strncat(r[n],RI[n],6);
                    m++;
                    break;
                case 'J':
                    strncat(r[n],RJ[n],6);
                    m++;
                    break;
                case 'K':
                    strncat(r[n],RK[n],6);
                    m++;
                    break;
                case 'L':
                    strncat(r[n],RL[n],6);
                    m++;
                    break;
                case 'M':
                    strncat(r[n],RM[n],6);
                    m++;
                    break;
                case 'N':
                    strncat(r[n],RN[n],6);
                    m++;
                    break;
                case 'O':
                    strncat(r[n],RO[n],6);
                    m++;
                    break;
                case 'P':
                    strncat(r[n],RP[n],6);
                    m++;
                    break;
                case 'Q':
                    strncat(r[n],RQ[n],6);
                    m++;
                    break;
                case 'R':
                    strncat(r[n],RR[n],6);
                    m++;
                    break;
                case 'S':
                    strncat(r[n],RS[n],6);
                    m++;
                    break;
                case 'T':
                    strncat(r[n],RT[n],6);
                    m++;
                    break;
                case 'U':
                    strncat(r[n],RU[n],6);
                    m++;
                    break;
                case 'V':
                    strncat(r[n],RV[n],6);
                    m++;
                    break;
                case 'W':
                    strncat(r[n],RW[n],6);
                    m++;
                    break;
                case 'X':
                    strncat(r[n],RX[n],6);
                    m++;
                    break;
                case 'Y':
                    strncat(r[n],RY[n],6);
                    m++;
                    break;
                case 'Z':
                    strncat(r[n],RZ[n],6);
                    m++;
                    break;
                case '1':
                    strncat(r[n],R1[n],6);
                    m++;
                    break;
                case '2':
                    strncat(r[n],R2[n],6);
                    m++;
                    break;
                case '3':
                    strncat(r[n],R3[n],6);
                    m++;
                    break;
                case '4':
                    strncat(r[n],R4[n],6);
                    m++;
                    break;
                case '5':
                    strncat(r[n],R5[n],6);
                    m++;
                    break;
                case '6':
                    strncat(r[n],R6[n],6);
                    m++;
                    break;
                case '7':
                    strncat(r[n],R7[n],6);
                    m++;
                    break;
                case '8':
                    strncat(r[n],R8[n],6);
                    m++;
                    break;
                case '9':
                    strncat(r[n],R9[n],6);
                    m++;
                    break;
                case '0':
                    strncat(r[n],R0[n],6);
                    m++;
                    break;
                case 'a':
                    strncat(r[n],Ra[n],6);
                    m++;
                    break;
                case 'b':
                    strncat(r[n],Rb[n],6);
                    m++;
                    break;
                case 'c':
                    strncat(r[n],Rc[n],6);
                    m++;
                    break;
                case 'd':
                    strncat(r[n],Rd[n],6);
                    m++;
                    break;
                case 'e':
                    strncat(r[n],Re[n],6);
                    m++;
                    break;
                case 'f':
                    strncat(r[n],Rf[n],6);
                    m++;
                    break;
                case 'g':
                    strncat(r[n],Rg[n],6);
                    m++;
                    break;
                case 'h':
                    strncat(r[n],Rh[n],6);
                    m++;
                    break;
                case 'i':
                    strncat(r[n],Ri[n],6);
                    m++;
                    break;
                case 'j':
                    strncat(r[n],Rj[n],6);
                    m++;
                    break;
                case ' ':
                    strncat(r[n],R_[n],6);
                    m++;
                    break;
           }
         }
         n++;
         m=0;
      }

      //prints out ascii art strings
      printf("%s\n",r[1]);
      printf("%s\n",r[2]);
      printf("%s\n",r[3]);
      printf("%s\n",r[4]);
      printf("%s\n",r[5]);
}





