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
    int f1,f2,fd;
    f1 = open(argv[1], O_RDWR);
    f2 = open(argv[2], O_RDWR);
    pid_t pid=fork();
    if(pid==0)  fd=f1;
    else        fd=f2;
    int oc = copierfichier(fd,fileno(stdout));
    printf("%d octets copiés",oc );
}