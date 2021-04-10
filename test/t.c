#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])  
{  
    int i = 0;  
    printf("\ncm line args:\n");
    printf("\targv[ 0]: %s\n", argv[0]);
    while(argv[i] != NULL)
        printf("\targv[ %d]: %s\n", i, argv[i++]);

    i = 0;
    printf("\nev args:\n");
    while(envp[i] != NULL)
        printf("\tenvp[ %d]: %s\n", i, envp[i++]);
    
    return 0;
}
