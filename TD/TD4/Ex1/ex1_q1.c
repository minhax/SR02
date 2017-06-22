#include "sharemem.h"

int copierfichier(int f1, int f2){
    int octlus=0,octcopies=0,octecris=0;
    char buf[MAXSIZE];
    while (1){
        if ((octlus=read(f1,buf,MAXSIZE))<=0)break;
        if ((octecris=write(f2,buf,octlus))<=0)break;
        octcopies+=octlus;
    }
    return octcopies;
}

int main(){
    int f1=open("f1.txt",O_RDWR);
    int f2=open("f2.txt",O_RDWR);
    copierfichier(f1,f2);
}