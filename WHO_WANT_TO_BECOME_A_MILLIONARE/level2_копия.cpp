#include "level2.h"
#include "ui_level2.h"
#include <QMessageBox>


// 0 - пусто     1 - ответ     2-блокировка
Level2::Level2(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Level2)

{
    ui->setupUi(this);
}

void Level2::on_x2_clicked(){
    if(doubleX==true){
        pressDX=true;
    }
}

void Level2::on_fiftyFirty_clicked(){
    int a=2;
    if(ff==0 && a>0){
        a--;
        ff=2;
    }
    if(sc==0 && a>0){
        a--;
        sc=2;
    }
    if(td==0 && a>0){
        a--;
        td=2;
    }
    if(th==0 && a>0){
        a--;
        th=2;
    }
}

void Level2::on_friendHelp_clicked(){
    if(friendH==true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Друг");
        if(ff==1){
            msgBox.setText("Левый верхний");
            msgBox.exec();
            friendH=false;

        }
        if(sc==1){
            msgBox.setText("Правый верхний");
            msgBox.exec();
            friendH=false;

        }
        if(td==1){
            msgBox.setText("Левый нижний");
            msgBox.exec();
            friendH=false;

        }
        if(th==1){
            msgBox.setText("Правый нижний");
            msgBox.exec();
            friendH=false;

        }
    }
}

void Level2::on_first_clicked(){
    if(ff<2){
        if(ff==1){
            emit right();
        }
        else if(pressDX==true){
            doubleX = false;
            pressDX = false;
        }
        else emit fall();
    }
}

void Level2::on_second_clicked(){
    if(sc<2){
        if(sc==1){
            emit right();
        }
        else if(pressDX==true){
            doubleX = false;
            pressDX = false;
        }
        else emit fall();
    }
}

void Level2::on_third_clicked(){
    if(td<2){
        if(td==1){
            emit right();
        }
        else if(pressDX==true){
            doubleX = false;
            pressDX = false;
        }
        else emit fall();
    }
}

void Level2::on_fourth_clicked(){
    if(th<2){
        if(th==1){
            emit right();
        }
        else if(pressDX==true){
            doubleX = false;
            pressDX = false;
        }
        else emit fall();
    }
}
