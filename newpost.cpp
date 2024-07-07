#include "newpost.h"
#include "ui_newpost.h"

newpost::newpost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newpost)
{
    ui->setupUi(this);
}

newpost::~newpost()
{
    delete ui;
}
