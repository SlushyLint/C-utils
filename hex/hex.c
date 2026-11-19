//#include <cstdio>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("you're stupid\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");   // argv[1] contains the first argument, just 
                                        // like  os.Args[1] in Go

                                        // *file now contains some shit
                                        // we now print some shit


                                        //    int n = idigit(argv[2]);
                                        //    do not use isdigit(). it converts one char to a int
                                        //    use atoi

//    printf("%d\n\n", n);

    int n = atoi(argv[2]);
    char buf[1024]; // not int, like i did previously
                    // as it contains a string
    int i = 0 ;
    while (fgets(buf, sizeof(buf), file))  {
        // shut the fuck up, warning, nobody gives a shit
        // it compiles


int c = 0;
for (int j = 0; buf[j] != '\0'; j += n) {

    // Print hex
    for (int k = j; k < j + n && buf[k] != '\0'; k++) {
        printf("%-3.2x", (unsigned char)buf[k]);
        c++;
    }

    for (; c<n;c++) {
        printf("   ");
    }
    printf(" | ");

    // Print text
    for (int k = j; k < j + n && buf[k] != '\0'; k++) {
        if (buf[k]!='\n') {

        printf("%c", buf[k]);
        }
    }

    printf("\n");
}
//            printf("\n\n%d\n\n", i);

    }
    printf("\n\n");
    return 0;

    // lmfao absolutely no error handling
    // hope you used the program correctly

}


