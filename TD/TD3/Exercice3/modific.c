#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

main() {
	int* projection;
	int i;
	int fd=open("titi.dat",O_RDWR,0666);
	struct stat filestate;

	stat("titi.dat", &filestate);
	projection = (int*) mmap(NULL,filestate.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0); //MAP_PRIVATE ne va pas permettre au fichier original d'être modifié
	close(fd);
//But du prog: Dès que l'utilisateur rentre un nombre existant dans le tableau, faire un +1?
	while (1) {
		scanf("%d", &i);
		//printf("i: %d\n", i);
		if (i==99){
			exit(0);
		} else {
			projection[i]++;// Qu'est-ce que ça fait exactement?
		}
	}

	munmap(projection,filestate.st_size);
	return 0;
}
