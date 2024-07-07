#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "newpost.h"



namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Home *ui;
    newpost *newpostWindow;
};

#endif // HOME_H
