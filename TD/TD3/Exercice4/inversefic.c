fd// Ecrire un programme qui projette un fd en mémoire, ensuite il l’inverse (inverse son
// contenu) et affiche son nouveau contenu.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
    char * proj; //garder des char quand on écrit des char (on utilise des int )
    int fd;
    struct stat etat_fichier;
    long file_size;
    int i;
    char tmp;

    fd = open(argv[1], O_RDWR);
    stat(argv[1], &etat_fichier);
    file_size = etat_fichier.st_size;
    proj = (char *) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (proj == (char *) MAP_FAILED) {
        perror("mmap");
        exit(0);
    }
    close(fd);

    for (i = 0; i < file_size / 2; i++) {
        tmp = proj[i];
        proj[i] = proj[file_size-i-1];
        proj[file_size-i-1] = tmp;
    }

    munmap((void *)proj, file_size);

    return 0;
}
