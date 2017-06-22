#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct sigaction act_f;
struct sigaction act_p;

pid_t pid;


void handler_fils(){
	printf("temperature : %d", random()%30+10);
	fflush(stdout);
}

void handler_pere(){
	kill(pid,SIGUSR1);
	alarm (5);
}

int main(){
	pid = fork();

	if (pid==0){
		act_f.sa_handler= handler_fils;
		sigaction(SIGUSR1, &act_f, NULL);
		while (1){
			pause();
		}
	}
	else {
		act_p.sa_handler = handler_pere;
		sigaction(SIGALRM, &act_p, NULL);
		alarm(5);
		while (1) {
			sleep(1);
			printf("-");
			fflush(stdout);
		}
	}
	return 0;
}

Ex:2
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


struct sigaction act_f;
struct sigaction act_p;

char lettre_f [26]= "abcdefghijklmnopqrstuvwxyz";
char lettre_p [26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cpt_f = 1, idx_f = 0, idx_p = 0, cpt_p = 1;

pid_t pid;

void handler_fils(){
	for (int i = 0; i < cpt_f; i++){
		if(idx_f<26){
			printf("%c",lettre_f[idx_f]);
			fflush(stdout);
			idx_f++;
		}
	}
	cpt_f++;
	kill(getppid(),SIGUSR1);
}

void handler_pere(){
	for (int i = 0; i < cpt_p; i++){
		if(idx_p<=25){
			printf("%c", lettre_p[idx_p]);
			fflush(stdout);
		}
		idx_p++;
	}
	cpt_p++;
    kill(pid,SIGUSR1);
}


int main(int argc, char const *argv[]) {
	pid = fork ();
	if(pid == 0){
		act_f.sa_handler=handler_fils;
		sigaction(SIGUSR1,&act_f, NULL);
		while(1){
			pause();
		}
	}
	else {
		act_p.sa_handler=handler_pere;
		sigaction(SIGUSR1,&act_p, NULL);
		sleep(1);
		kill(pid, SIGUSR1);
		while(1){
			pause();
		}
	}
    return 0;
}

Ex:3
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void captpere(){
	nbsp ++;
	if(nbsp==3){
		printf("Trois signaux reçus : fin.");
		exit(0);
	}
}

void captfils(){
	nbsp++;
	rectvert(2);
	if(nbsp==3){
		printf("Trois signaux reçus : fin.");
		exit(1);
	}
}

void fonction_fils() {
	initrec();
	act_f.sa_handler=captfils;
	sigaction(SIGINT,&act_f,NULL);
	while (i !=-1){
		i = attendreclic();
		if(i==0)
			kill(getppid(),SIGINT);
		}
	detruitrect();
}

void fonction_pere() {
	act_p.sa_handler=captpere;
	sigaction(SIGINT,&act_p,NULL);
	while (1){
		n = sleep(10);
	}
	printf("Temps restant : %d s",n)
}

int main(int argc, char const *argv[]) {
	pid = fork();
	if(pid==0) fonction_fils();
	else fonction_pere();
    return 0;
}



