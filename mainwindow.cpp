#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QPixmap>

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

    const QIcon home_tab(":/images/assets/home.png");
    const QIcon myNetwork_tab(":/images/assets/myNetwork.png");
    const QIcon jobs_tab(":/images/assets/jobs.png");
    const QIcon messaging_tab(":/images/assets/messaging.png");
    const QIcon me_tab(":/images/assets/profile.png");
    const QPixmap Linkedin_logo(":/images/assets/linkedin_logo.png");

    ui->Linkedin_logo->setPixmap(Linkedin_logo);

    ui->search_lineEdit->setPlaceholderText("Search...");

    ui->originTabs->setIconSize(QSize(40, 40));

    ui->originTabs->insertTab(ui->originTabs->count(), new Home(), home_tab, "Home");
    ui->originTabs->insertTab(ui->originTabs->count(), new MyNetwork(), myNetwork_tab, "My Network");
    ui->originTabs->insertTab(ui->originTabs->count(), new Jobs(), jobs_tab, "Jobs");
    ui->originTabs->insertTab(ui->originTabs->count(), new Messaging(), messaging_tab, "Messaging");
    ui->originTabs->insertTab(ui->originTabs->count(), new Me(), me_tab, "Me");
    ui->originTabs->removeTab(1);
    ui->originTabs->removeTab(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

