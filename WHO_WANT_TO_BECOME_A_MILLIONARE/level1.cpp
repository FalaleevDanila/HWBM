#include "level1.h"
#include "ui_level1.h"
#include <QMessageBox>
//#include <QDebug>


// 0 - пусто     1 - ответ     2-блокировка
Level1::Level1(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Level1)

{
    ui->setupUi(this);
    ff=1;
    sc=0;
    td=0;
    th=0;
    pressDX=false;
}

void Level1::setInfo(Attempt *attempt)
{
    this->attempt = attempt;
    ui->x2->setDisabled(!attempt->isDouble);
    ui->fiftyFifty->setDisabled(!attempt->isFifty);
    ui->friendHelp->setDisabled(!attempt->isFriendsHelp);
}

void Level1::on_x2_clicked(){
    if(attempt->isDouble==true){
        pressDX=true;
        ui->x2->setDisabled(true);
        attempt->isDouble=false;
    }
}

void Level1::on_fiftyFifty_clicked(){
    if(attempt->isFifty==true){


    int a=2;
    if(ff==0 && a>0){
        a--;

        ui->first->setDisabled(true);
    }
    if(sc==0 && a>0){
        a--;

        ui->second->setDisabled(true);
    }
    if(td==0 && a>0){
        a--;

        ui->third->setDisabled(true);
    }
    if(th==0 && a>0){
        a--;

        ui->fourth->setDisabled(true);
    }
    ui->fiftyFifty->setDisabled(true);
    attempt->isFifty=false;
    }
}

void Level1::on_friendHelp_clicked(){
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

void Level1::on_first_clicked(){

        if(ff==1){

            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            emit right();
            this->close();

        }
        else if(pressDX==true){

            pressDX = false;
            ui->first->setDisabled(true);
        }
        else{
            attempt->isFriendsHelp = true;
            attempt->isDouble = true;
            attempt->isFifty = true;

            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            ui->x2->setDisabled(!attempt->isDouble);
            ui->fiftyFifty->setDisabled(!attempt->isFifty);
            ui->friendHelp->setDisabled(!attempt->isFriendsHelp);


            emit fall();
            this->close();
        }


}

void Level1::on_second_clicked(){

        if(sc==1){
            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
            ui->second->setDisabled(true);
        }
        else{
            attempt->isFriendsHelp = true;
            attempt->isDouble = true;
            attempt->isFifty = true;

            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            ui->x2->setDisabled(!attempt->isDouble);
            ui->fiftyFifty->setDisabled(!attempt->isFifty);
            ui->friendHelp->setDisabled(!attempt->isFriendsHelp);

            emit fall();
            this->close();
        }

}

void Level1::on_third_clicked(){

        if(td==1){
            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
            ui->third->setDisabled(true);
        }
        else{

            attempt->isFriendsHelp = true;
            attempt->isDouble = true;
            attempt->isFifty = true;


            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            ui->x2->setDisabled(!attempt->isDouble);
            ui->fiftyFifty->setDisabled(!attempt->isFifty);
            ui->friendHelp->setDisabled(!attempt->isFriendsHelp);

            emit fall();
            this->close();
        }

}

void Level1::on_fourth_clicked(){

        if(th==1){
            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            emit right();
            this->close();
        }
        else if(pressDX==true){

            pressDX = false;
            ui->fourth->setDisabled(true);
        }
        else{

            attempt->isFriendsHelp = true;
            attempt->isDouble = true;
            attempt->isFifty = true;

            ui->first->setDisabled(false);
            ui->second->setDisabled(false);
            ui->third->setDisabled(false);
            ui->fourth->setDisabled(false);

            ui->x2->setDisabled(!attempt->isDouble);
            ui->fiftyFifty->setDisabled(!attempt->isFifty);
            ui->friendHelp->setDisabled(!attempt->isFriendsHelp);

            emit fall();
            this->close();
        }

}
