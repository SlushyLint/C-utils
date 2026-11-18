#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Only takes one arg, dumbass\n");
            return 1;
    } 
    FILE *file = fopen(argv[1], "r");
    //  file aparently returns something
    //  no fucking clue what

    // printf("\n%sO\n", file);
    // but ig its not a string

    // does Go bullshit work?
    if (file == NULL) {
        printf("No input file");
        return 1;
    }
    char buf[1024];     // buffer of 1 KiB

    
    while (fgets( buf, sizeof(buf), file )) {
        printf("%s", buf);
    }

    fclose(file);
    return 0;

}
