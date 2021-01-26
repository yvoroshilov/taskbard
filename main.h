#ifndef TASKBARD_MAIN_H
#define TASKBARD_MAIN_H

#define PROGRAM_NAME "taskbard"
#define TAB_MODULE_NAME "tab"

extern struct Configuration {
    long long barPid;
    const char* tabModuleName;
} configuration;

void configure(int argc, char** argv);

#endif //TASKBARD_MAIN_H
