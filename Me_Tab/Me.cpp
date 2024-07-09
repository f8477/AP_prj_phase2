#include "Me.h"
#include "ui_Me.h"

Me::Me(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Me)
{
    ui->setupUi(this);

    ui->nameOfUser->setText("Fatemeh");
    ui->lastnameOfUser->setText("Arabkhani");
    ui->skillsOfUser->setPlainText("software engineer");
    ui->skillsOfUser->setReadOnly(true);
    ui->BioOfUser->setPlainText("CE Student at FUM | Linux Lover \nLove swim and trip");
    ui->BioOfUser->setReadOnly(true);

    ui->accountProfile->setPixmap(QPixmap(":/images/assets/profile.png"));
    ui->companyImage->setPixmap(QPixmap(":/images/assets/company.png"));
}

Me::~Me()
{
    delete ui;
}


