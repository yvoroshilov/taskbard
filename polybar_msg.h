#ifndef TASKBARD_POLYBAR_MSG_H
#define TASKBARD_POLYBAR_MSG_H

void showName(int moduleNumber);
void toggleFocus(int tabNumber);
char* getDefaultMsg();
void getInvokeHookMsg(char* msg, int moduleNumber, int hookNumber);

#endif //TASKBARD_POLYBAR_MSG_H
