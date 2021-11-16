// Write a C program, print_diary.c, which prints the contents of the
// file $HOME/.diary to stdout.
// The lecture example getstatus.c shows how to get the value of an 
// environment variable.
// 
// snprintf is a convenient function for constructing the pathname of the
// diary file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the pathname
    char* home_pathname = getenv("HOME");
    if (home_pathname == NULL) {
        return 1;
    }
    char* diary = ".diary";
    // create a new string with enough space to add the two strings together
    // get total size
    int size = strlen(home_pathname) + strlen(diary) + 2; // add space for / and \0
    char diary_pathname[size];
    snprintf(diary_pathname, size, "%s/%s", home_pathname, diary);
    
    // open the file -> remember previous tutlabs
    FILE* fp = fopen(diary_pathname, "r"); 
    if (fp == NULL) {
        perror(diary_pathname);
        return 1;
    }
    
    // print the contents to stdout.
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
    }
    fclose(fp);
    
    return 0;
}