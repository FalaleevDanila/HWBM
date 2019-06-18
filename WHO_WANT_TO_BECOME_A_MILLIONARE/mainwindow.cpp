#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "organize.h"

MainWindow::MainWindow(Attempt *attempt, QWidget *parent) :
    QMainWindow(parent),
    attempt(attempt),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    levelStart = new Level1();
    levelSecond = new Level2();
    finalLevel = new Level3();

    levelStart->setInfo(attempt);
    levelSecond->setInfo(attempt);
    finalLevel->setInfo(attempt);

    connect(levelStart,&Level1::right,levelSecond , &Level2::check);
    connect(levelStart,&Level1::right,levelSecond , &Level2::show);
    connect(levelStart,&Level1::fall, this , &MainWindow::show);
    connect(levelStart,&Level1::fall, this , &MainWindow::endGameLoser);

    connect(levelSecond,&Level2::right,finalLevel , &Level3::check);
    connect(levelSecond,&Level2::right, finalLevel, &Level3::show);
    connect(levelSecond,&Level2::fall, this , &MainWindow::show);
    connect(levelSecond,&Level2::fall, this, &MainWindow::endGameLoser);



    connect(finalLevel, &Level3::right, this, &MainWindow::show);
    connect(finalLevel, &Level3::right, this, &MainWindow::endGameWinner);

    connect(finalLevel,&Level3::fall, this , &MainWindow::show);
    connect(finalLevel, &Level3::fall, this, &MainWindow::endGameLoser);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton chec = QMessageBox::question(this, " Notification "," Are you sure? ",QMessageBox::Yes| QMessageBox::No);
    if(chec==QMessageBox::Yes){
       this->close();
    }
    else {
        this->show();
    }
}
void MainWindow::on_pushButton_play_clicked(){
    attempt->isFifty=true;
    attempt->isDouble=true;
    attempt->isFriendsHelp=true;

    levelStart->setInfo(attempt);
    levelStart->show();
    this->close();
}
