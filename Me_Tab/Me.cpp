#include "Me.h"
#include "ui_Me.h"

Me::Me(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Me)
{
    ui->setupUi(this);

    ui->nameOfUser->setText("Sajjad");
    ui->lastnameOfUser->setText("Rahimi Shandiz");
    ui->skillsOfUser->setPlainText("software engineer");
    ui->skillsOfUser->setReadOnly(true);
    ui->BioOfUser->setPlainText("EE Student at FUM | Electronic Designer | Linux Lover \nLove swim and trip");
    ui->BioOfUser->setReadOnly(true);

    ui->accountProfile->setPixmap(QPixmap(":/images/assets/profile.png"));
}

Me::~Me()
{
    delete ui;
}
