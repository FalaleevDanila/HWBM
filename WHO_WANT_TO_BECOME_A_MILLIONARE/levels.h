#ifndef LEVELS_H
#define LEVELS_H

#include "level.h"
#include <string>

class Levels
{
    std::string task;
public:
    Level level[4];

    void setTask(std::string const &task){
        this->task=task;
    }

    std::string getTask(){
        return task;
    }
};

#endif // LEVELS_H
