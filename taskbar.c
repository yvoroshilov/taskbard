#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taskbar.h"
#include "logger.h"

void displayTabs() {

}

struct WindowDescriptions parseWindowsInfo() {
    FILE* fp = popen("wmctrl -lx", "r");
    if (fp == NULL) {
        writeLog(REGULAR, "Failed to run command wmctrl -lx");
        exit(1);
    }

    char line[1000];
    struct WindowDescriptions windowDescriptions;
    int wNumber = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        const char* token;
        struct WindowDescription winDescription;

        token = strtok(line, " \t\n");
        winDescription.wid = token;

        token = strtok(line, " \t\n");
        winDescription.desktopNumber = (int)strtol(token, NULL, 10);

        token = strtok(line, " \t\n");
        winDescription.resClass = token;

        token = strtok(line, " \t\n");
        winDescription.title = token;

        windowDescriptions.descriptions[wNumber++] = winDescription;
    }

    pclose(fp);
    return windowDescriptions;
}