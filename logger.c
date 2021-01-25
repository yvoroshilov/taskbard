#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "logger.h"
#include "main.h"

#define LOG_FILE_NAME "taskbard.writeLog"
#define LOG_FILE_PATH "/tmp/"PROGRAM_NAME

FILE* logFile;

void initLogger() {
    logFile = fopen(LOG_FILE_PATH, "w");
}

void writeLog(const char *msg) {
    fputs(formatMsg(msg), logFile);
}

const char* formatMsg(const char *msg) {
    time_t rawTime;
    struct tm* timeInfo;

    time (&rawTime);
    timeInfo = localtime ( &rawTime );

    char* output = malloc(sizeof(char) * 1000);
    sprintf(output, "[%d %d %d %d:%d:%d] %s",
            timeInfo->tm_mday,
            timeInfo->tm_mon + 1,
            timeInfo->tm_year + 1900,
            timeInfo->tm_hour,
            timeInfo->tm_min,
            timeInfo->tm_sec,
            msg);

    return output;
}

void closeLogger() {
    fclose(logFile);
}