#include "Home.h"
#include "ui_Home.h"
#include "account.h"
#include <QFont>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>



Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home),
    newpostWindow(nullptr)
{

    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();


//    QString useid = User::getInstance().getUsername();
//    ui->label_20->setText(useid);
}

Home::~Home()
{
    delete ui;
    if (newpostWindow) {
            delete newpostWindow;
    }
}

void Home::on_pushButton_clicked()
{

    if (!newpostWindow) {
       newpostWindow = new newpost(this);
    }
    newpostWindow->show();
}


void Home::on_pushButton_8_clicked()
{
    QString useid = User::getInstance().getUsername();
    ui->label_20->setText(useid);


    QSqlQuery q;

    if (q.exec("SELECT * FROM Post")) {
            int i = 1;
            q.last();
            while (q.isValid() && i <= 5) {
                QString username = q.value("Sender_ID").toString();
                QString text = q.value("Content_Text").toString();

                if (i == 1){
                    ui->label_6->setText(username);
                    ui->textEdit_2->setText(text);
                }else if (i == 2){
                    ui->label_29->setText(username);
                    ui->textEdit_8->setText(text);
                }


                i++;
                q.previous();
            }
        } else {
//            qDebug() << "Error: " << query.lastError().text();
        }





}

