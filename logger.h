#ifndef TASKBARD_LOGGER_H
#define TASKBARD_LOGGER_H

void initLogger();
void writeLog(const char* msg);
const char* formatMsg(const char* msg);
void closeLogger();

#endif //TASKBARD_LOGGER_H
