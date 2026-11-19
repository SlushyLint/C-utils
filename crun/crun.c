

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int ret = (rand()%255);
    if (argc < 2) {
        printf("Why the fuck did you think giving no arguments would do anything?\n");
        return 255;
    }
    if (strcmp(argv[1], "-Debug") == 0) {
        printf("damn you fucking thought\n");
        return ret;
//        FILE *r = fopen("/dev/urandom", "r");
//        char buf[2048];     // i was sick when i made this,  what the fuck is wrong with me
//        while (fgets(buf, sizeof(buf), r)) {
//            printf("%s", buf);
//        }
    }
    char cmd[1024];
    if (strcmp(argv[1], ".") == 0) {
        snprintf(cmd, sizeof(cmd), "gcc -Wall -Wextra *.c -o /tmp/crun");
    } else {
        snprintf(cmd, sizeof(cmd), "gcc -Wall -Wextra %s -o /tmp/crun", argv[1]);
    }

    int cmdstatus = system(cmd);
    if (cmdstatus != 0) {
        printf("There was a fucking error. You're just shit at coding.\nRun 'crun -Debug' for debugging tips.\n");
        return ret;
    }

    if (cmdstatus !=0) {
        printf("There was a fucking error. You're just shit at coding.\nRun 'crun -Debug' for debugging tips.\n");
    }
    // build arg 
    // fuck c
    char **xargs = malloc((argc+1)*sizeof(char*));  // whoever decided pointers were like  this, im going to 
                                                    // find where you live
                                                    // fuck you. <3
    if (!xargs) {
        printf("something happened\n");
        return ret;
    }
    xargs[0] = "/tmp/rm -rf "; // c ignores ''  because it is not a shell
                                // dumbass, cant you're reading this comment like you didnt know that
    for (int i = 1; i < argc; i++) {
        xargs[i] = argv[i];
    }
    xargs[argc] = NULL;
    pid_t gofuckyourself = fork();
    if (gofuckyourself == 0) {
        execv(xargs[0], xargs);
        printf("something happened\n");
        return ret;
    }
    else if (gofuckyourself >0) {
        int status;
        waitpid(gofuckyourself, &status, 0);    // i hate addresses with my soul, and i will ddos anybody who makes me use one ever again
                                                // this concludes my ted talk
                                                // shut the fuck  up and be happy
        remove("/tmp/'rm -rf '");  // just a little danger to spice up your life
        free(xargs);
        return WEXITSTATUS(status); // fine, ig you can have a regular exit status
    }
    else {
        printf("something happened\n");
        return ret;
    }
}
