#include "Me.h"
#include "ui_Me.h"

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
