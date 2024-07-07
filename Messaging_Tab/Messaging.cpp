#include "Messaging.h"
#include "ui_Messaging.h"

Messaging::Messaging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Messaging)
{
    ui->setupUi(this);
}

Messaging::~Messaging()
{
    delete ui;
}
