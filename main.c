#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "logger.h"
#include "main.h"
#include "taskbar.h"

#ifndef MINGW_SDK_INIT
    #include <syslog.h>
#else
    #include "stub.h"
#endif

struct Configuration configuration = {
    .tabModuleName = TAB_MODULE_NAME
};

int main(int argc, char** argv) {
    pid_t pid, sid;
    parseWindowsInfo();
    return 0;

    // pid = fork();
    // if (pid < 0) {
    //     exit(EXIT_FAILURE);
    // }
    // if (pid > 0) {
    //     exit(EXIT_SUCCESS);
    // }
    // umask(0);

    // initLogger();

    // sid = setsid();
    // if (sid < 0) {
    //     exit(EXIT_FAILURE);
    // }

    // if ((chdir("/")) < 0) {
    //     exit(EXIT_FAILURE);
    // }

    // close(STDIN_FILENO);
    // close(STDOUT_FILENO);
    // close(STDERR_FILENO);

    // writeLog(REGULAR, "**********************");
    // writeLog(REGULAR, "*** DAEMON STARTED ***");
    // writeLog(REGULAR, "**********************");

    // configure(argc, argv);
    // int cnt = 0;
    // while (1) {
    //     sleep(3);
    //     break;
    // }

    // writeLog(REGULAR, "***********************");
    // writeLog(REGULAR, "*** DAEMON FINISHED ***");
    // writeLog(REGULAR, "***********************");
    // closeLogger();
    // exit(EXIT_SUCCESS);
}

void configure(int argc, char** argv) {
    configuration.barPid = strtoll(argv[0], NULL, 10);
}
