#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QDialog>
#include "newpost.h"
#include <QMainWindow>
#include <QLineEdit>

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

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_41_clicked();

private:
    Ui::Home *ui;
    newpost *newpostWindow;
};

#endif // HOME_H
