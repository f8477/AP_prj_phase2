#include "mynetwork.h"
#include "ui_mynetwork.h"

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
