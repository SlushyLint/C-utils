#include <stdio.h>
#include <time.h>
#include <string.h>
int main(void) {
    char buf[1024];  // 1 KiB for a buffer
                    // we will reuse this buffer
    FILE *file = fopen("/proc/cpuinfo", "r");
    while (fgets(buf, sizeof(buf), file) != NULL) {
        if (strstr(buf, "MHz") != NULL || strncmp(buf, "model", 5) == 0 ) {
        strtok(buf, ":");
        char *strip = strtok(NULL, "\n");
        printf("%s\n", strip);
        }
    }
    char *line = strtok(buf, "\n");


    fclose(file);
    return 0;

}
