#include "sendpost.h"
#include "ui_sendpost.h"

SendPost::SendPost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendPost)
{
    ui->setupUi(this);
}

SendPost::~SendPost()
{
    delete ui;
}
