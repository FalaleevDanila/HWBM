#ifndef LEVEL2_H
#define LEVEL2_H

#include <QWidget>

#include "attempt.h"

namespace Ui {
class Level2;
}

class Level2: public QWidget
{
    Q_OBJECT
public:
    Level2(QWidget *parent = nullptr);

    Attempt *getInfo() const
    {
        return this->attempt;
    }

    void setInfo(Attempt *attempt)
    {
        this->attempt = attempt;
    }


signals:

    void right();
    void fall();



private slots:
    // Слоты от кнопок главного окна
    void on_first_clicked();
    void on_second_clicked();
    void on_third_clicked();
    void on_fourth_clicked();
    void on_fiftyFirty_clicked();
    void on_friendHelp_clicked();
    void on_x2_clicked();

private:

    Ui::Level2  *ui;
    Attempt *attempt;

    int ff;
    int sc;
    int td;
    int th;

    bool pressDX;
};


#endif // LEVEL2_H
