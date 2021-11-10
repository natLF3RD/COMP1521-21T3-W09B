// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    // Loop through all files given.
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

// chmod a file if publically-writeable
void chmod_if_needed(char *pathname) {
    // get original value
    struct stat sb;
    
    if (stat(pathname, &sb) == -1) {
        perror(pathname);
        return;
    }
    
    if ((sb.st_mode & S_IWOTH) != 0) {
        printf("removing public write from %s\n", pathname);
        mode_t new_mode = sb.st_mode & ~S_IWOTH;
        if (chmod(pathname, new_mode) == -1) {
            perror("chmod");
            return;
        }
    } else {
        printf("%s is not publically writable\n", pathname);
    }
    
}




