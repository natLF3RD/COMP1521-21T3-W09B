#include <stdio.h>

int main (int argc, char* argv[]) {
    // stdin and stdout are streams
    // fgets scanf getchar putchar printf etc..
    
    // first argv is string contianging the pathname of the the file we want to read from.
    // read from a file
    FILE * fp_read = fopen(argv[1], "r");
    if (fp_read == NULL) {
        perror("failed to open the read file");
    } else {
        int ch = fgetc(fp_read);
        while (ch != EOF && ch != '\n') {
            fputc(ch, stdout);
            ch = fgetc(fp_read);
        }
        
        fputc('\n', stdout);
    }
    fclose(fp_read);
    
    // write to a file.
    // FILE * fp_write = fopen(argv[2], "w");
    // if (fp_write == NULL) {
    //     perror("failed to open the write file");
    // } else {
    //     int ch = fgetc(stdin);
    //     while (ch != EOF && ch != '\n') {
    //         fputc(ch, fp_write);
    //         ch = fgetc(stdin);
    //     }
        
    //     ch = fgetc(stdin);
    //     // read another line.
    //     while (ch != EOF && ch != '\n') {
    //         fputc(ch, fp_write);
    //         ch = fgetc(stdin);
    //     }
    // }
    // fclose(fp_write);
    
    // append to an existing file
    FILE * fp_app = fopen(argv[3], "a");
    if (fp_app == NULL) {
        perror("failed to open the write file");
    } else {
        int ch = fgetc(stdin);
        while (ch != EOF && ch != '\n') {
            fputc(ch, fp_app);
            ch = fgetc(stdin);
        }
        
    }
    

    return 0;
}