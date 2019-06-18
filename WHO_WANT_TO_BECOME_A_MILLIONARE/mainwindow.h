#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "attempt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Attempt *attempt, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void endGameLoser(){
        attempt->isFifty=true;
        attempt->isDouble=true;
        attempt->isFriendsHelp=true;

        QMessageBox msgBox;
        msgBox.setWindowTitle("Уведомление");

        msgBox.setText("Вы проиграли!");
        msgBox.exec();

    }
    void endGameWinner(){
        attempt->isFifty=true;
        attempt->isDouble=true;
        attempt->isFriendsHelp=true;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Уведомление");
        msgBox.setText("Вы выграли!");
        msgBox.exec();

    }

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_play_clicked();
    void on_pushButton_exit_clicked();

private:
    Attempt *attempt;

    Ui::MainWindow *ui;
    Level1 *levelStart;
    Level2 *levelSecond;
    Level3 *finalLevel;

};

#endif // MAINWINDOW_H
