#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#define N 2

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s\n: %d", msg, errno);
    exit(0);
}

pid_t Fork(void) 
{
    pid_t pid;

    if ((pid = fork()) < 0)
	    unix_error("Fork error");
    return pid;
}

int main() {
    int i, status, sig, *ptr = 0;
    pid_t pid;

    printf("Fork error");

    for(i = 0; i < N; ++i) {
        if((pid = Fork()) == 0){
            *ptr = 2;

            exit(0);
        }
    }


    while((pid = wait(&status)) > 0) {
        if(WIFEXITED(status))
            printf("child %d terminated normally with eixt status=%d\n", pid, WEXITSTATUS(status));
        else if(WIFSIGNALED(status)){
            fprintf(stderr, "child %d terminated by signal %d: ", pid, sig = WTERMSIG(status));
            psignal(sig, "");
        }
        else 
            fprintf(stderr, "child %d terminated abnormally\n", pid);
    }

    if(errno != ECHILD)
        unix_error("waitpid error");

    exit(0);
}
