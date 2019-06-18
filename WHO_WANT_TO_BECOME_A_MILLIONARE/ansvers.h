#ifndef RANDOMANSVERS_H
#define RANDOMANSVERS_H

#include "levels.h"

#include <vector>

Levels answers(int i){
    Levels level;
    if(i==1){


    level.setTask(" В каком году основали бауманку? ");
    level.level[0].setr(true," 13 июля 1830 г. ");
    level.level[1].setr(false," 11 апреля 2000 г. ");
    level.level[2].setr(false," 1 января 0 г.н.э.");
    level.level[3].setr(false," 15 июня 1850 г. ");

    }

    if(i==2){

    level.setTask(" Лучший технический: ");
    level.level[0].setr(true," Бауманка ");
    level.level[1].setr(false," MIT ");
    level.level[2].setr(false," Станкин ");
    level.level[3].setr(false," Harward ");

    }

    if(i==3){
    level.setTask(" Чьё имя носит МГТУ им. Баумана? ");
    level.level[0].setr(true," Н.Э. Баумана ");
    level.level[1].setr(false," А.С. Пушкина ");
    level.level[2].setr(false," М.В. Ломоносова ");
    level.level[3].setr(false," Т.Т. Джаборича ");
    }
    return level;



}

#endif // RANDOMANSVERS_H
