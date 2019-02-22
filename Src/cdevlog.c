#include "cdevlog.h"

void creat_file(){
    FILE *fp;
    fp = fopen(FILE_PATH, "w");
    fclose(fp);

    return;
}

void print_file(char *message){
    FILE *fp;
    fp = fopen(FILE_PATH, "a");
    fprintf(fp, message);
    fprintf(fp,"\n");
    fclose(fp);

    return;
}

void data_file(char *data){
    int i=0;
    FILE *fp;
    fp = fopen(FILE_PATH, "a");
    for(; *data!='\0'; data++, i++){
        fprintf(fp, "%x ",*data&0xFF);
    }
    fprintf(fp,"\n");
    data-=i;
    for(;*data!='\0';data++){
        for(i=7;i>=0;i--){
            if(*data>>i&1) fprintf(fp,"1");
            else fprintf(fp,"0");
        }
        fprintf(fp, " ");
    }
    fprintf(fp,"\n");
    fclose(fp);
    return;
}