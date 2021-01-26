#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "polybar_msg.h"
#include "main.h"

#define POLYBAR_MSG "polybar-msg"
#define COMMAND_LENGTH 1000

static char defaultMsg[COMMAND_LENGTH];

/*
 * hook-1 - show name
 * hook-2 - toggle focus
 */
void showName(int moduleNumber) {
    char cmd[COMMAND_LENGTH];
    getInvokeHookMsg(cmd, moduleNumber, 1);
    system(cmd);
}

void toggleFocus(int moduleNumber) {
    char cmd[COMMAND_LENGTH];
    getInvokeHookMsg(cmd, moduleNumber, 2);
}

char* getDefaultMsg() {
    if (strlen(defaultMsg) == 0) {
        sprintf(defaultMsg, POLYBAR_MSG" -p %lld", configuration.barPid);
    }

    return defaultMsg;
}

void getInvokeHookMsg(char *const msg, int moduleNumber, int hookNumber) {
    sprintf(msg, "%s hook %s%d, %d",
            getDefaultMsg(),
            configuration.tabModuleName,
            moduleNumber,
            hookNumber);
}
