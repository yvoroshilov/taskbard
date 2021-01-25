#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include "logger.h"


int main(void) {
    pid_t pid, sid;

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);

    //writeLog
    initLogger();

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);


    int cnt = 0;
    while (1) {
        char number[256];
        sprintf(number, "%ld", cnt);
        const char* f = strcat("Random string: ", number);
        writeLog(f);

        if (cnt++ == 10) {
            break;
        } else {
            sleep(3);
        }
    }
    closeLogger();
    exit(EXIT_SUCCESS);
}

void initLoggers() {
}