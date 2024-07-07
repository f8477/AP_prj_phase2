#include "me.h"
#include "ui_me.h"

Me::Me(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Me)
{
    ui->setupUi(this);
}

Me::~Me()
{
    delete ui;
}
