#include <stdio.h>
#include <time.h>
#include <string.h>
int main(void) {
    char buf[1024];  // 1 KiB for a buffer
                    // we will reuse this buffer
    FILE *file = fopen("/proc/cpuinfo", "r");
    while (fgets(buf, sizeof(buf), file) != NULL) {
        printf("%s", buf);
    }

    printf("\n\n\n\n%s\n", buf);
    return 0;

}
