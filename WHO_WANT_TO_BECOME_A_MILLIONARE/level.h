#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level
{
    bool mainN;
    std::string line;
public:
    void setr(bool const &mainN, std::string const &line){
        this->line=line;
        this->mainN=mainN;
    }
    std::string getLine(){
      return line;
    }
    bool getMainN(){
        return mainN;
    }
};


#endif // LEVEL_H
