#ifndef LEVEL3_H
#define LEVEL3_H


#include <QWidget>

#include "attempt.h"

namespace Ui {
class Level3;
}

class Level3: public QWidget
{
    Q_OBJECT
public:
    Level3(QWidget *parent = nullptr);

    Attempt *getInfo() const
    {
        return this->attempt;
    }

    void setInfo(Attempt *attempt);


signals:

    void right();
    void fall();



private slots:
    // Слоты от кнопок главного окна
    void on_first_clicked();
    void on_second_clicked();
    void on_third_clicked();
    void on_fourth_clicked();
    void on_fiftyFifty_clicked();
    void on_friendHelp_clicked();
    void on_x2_clicked();

public slots:

    void check();

private:
    Ui::Level3  *ui;
    Attempt *attempt;

    int ff;
    int sc;
    int td;
    int th;

    bool pressDX;
};


#endif // LEVEL3_H
