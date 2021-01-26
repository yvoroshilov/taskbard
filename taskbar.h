#ifndef TASKBARD_TASKBAR_H
#define TASKBARD_TASKBAR_H

#define MAX_TABS 1000

struct WindowDescription {
    const char* wid;
    int desktopNumber;
    const char* resClass;
    const char* machineName;
    const char* title;
};

struct WindowDescriptions {
    struct WindowDescription descriptions[MAX_TABS];
    int size;
};

void displayTabs();
struct WindowDescriptions parseWindowsInfo();

#endif //TASKBARD_TASKBAR_H
