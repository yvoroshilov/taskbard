#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#include "main.h"

#define LOG_OUTPUT_SIZE 1000
#define LOG_FILE_NAME "taskbard.log"
#ifndef MINGW_SDK_INIT
    #define LOG_FILE_PATH "/tmp/"LOG_FILE_NAME
#else
    #define LOG_FILE_PATH LOG_FILE_NAME
#endif

FILE* logFile;

void initLogger() {
    logFile = fopen(LOG_FILE_PATH, "at");
}

void writeLog(enum MsgType msgType, const char *msg) {
    char output[LOG_OUTPUT_SIZE] = {};
    formatMsg(output, msg);
    fputs(output, logFile);
    fflush(logFile);
}

void formatMsg(char* output, const char* msg) {
    time_t rawTime;
    struct tm* timeInfo;

    time (&rawTime);
    timeInfo = localtime ( &rawTime );

    char format[LOG_OUTPUT_SIZE] = {}/* = "[%d.%m.%Y %H:%M:%S] "*/;
    sprintf(format, "[%%d.%%m.%%Y %%H:%%M:%%S] %s\n", msg);

    strftime(output, LOG_OUTPUT_SIZE, format, timeInfo);
}

void getMsgFormat(char* format, const char* const msg, enum MsgType msgType) {
    char defaultFormat[] = "[%%d.%%m.%%Y %%H:%%M:%%S] %s\n";
    switch (msgType) {
        case REGULAR: {
            strcpy(format, defaultFormat);
            break;
        }
        case IMPORTANT: {
            long msgLen = (long)strlen(msg);
//            strcat(format, strcat())
            break;
        }
        default: {

        }
    }

}

void closeLogger() {
    fclose(logFile);
}