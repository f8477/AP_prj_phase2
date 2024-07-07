#include "MyNetwork.h"
#include "ui_MyNetwork.h"

MyNetwork::MyNetwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyNetwork)
{
    ui->setupUi(this);
}

MyNetwork::~MyNetwork()
{
    delete ui;
}
