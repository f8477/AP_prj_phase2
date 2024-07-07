#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Home_Tab/Home.h"
#include "MyNetwork_Tab/MyNetwork.h"
#include "Jobs_Tab/Jobs.h"
#include "Messaging_Tab/Messaging.h"
#include "Me_Tab/Me.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->originTabs->insertTab(ui->originTabs->count(), new Home(), QIcon(QString("")), "Home");
    ui->originTabs->insertTab(ui->originTabs->count(), new MyNetwork(), QIcon(QString("")), "My Network");
    ui->originTabs->insertTab(ui->originTabs->count(), new Jobs(), QIcon(QString("")), "Jobs");
    ui->originTabs->insertTab(ui->originTabs->count(), new Messaging(), QIcon(QString("")), "Messaging");
    ui->originTabs->insertTab(ui->originTabs->count(), new Me(), QIcon(QString("")), "Me");
}

MainWindow::~MainWindow()
{
    delete ui;
}

