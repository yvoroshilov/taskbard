#ifndef TASKBARD_LOGGER_H
#define TASKBARD_LOGGER_H

enum MsgType {
    REGULAR,
    IMPORTANT
};

void initLogger();
void writeLog(enum MsgType msgType, const char* msg);
void formatMsg(char* output, const char* msg);
void closeLogger();

#endif //TASKBARD_LOGGER_H
