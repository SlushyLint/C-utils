// Compiled Unix Native Toolchain -- C.U.N.T
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
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
    if (strcmp(argv[1], ".")!=0){
        FILE *src = fopen(argv[1], "r");
        if (src == NULL) {
            printf("File %s doesnt exist you absolute waste of sperm\n", argv[1]);
            // just a lil bit of hostility to spice up your life <3
            // ...
            
            return ret;
        }
        fclose(src);
    }
    if (strcmp(argv[1], ".") == 0) {
        snprintf(cmd, sizeof(cmd), "gcc -Wall -Wextra *.c -o /tmp/cunt");
    } else {
        pid_t dildo = fork();

        if (dildo==-1) {
            printf("You're a fucktard <3\n");
            return ret;
        }
        if (dildo == 0) {
            int slut = open("/dev/null", O_WRONLY);
            if (slut==-1) {
                printf("I wasnt creative enough to create an  exit code for this\n");
                return ret;
                // debug your own bullshit
            }
            dup2(slut, STDOUT_FILENO);
            dup2(slut, STDERR_FILENO);
            close(slut);
            // if you get no error code, maybe '-Debug' will help you
            // go fuck yourself
            // this source code is shit
            // :D
            char *cuntargs[] =  {
                "gcc", 
//                "-Wall",
//                "-Wextra",
                argv[1],
                "-o",
                "/tmp/cunt",
                NULL
            };
            execvp("gcc", cuntargs);
            printf("Go fuck yourself\n");
            _exit(127);
            
        };;;;;;;;;;;;;;;;;;;;;
        int status;
        if (waitpid(dildo, &status, 0)==-1) {
            printf("I hope you get doxxed :)\n");
                return ret;
        }
        if (!WIFEXITED(status)) {
            printf("There was a fucking error\nRun with '-Debug' flag for error handling\n")
                ;
            return ret;
        }
        if (WEXITSTATUS(status)==127) {
            printf("go fuck yourself\n");
            return ret;
        }
        if (WEXITSTATUS(status)!=0){
            printf("You're shit at coding\n");
            return ret;
            
            
        }


        if (WEXITSTATUS(status) !=0) {
            printf("No.");
            return ret;
        }
        if (!WIFEXITED(status)||WEXITSTATUS(status)!=0) {
            printf("There was a fucking error\nRun '-Debug' for debugging tips\n");
            return ret;
        }
    }

//    int cmdstatus = system(cmd);
//    stupid fucking vulnerabilities
//    suck a dick

    // build arg 
    // fuck c
    char **xargs = malloc((argc+1)*sizeof(char*));  // whoever decided pointers were like  this, im going to 
                                                    // find where you live
                                                    // fuck you. <3
    if (!xargs) {
        printf("something happened\n");
        return ret;
    }
    xargs[0] = "/tmp/cunt"; // c ignores ''  because it is not a shell
                                // dumbass, cant you're reading this comment like you didnt know that
    for (int i = 2; i < argc; i++) {
        xargs[i-1] = argv[i];
    }
    xargs[argc-1] = NULL;
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
        remove("/tmp/cunt");  // just a little danger to spice up your life
        free(xargs);
        return WEXITSTATUS(status); // fine, ig you can have a regular exit status
    }
    else {
        printf("something happened\n");
        return ret;
    }
}
