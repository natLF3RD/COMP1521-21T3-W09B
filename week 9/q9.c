
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/wait.h>

#define C_COMPILER "/usr/local/bin/dcc"


char* get_binary_name (char* path) {
    char *binary = strdup(path);
    char *pos = strchr(binary, '.');
    if (pos == NULL || *(pos+1) != 'c' || *(pos+2) != '\0') {
        fprintf(stderr, "%s is not a c file\n", binary);
        exit(1);
    }
    
    // chops off the end of the string.
    *pos = '\0';
    
    return binary;
}


int main (int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No file names provided.\n");
        return 1;
    }

    for (int i=1; i<argc; i++) {
        char* binary = get_binary_name(argv[i]);
        
        printf("%s %s -o %s\n", C_COMPILER, argv[i], binary);
        
        pid_t child_pid;
        char* p_args[] = {C_COMPILER, argv[i], "-o" , binary, NULL};
        
        extern char **environ;
        if (posix_spawn(&child_pid, C_COMPILER, NULL, NULL, p_args, environ) != 0) {
            perror("spawn");
            exit(1);
        }
        
        // always should do this after.
        int exit_status;
        if (waitpid(child_pid, &exit_status, 0) == -1) {
            // something failed to run tge program.
            perror("waitpid");
            exit(1);
        }
        
        // did the program execute successfully?
        if (exit_status != 0) {
            fprintf(stderr, "%s failed to complie.\n", argv[i]);
            exit(1);
        }
    }
    
    
}