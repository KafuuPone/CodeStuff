#include <iostream>
#include "classes.h"

#include "output.h"

//creates an array of file pointers
FILE** filearr(int tot) {
    FILE** output = (FILE**)malloc(tot*sizeof(FILE*)); //pointer for array of file pointers
    for(int i=0; i<tot; i++) {
        //only deals with 2 decimals
        char filename[] = "./Plot/body_00.csv";
        filename[12] = i/10+'0';
        filename[13] = i%10+'0';
        output[i] = fopen(filename, "w");
    }
    return output;
}

//records coords of all bodies
void retrievedata(FILE** files, const body* bodies, int tot) {
    for(int i=0; i<tot; i++) {
        if (files[i] != NULL)
            fprintf(files[i], "%lf, %lf, %lf\n", (bodies[i]).r.x, (bodies[i]).r.y, (bodies[i]).r.z);
    }
}

//close all files
void closefiles(FILE** files, int tot) {
    for(int i=0; i<tot; i++) {
        fclose(files[i]);
    }
}