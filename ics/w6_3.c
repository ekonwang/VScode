#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

#define TIMEOUT 5
#define MAXLINE 1024

jmp_buf buf;

void SIGALRM_handler(int signum){
	longjmp(buf, 1);
}

char *tfgets(char *s, int size, FILE *stream)
{
	if (signal(SIGALRM, SIGALRM_handler) == SIG_ERR)
	{
		perror("Failed to install SIGALRM_handler");
		return NULL;
	}
	else
	{
		alarm(TIMEOUT);
	}

	if (!setjmp(buf)){
		return fgets(s, size, stream);
	}else	
	{
		return NULL;
	}
}

int main(){
	char temp_bufer[MAXLINE];
	char *result = tfgets(temp_bufer, MAXLINE, stdin);
	
	if (result){
		printf("Input : %s\n", result);
	}else{
		fprintf(stderr, "Time out!\n");
	}
	
	return 0;
}