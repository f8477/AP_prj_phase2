#include "Home.h"
#include "ui_Home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home),
    newpostWindow(nullptr)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
    if (newpostWindow) {
            delete newpostWindow;
    }
}

void Home::on_pushButton_clicked()
{
    if (!newpostWindow) {
       newpostWindow = new newpost(this);
    }
    newpostWindow->show();
}

