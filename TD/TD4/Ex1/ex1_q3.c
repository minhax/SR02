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
    int f1,f2,fd,id,oc;
    int *shm;
    f1 = open(argv[1], O_RDWR);
    f2 = open(argv[2], O_RDWR);
    id = shmget(IPC_private, sigconf(int),0666);    //ouverture
    shm = shmat (id,NULL,0);                        //attachement
    pid = fork();
    if (pid==0){
        fd=f1;
    }
    else{
        fd=f2;
    }
    oc = copierfichier(fd,fileno(stdout));          //ecriture
    if(pid==0){
        *shm = oc;
        return 0;
    }
    wait(NULL); //equivalent à waitpid(pid)
    printf("%d octets copiés par le père",oc);
    printf("%d octets copiés par le fils",*shm);    //lecture dans le segment mémoire
    printf("%d octets copiés au total",oc+*shm);
    shmdt(shm);                                     //detachement
    shmctl(id,IPC_RMD,NULL);                        //suppression
}