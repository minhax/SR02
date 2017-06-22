#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
main() {
	int* projection;
	int i;
	int fd=open("titi.dat",O_RDWR,0666);
	struct stat filestate;
	stat("titi.dat", &filestate);
	projection = (int*)mmap(NULL,filestate.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);
	while (1) {
		scanf("%d", &i);
	//	printf("i: %d\n", i);
		if (i==99){
			return 0;
		} else {
			for (i=0;i<10;i++) printf("%d\n",projection[i]);
		}
	}
	return 0;
}
