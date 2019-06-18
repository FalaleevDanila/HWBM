#include "level2.h"
#include "ui_level2.h"
#include <QMessageBox>


// 0 - пусто     1 - ответ     2-блокировка
Level2::Level2(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Level2)

{
    ui->setupUi(this);
    ff=0;
    sc=0;
    td=1;
    th=0;
    pressDX=false;

    ui->x2->setDisabled(!attempt->isDouble);
    ui->fiftyFifty->setDisabled(!attempt->isFifty);
    ui->friendHelp->setDisabled(!attempt->isFriendsHelp);
}

void Level2::on_x2_clicked(){
    if(attempt->isDouble==true){
        pressDX=true;
    }
}

void Level2::on_fiftyFirty_clicked(){
    if(attempt->isFifty==false){
        return;
    }

    int a=2;
    if(ff==0 && a>0){
        a--;
        ff=2;
        ui->first->setDisabled(true);
    }
    if(sc==0 && a>0){
        a--;
        sc=2;
        ui->second->setDisabled(true);
    }
    if(td==0 && a>0){
        a--;
        td=2;
        ui->third->setDisabled(true);
    }
    if(th==0 && a>0){
        a--;
        th=2;
        ui->fourth->setDisabled(true);
    }
    ui->fiftyFifty->setDisabled(true);
    attempt->isFifty=false;
}

void Level2::on_friendHelp_clicked(){
    if(attempt->isFriendsHelp==true){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Друг");
        if(ff==1){
            msgBox.setText("Левый верхний");
            msgBox.exec();

        }
        if(sc==1){
            msgBox.setText("Правый верхний");
            msgBox.exec();

        }
        if(td==1){
            msgBox.setText("Левый нижний");
            msgBox.exec();

        }
        if(th==1){
            msgBox.setText("Правый нижний");
            msgBox.exec();

        }
        ui->friendHelp->setDisabled(true);
        attempt->isFriendsHelp = false;
    }
}

void Level2::on_first_clicked(){
    if(ff<2){
        if(ff==1){
            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
        }
        else{
            emit fall();
            this->close();
        }
    }
}

void Level2::on_second_clicked(){
    if(sc<2){
        if(sc==1){
            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
        }
        else{
            emit fall();
            this->close();
        }
    }
}

void Level2::on_third_clicked(){
    if(td<2){
        if(td==1){
            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
        }
        else{
            emit fall();
            this->close();
        }
    }
}

void Level2::on_fourth_clicked(){
    if(th<2){
        if(th==1){
            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
        }
        else{
            emit fall();
            this->close();
        }
    }
}
