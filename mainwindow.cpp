#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "home.h"
#include "jobs.h"
#include "mynetwork.h"
#include "messaging.h"
#include "me.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->origin->insertTab(ui->origin->count(), new Home(), QIcon(QString("")), "Home");
    ui->origin->insertTab(ui->origin->count(), new MyNetwork(), QIcon(QString("")), "My Network");
    ui->origin->insertTab(ui->origin->count(), new Jobs(), QIcon(QString("")), "Jobs");
    ui->origin->insertTab(ui->origin->count(), new Messaging(), QIcon(QString("")), "Messaging");
    ui->origin->insertTab(ui->origin->count(), new Me(), QIcon(QString("")), "Me");

    ui->origin->setCurrentIndex(ui->origin->count()-1);  // this line set the default tab when start the project
}

MainWindow::~MainWindow()
{
    delete ui;
}

