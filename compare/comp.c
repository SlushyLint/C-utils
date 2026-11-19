#include <stdio.h>

int shit() {
    shit();
    shit();
    return 0;
} 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("you're fucking stupid\n");
        while (1) { shit(); }
    }

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");


}


